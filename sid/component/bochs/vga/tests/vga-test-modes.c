#include <stdio.h>
#define WIDTH 80
/* Note: not the default 25: */
#define HEIGHT 37
#define PAUSE_LENGTH 50000

/* Cathode Ray Tube Controller Index Register */
/* These values are only valid when the vga controller is in color
   emulation mode (which the bochs one is by default) */
#define CRTC_INDEX_PORT (char *)0x03d4
/* Cathode Ray Tube Controller Registers */
#define CRTC_PORT (char *)0x03d5
/* Cathode Ray Tube Controller Maximum Scan Line Register */
#define CRTC_MSL_REG 9
#define CRTC_MSL_MASK 0x1f
/* Cathode Ray Tube Controller Vertical Display End Register */
#define CRTC_VDE_REG 18
/* Cathode Ray Tube Controller Overflow Register */
#define CRTC_OF_REG 7
#define CRTC_OF_VDE_BITS_MASK 0x42
/* Graphics Controller Index Register */
#define GCR_INDEX_PORT (char *)0x03ce
/* Graphics Controller Registers */
#define GCR_PORT (char *)0x03cf
/* Graphics Controller Miscellaneous Register */
#define GCR_MISC_REG 6
#define GCR_MEMORY_MAPPING_MASK 0x0c

void read_port (char *port_num, char *val);
void write_port (char *port_num, char val);

int
main()
{
  unsigned char *vga_mem_mode_3 = (unsigned char *)(0xb8000);
  unsigned char *vga_mem_mode_2 = (unsigned char *)(0xb0000);
  char old_overflow_reg;
  char old_vde_reg;
  char old_msl_reg;
  char old_misc_reg;
  int i;
  char memory_mapping = 3;
  char msl;
  char vde;
  char overflow_reg;

  printf("Changing Video Mode\n");
  write_port(GCR_INDEX_PORT, GCR_MISC_REG);
  read_port(GCR_PORT, &old_misc_reg);

  write_port(GCR_PORT, (old_misc_reg & ~GCR_MEMORY_MAPPING_MASK) | (memory_mapping << 2));

  write_port(CRTC_INDEX_PORT, CRTC_MSL_REG);
  read_port(CRTC_PORT, &old_msl_reg);
  msl = old_msl_reg & CRTC_MSL_MASK;

  vde = (HEIGHT * (msl + 1)) - 1;

  write_port(CRTC_INDEX_PORT, CRTC_VDE_REG);
  read_port(CRTC_PORT, &old_vde_reg);
  write_port(CRTC_PORT, vde & 0xff);

  write_port(CRTC_INDEX_PORT, CRTC_OF_REG);
  read_port(CRTC_PORT, &old_overflow_reg);

  write_port(CRTC_PORT,
             (old_overflow_reg & ~CRTC_OF_VDE_BITS_MASK)
             | (((vde & 0x100) >> 7) | ((vde & 0x200) >> 3))
             );

  printf("Drawing a's...\n");
  for (i=0; i < 80 * HEIGHT * 2; i+=2)
    {
      vga_mem_mode_3[i] = 'a';
      vga_mem_mode_3[i+1] = 15;
    }

  printf("Restoring Video Mode\n");
  write_port(CRTC_PORT, old_overflow_reg);

  write_port(CRTC_INDEX_PORT, CRTC_VDE_REG);
  write_port(CRTC_PORT, old_vde_reg);

  write_port(GCR_INDEX_PORT, GCR_MISC_REG);
  write_port(GCR_PORT, old_misc_reg);

  printf("Drawing z's...\n");
  for (i=0; i < 80 * 25 * 2; i+=2)
    {
      vga_mem_mode_2[i] = 'z';
      vga_mem_mode_2[i+1] = 15;
    }

  while(1);
}

void
read_port (char *port_num, char *val)
{
  *val = *port_num;
}

void
write_port (char *port_num, char val)
{
  *port_num = val;
}

