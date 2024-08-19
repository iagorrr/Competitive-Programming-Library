/*8<
  @Title: List N elements choose K
  @Description:
    Process every possible combination of $K$
    elements from $N$ elements, thoose index
    marked as $1$ in the index vector says which
    elments are choosed at that moment.
  @Time:$O(\binom{N}{K} \cdot O(process))$
>8*/
void process(vi &index) {
  for (int i = 0; i < len(index); i++) {
    if (index[i])
      cout << i << " \n"[i == len(index) - 1];
  }
}

void n_choose_k(int n, in k) {
  vi index(n);
  fill(index.end() - k, index.end(), 1);

  do {
    process(index);
  } while (next_permutation(all(index)));
}
