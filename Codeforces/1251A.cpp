// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(string s){

    ll i = 0;
    string ans;
    map<char, bool> m;
    char c;
    while(i < s.size()){
        c = s[i];
        ll t = 0;
        while(s[i] == c && i < s.size()){
            t++;
            i++;
        }
        if(t&1 && !m[c]){ ans.push_back(c); m[c] = true;}

    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    ll T;

    cin >> T;
    while(T--){
        string s;

        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}

// AC