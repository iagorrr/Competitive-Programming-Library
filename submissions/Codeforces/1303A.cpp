// iagorr ;) O(N)
#include <bits/stdc++.h>

using namespace std;

int solve(string S) {
  vector<pair<char, int>> ans;
  int s = 1;
  int count = 1;
  char current = S[0];
  while (s < S.size()) {

    if (current != S[s]) {
      ans.push_back({current, count});
      count = 0;
      current = S[s];
    }
    count++;
    s++;
  }

  if (current == S[s - 1]) {
    ans.push_back({current, count});
  }

  // for(int i = 0; i < ans.size(); i++){
  //     cout << ans[i].first << " " << ans[i].second << endl;
  // }

  int finalAns = 0;
  for (int i = 1; i < ans.size() - 1; i++) {
    if (ans[i].first == '0' && ans[i - 1].first == '1' &&
        ans[i + 1].first == '1')
      finalAns += ans[i].second;
  }
  return finalAns;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    // cout << endl << endl << endl;

    int ans = solve(S);
    cout << ans << endl;
  }
  return 0;
}

// Accepted.
