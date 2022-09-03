// iagorrr O(N)
#include <bits/stdc++.h>
using namespace std;

string solve(string s, int n){

    string ans;
    ans.push_back(s[0]);
    int i = 1;
    while(i < n) {
        if(s[i] == s[i-1] && i == 1)break;
        else if(s[i] > s[i-1]) break;
        ans.push_back(s[i]);
        i++;
    }
    string rans = ans;
    reverse(rans.begin(), rans.end());

    return ans+rans;
}
int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        int n;

        cin >> n;
        cin >> s;

        cout << solve(s, n) << endl;
    }
}

// Accepted.