#include <stdio.h>
#define WIDTH 80
#define HEIGHT 25
#define PAUSE_LENGTH 50000

#define PEL_ADDRESS_WRITE_MODE (char *)0x03c8
#define PEL_DATA_REGISTER (char *)0x03c9

void read_port (char *port_num, char *val);
void write_port (char *port_num, char val);

int
main()
{
  unsigned char *vga_mem = (unsigned char *)(0xb0000);
  int i;

  write_port(PEL_ADDRESS_WRITE_MODE, 0);

  /* Black */
  write_port(PEL_DATA_REGISTER, 0x00);
  write_port(PEL_DATA_REGISTER, 0x00);
  write_port(PEL_DATA_REGISTER, 0x00);

  /* Red */
  write_port(PEL_DATA_REGISTER, 0x33);
  write_port(PEL_DATA_REGISTER, 0xff);
  write_port(PEL_DATA_REGISTER, 0x22);

  /* Green */
  write_port(PEL_DATA_REGISTER, 0x00);
  write_port(PEL_DATA_REGISTER, 0xff);
  write_port(PEL_DATA_REGISTER, 0x00);
  
  /* Blue */
  write_port(PEL_DATA_REGISTER, 0x00);
  write_port(PEL_DATA_REGISTER, 0x00);
  write_port(PEL_DATA_REGISTER, 0xff);

  /* White */
  write_port(PEL_DATA_REGISTER, 0x33);
  write_port(PEL_DATA_REGISTER, 0xff);
  write_port(PEL_DATA_REGISTER, 0x00);

  printf("Drawing (0x33, 0xff, 0x22) a's...\n");
  for (i=0; i < 80 * HEIGHT * 2; i+=2)
    {
      vga_mem[i] = 'a';
      vga_mem[i+1] = 1;
    }

  printf("Pausing...\n");
  for(i = 0; i < PAUSE_LENGTH; i++);

  printf("Drawing Blue z's...\n");
  for (i=0; i < 80 * 25 * 2; i+=2)
    {
      vga_mem[i] = 'z';
      vga_mem[i+1] = 3;
    }

  printf("Pausing...\n");
  for(i = 0; i < PAUSE_LENGTH; i++);

  printf("Drawing Green H's...\n");
  for (i=0; i < 80 * 25 * 2; i+=2)
    {
      vga_mem[i] = 'H';
      vga_mem[i+1] = 2;
    }

  printf("Pausing...\n");
  for(i = 0; i < PAUSE_LENGTH; i++);

  printf("Drawing (0x88, 0xff, 0x88) g's...\n");
  for (i=0; i < 80 * 25 * 2; i+=2)
    {
      vga_mem[i] = 'g';
      vga_mem[i+1] = 4;
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

