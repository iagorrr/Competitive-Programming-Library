// Caua
#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define maxMerge 100
void merge(int *v, int begin, int mid, int end) {
  int aux[end - begin + 1];
  int iaux = 0;

  int i = begin;
  int j = mid + 1;

  while (i <= mid && j <= end && iaux < maxMerge) {
    if (less(v[j], v[i])) {
      aux[iaux++] = v[j++];
    } else {
      aux[iaux++] = v[i++];
    }
  }

  while (i <= mid && iaux < maxMerge) {
    aux[iaux++] = v[i++];
  }

  while (j <= end && iaux < maxMerge) {
    aux[iaux++] = v[j++];
  }

  for (int i = 0; i < iaux; i++) {
    v[begin++] = aux[i];
  }
}

void mergeSort(int *v, int begin, int end) {
  if (begin >= end) {
    return;
  }

  int mid = (begin + end) / 2;
  mergeSort(v, begin, mid);
  mergeSort(v, mid + 1, end);
  merge(v, begin, mid, end);
}

int main() {
  int n, k;
  int placas[(int)1e6 + (int)6.66];
  int len = 0;

  int lastOrderedLen = 0;
  while (scanf("%d %d", &n, &k) == 2) {
    if (n == 1) {
      if (lastOrderedLen >= maxMerge && k >= placas[lastOrderedLen - 1]) {
        continue;
      }
      placas[len++] = k;
    } else {
      if (len > lastOrderedLen) {
        mergeSort(placas, lastOrderedLen, len - 1);
        merge(placas, 0, lastOrderedLen - 1, len - 1);
        if (len > maxMerge) {
          len = maxMerge;
        }
        lastOrderedLen = len;
      }

      printf("%i", placas[0]);
      for (int i = 1; i < k; i++) {
        printf(" %i", placas[i]);
      }
      printf("\n");
    }
  }
}
// AC
