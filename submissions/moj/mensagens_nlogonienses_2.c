/*
 * iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char *ans = calloc((1 << 22), sizeof(char)), c;
  unsigned int id, fid, min = (1 << 20);
  scanf("%u %c", &fid, &c);
  ans[(1 << 20)] = c;
  while (scanf("%u %c", &id, &c) != EOF)
  {
    ans[(1 << 20) - (fid - id)] = c;
    min = (min < ((1 << 20) - (fid - id))) ? min : (1 << 20) - (fid - id);
  }

  printf("%s\n", &ans[min]);
}

// AC, malandragem