// iagorrr
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(string s, string t){
    if(t == "a") return 1;

    ll tat = 0;
    ll tas = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a') tas++;
    }

    for(int i = 0; i < t.size(); i++){
        if(t[i] == 'a') tat++;
    }

    if(tat >= 1) return -1;


    return (1ll<<tas);
}

int main(){
    ll T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        string t;
        cin >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}

// AC
