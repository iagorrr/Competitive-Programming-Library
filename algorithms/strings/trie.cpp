struct trie {
  vi2d to;
  vi end, pref;
  int sigma;
  char norm;

  trie(int sigma_ = 26, char norm_ = 'a')
    : sigma(sigma_), norm(norm_) {
    to = {vector<int>(sigma)};
    end = {0}, pref = {0};
  }

  int next(int node, char key) {
    return to[node][key - norm];
  }

  void insert(const string &s) {
    int x = 0;
    for (auto c : s) {
      int &nxt = to[x][c - norm];
      if (!nxt) {
        nxt = len(to);
        to.push_back(vi(sigma));
        end.emplace_back(0), pref.emplace_back(0);
      }
      x = nxt, pref[x]++;
    }
    end[x]++, pref[0]++;
  }
  void erase(const string &s) {
    int x = 0;
    for (char c : s) {
      int &nxt = to[x][c - norm];
      x = nxt, pref[x]--;
      if (!pref[x]) nxt = 0;
    }
    end[x]--, pref[0]--;
  }
  int find(const string &s) {
    int x = 0;
    for (auto c : s) {
      x = to[x][c - norm];
      if (!x) return 0;
    }
    return x;
  }
};
