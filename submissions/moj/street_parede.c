// Cauã & iagorrr ;)
#include <stdio.h>

int stack[(int)1e5];

int main() {
  int n;
  int tmp;
  int car;

  while (scanf("%d", &n) == 1 && n != 0) {
    int sp = -1;
    int count = 1;

    for (int i = 0; i < n; i++) {
      scanf("%d", &car);
      if (car == count) {
        count++;
        while (sp >= 0 && stack[sp] == count) {
          sp--;
          count++;
        }
      } else {
        stack[++sp] = car;
      }
    }

    if (n + 1 == count) {
      puts("yes");
    } else {
      puts("no");
    }
  }

  return 0;
}

// AC
