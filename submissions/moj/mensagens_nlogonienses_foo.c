/*
 * iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  // insert only once.
  const unsigned int maxzap = 1ull << 31;
  char *ans = calloc(maxzap + 1, sizeof(char));
  unsigned int id;
  char c;
  unsigned f = 0;
  unsigned s = 0;
  while (scanf("%u %c", &id, &c) != EOF)
  {
    ans[id] = c;
    s = id < s ? id : s;
    f = id > f ? id : 
  }

  for (unsigned int i = 0; i <= maxzap; ++i)
  {
    if (ans[i])
      printf("%c", ans[i]);
  }
  printf("\n");
}