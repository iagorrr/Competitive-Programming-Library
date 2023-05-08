// iagorrr ;) & Cauã
#include <stdio.h>
#define Item

int nexts[5001];
int values[5001] = {[0 ... 5000] = -1};

int main() {
  int n;
  scanf("%d", &n);

  int actual;
  int identifier, value, next;
  scanf("%d %d %d", &actual, &value, &next);
  nexts[actual] = next;
  values[actual] = value;

  while (--n) {
    scanf("%d %d %d", &identifier, &value, &next);
    nexts[identifier] = next;
    values[identifier] = value;
  }

  while (actual != -1) {
    printf("%d\n", values[actual]);
    actual = nexts[actual];
  }
}

// AC.
