// iagorrr ;)
#include <stdio.h>

int main(void) {
  int n; scanf("%d", &n);

  scanf("%*c");
  while(n--) {
    char s[100+1]; scanf("%s", s);

    char *c = &s[0];

    int a = 0;
    while(*c) {
      if(*c >= '1' && *c <= '9') a += *c-'0';
      ++c;
    }
    printf("%d\n", a);
  }

}

// AC, strings.
