void combinations_with_repetition(int n, int k,
                                  function<void(const vector<int> &)> process) {
        vector<int> v(k, 1);
        int pos = k - 1;

        while (true) {
                process(v);

                v[pos]++;

                while (pos > 0 and v[pos] > n) {
                        --pos;
                        v[pos]++;
                }

                if (pos == 0 and v[pos] > n) break;

                for (int i = pos + 1; i < k; ++i) v[i] = v[pos];

                pos = k - 1;
        }
}
