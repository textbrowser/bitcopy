/*
** Copyright (c) 2015, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from bitcopy without specific prior written permission.
**
** BITCOPY IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** BITCOPY, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void bitcopy(void *dst, const void *src,
	     const size_t bits[], const size_t length);

void bitcopy(void *dst, const void *src,
	     const size_t bits[], const size_t length)
{
  char *d = dst;
  const char *s = src;

  for(size_t i = 0; i < length; i++)
    {
      size_t bit = bits[i] % 8;
      size_t idx = bits[i] >> 3; // Divide by eight.

      if(((1 << bit) & s[idx])) // Is the bit set?
	d[idx] |= (char) (1 << bit); // Set the bit.
      else
	d[idx] &= (char) (~(1 << bit)); // Clear the bit.
    }
}

int main(void)
{
  char a[] = "Pleaze see the doctox!";
  char b[] = "Please see the doctor!";
  int32_t x = 101;
  int32_t y = 202;
  size_t bits_ab[] = {8 * 4,
		      8 * 4 + 1,
		      8 * 4 + 2,
		      8 * 4 + 3,
		      8 * 4 + 4,
		      8 * 4 + 5,
		      8 * 4 + 6,
		      8 * 4 + 7,
		      8 * 20,
		      8 * 20 + 1,
		      8 * 20 + 2,
		      8 * 20 + 3,
		      8 * 20 + 4,
		      8 * 20 + 5,
		      8 * 20 + 6,
		      8 * 20 + 7};
  size_t bits_xy[] = {0, 1, 2, 3, 4, 5, 6, 7,
	 	      8 * 3,
		      8 * 3 + 1,
		      8 * 3 + 2,
		      8 * 3 + 3,
		      8 * 3 + 4,
		      8 * 3 + 5,
		      8 * 3 + 6,
		      8 * 3 + 7};

  printf("a = %s, b = %s.\n", a, b);
  bitcopy(a, b, bits_ab, sizeof(bits_ab) / sizeof(size_t));
  printf("a = %s, b = %s.\n", a, b);
  printf("x = %d, y = %d.\n", x, y);
  bitcopy(&x, &y, bits_xy, sizeof(bits_xy) / sizeof(size_t));
  printf("x = %d, y = %d.\n", x, y);
  return EXIT_SUCCESS;
}
