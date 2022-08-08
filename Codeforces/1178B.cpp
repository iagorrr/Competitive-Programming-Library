// iagorrr ;) 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


ll solve(string s){
    vector <ll> cnt;
    vector <char> charcnt;

    ll i = 0;   
    ll n = s.size();
    while(i < n){
        char c = s[i];
        ll j = 0;
        while(j+i < n && s[i+j] == c){j++;};

        if(c == 'o'){cnt.push_back(j); charcnt.push_back('o');}
        if(c == 'v' && j > 1){cnt.push_back(j-1); charcnt.push_back('w');}
        i += j;
    }

    // for(int i = 0; i < cnt.size(); ++i) cout << cnt[i] << " ";
    // cout << endl;
    // for(int i = 0; i < cnt.size(); ++i) cout << charcnt[i] << " ";
    // cout << endl;

    // every 'o' must be combined with every 'w' that comes before.
    // every 'w' can close all the 'p' possibilities before it.
    ll ans = 0;
    ll tw = 0;
    ll p = 0;
    for(i = 0; i < cnt.size(); ++i){
        if(charcnt[i] == 'w'){
            ans += p*cnt[i];
            tw += cnt[i];
        }
        else{
            p += (cnt[i] * tw);
        }
    }

    return ans;
}

int main(){
    fast
    string s;
    cin >> s;

    cout << solve(s) << endl;
    return 0;
}

// AC.
