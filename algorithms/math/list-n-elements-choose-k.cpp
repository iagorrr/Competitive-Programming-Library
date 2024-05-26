void process(vi &index) {
  for (int i = 0; i < len(index); i++) {
    if (index[i]) cout << i << " \n"[i == len(index) - 1];
  }
}

void n_choose_k(int n, in k) {
  vi index(n);
  fill(index.end() - k, index.end(), 1);

  do {
    process(index);
  } while (next_permutation(all(index)));
}
