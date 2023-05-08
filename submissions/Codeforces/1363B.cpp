// iagorr ;)
#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int totalone = 0;
    int totalzero = 0;

    for(auto c : s){
        if(c == '1') totalone++;
        else totalzero++;
    }

    int ans = min(totalone, totalzero);

    int dtotalone = 0;
    int dtotalzero = 0;
    for(int i = 0; i < s.size(); ++i){

        if(s[i] == '1') dtotalone++;
        else dtotalzero++;

        ans = min(ans, dtotalzero+totalone-dtotalone);
        ans = min(ans, dtotalone+totalzero-dtotalzero);
    }
    return ans;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        cout << solve(s) << '\n';
    }
    return 0;
}