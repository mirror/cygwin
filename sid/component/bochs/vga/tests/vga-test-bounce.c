#define WIDTH 80
#define HEIGHT 25
#define PAUSE_LENGTH 600

int
main()
{
    unsigned char *vga_mem = (unsigned char *)(0xb0000);
    int x = 0, y = 0, xinc = 1,  yinc = 1;
    int last1 = 0, last2 = 0;
    int pause = 0;

    vga_mem[last1] = 'H';
    vga_mem[last2] = 0;

    vga_mem[2 * x + 2 * y * WIDTH] = 'H';
    vga_mem[2 * x + 2 * y * WIDTH + 1] = 15;

    while (1)
    {
      last1 = 2 * x + 2 * y * WIDTH;
      last2 = 2 * x + 2 * y * WIDTH + 1;

      vga_mem[last1] = 'H';
      vga_mem[last2] = 0;

      x += xinc;
      y += yinc;
      
      if (x == WIDTH - 1)
        xinc = -1;
      
      if (x == 0)
        xinc = 1;
      
      if (y == HEIGHT - 1)
        yinc = -1;
      
      if (y == 0)
        yinc = 1;

      vga_mem[2 * x + 2 * y * WIDTH] = 'H';
      vga_mem[2 * x + 2 * y * WIDTH + 1] = 15;

      for(pause=0; pause< PAUSE_LENGTH; pause++);
    }
}        
