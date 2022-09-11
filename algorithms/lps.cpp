/*
    Longest Palindrome Subsequence
        dynamic programming inplementation, based in the longest common subsequence.


        B A N A N A
          1 2 3 4 5

        1 2 3 4 5
        A N A N A B
*/
#include <bits/stdc++.h>
using namespace std;
int lps_dp[10001][10001];

int lps(const string &s1, const string &s2, int p1, int p2){
    if (p1 == 0 || p2 == 0) return 0;

    if(lps_dp[p1][p2] != -1) return lps_dp[p1][p2];

    if(s1[p1-1] != s2[p2-1]) return lps_dp[p1][p2] = max(lps(s1, s2, p1-1, p2), lps(s1, s2, p1, p2 -1));
    else return lps_dp[p1][p2] = lps(s1, s2, p1-1, p2-1) + 1;
}
int main(){
    memset(lps_dp, -1, sizeof(lps_dp));

    string a = "banana";
    string b = a;
    reverse(b.begin(), b.end());

    cout << lps(a, b, (int)a.size(), (int)b.size()) << endl;

    return 0;
}