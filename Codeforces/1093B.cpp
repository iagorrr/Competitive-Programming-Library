// iagorrr ;) O(NlogN)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// A string sorted will never be a palindrome, if the elements are different.
string solve(string s){
    int t = 0;
    map <char,bool> m;
    for(auto it = s.begin(); it != s.end(); ++it){
        if(!m[*it]) ++t;
        m[*it] = true;
    }
    if(t == 1) return "-1";

    sort(s.begin(), s.end());
    return s;
}

int main(){
    fast
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}

// Accepted.