#include <stdio.h>

#define KEYBOARD_OUTPUT_PORT (char *)0x060

void read_port (char *port_num, char *val);
void write_port (char *port_num, char val);

int
main()
{
  char current_char = 0;
  char ascii_char = 's';
  int skip_output = 0;

  while(1)
    {
      skip_output = 0;
      read_port(KEYBOARD_OUTPUT_PORT, &current_char);
      // check if key was released
      if(!(current_char & 0x80))
        {
          switch(current_char)
            {
            case 0x1f:
              ascii_char = 's';
              break;
            case 0x17:
              ascii_char = 'i';
              break;
            case 0x20:
              ascii_char = 'd';
              break;
            case 0x10: // q was pressed
              exit(0);
              break;
            default:
              skip_output = 1;
              break;
            }
          if(!skip_output)
            {
              printf("%c\n", ascii_char);
            }
        }
    }
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
