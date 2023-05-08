// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

map<string, string> slogans;
int main(){ 
    fastio
    int n;
    cin >> n;
    
    cin.ignore();
    while(n--){
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        slogans[s1] = s2;
    }

    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        cout << slogans[s] << '\n';
    }
    return 0;
}

// AC.
