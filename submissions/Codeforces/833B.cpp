// iagorrr ;)
#include <bits/stdc++.h>
#define sws ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
using pii = pair<int,int>;

inline int solve(const string &s, const int &n){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        map<char, bool> view;
        map<char, int> tot;
        int dist = 0;
        int max_q= -1;
        for(int j = 0; j+i < n; ++j){
            if(!view[s[j+i]]) dist++;

            tot[s[i+j]]++;
            if(tot[s[i+j]] > 10) break;
            max_q = max(max_q, tot[s[i+j]]);

            if(max_q <= dist)
                ans++;

            view[s[i+j]]  = true;
        }
    }

    return ans;
}
int32_t main(){
    sws
    int t;
    cin >> t;

    int n;
    string s;
    while(t--){
        cin >> n;

        cin >> s;

        cout << solve(s, n) << '\n';
    }
    return 0;
}
// AC
