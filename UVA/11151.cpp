// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

unsigned int dp[1000+10][1000+10];

unsigned int lps(const string &s1, const string &s2, unsigned int p1, unsigned int p2){
    if(p1 == 0 || p2 == 0) return 0;

    if(dp[p1][p2] != (unsigned int)-1) return dp[p1][p2];

    if(s1[p1-1] != s2[p2-1]) return dp[p1][p2] = max(lps(s1, s2, p1-1, p2), lps(s1, s2, p1, p2-1));
    else return dp[p1][p2] = lps(s1, s2, p1-1, p2-1)+1;
}
int main(){ 
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;cin.ignore();

    while(t--){
        string s;
        getline(cin, s);
        string sr = s;
        reverse(sr. begin(), sr.end());
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < (int)s.size(); ++i){
            for(int j = 0; j < (int)sr.size(); ++j){
                if(s[i] == sr[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        cout << dp[(int)s.size()][(int)sr.size()] << '\n';

    }
    return 0;
}