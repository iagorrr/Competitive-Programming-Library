// iagorrr ;) O(N)
#include <bits/stdc++.h>

using namespace std;

string solve(string t) {
  int N = t.size();

  // exceptions.
  if (N == 1)
    return t;
  int count = 1;
  while (count < N) {
    if (t[count] == t[count - 1])
      count++;
    else
      break;
  }
  if (count == N)
    return t;

  string ans;
  for (int i = 0; i < N; ++i) {
    if (t[i] == '1') {
      ans.push_back('1');
      if (i + 1 < N && t[i + 1] != '0')
        ans.push_back('0');
    } else {
      ans.push_back('0');
      if (i + 1 < N && t[i + 1] != '1')
        ans.push_back('1');
    }
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;

    cout << solve(t) << endl;
  }
}

// Accepted.
