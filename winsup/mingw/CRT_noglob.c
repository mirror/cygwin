/*
 * noglob.c
 *
 * This file defines _CRT_glob to have a value of 0, which will
 * turn off command line globbing. It is compiled into a separate object
 * file which you can add to your link line to turn off globbing like
 * this:
 *
 * gcc -o foo.exe foo.o noglob.o
 *
 * $Revision: 1.4 $
 * $Author: cgf $
 * $Date: 2000/02/05 04:04:38 $
 *
 */

int _CRT_glob = 0;
