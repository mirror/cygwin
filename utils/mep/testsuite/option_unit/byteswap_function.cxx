SI
byteswap (SI x)
{
  return (  ((x >> 24) & 0x000000ff) 
	  | ((x >> 8)  & 0x0000ff00)
	  | ((x << 8)  & 0x00ff0000)
          | ((x << 24) & 0xff000000));
}
