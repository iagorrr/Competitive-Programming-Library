// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    // fastio
    int t;
    cin >> t;

    while(t--){
        string b;
        cin.ignore();
        getline(cin, b);
        ll m, n, c;
        cin >> m >> n >> c;
        
        map<string, ll> ip;
        while(m--){
            string pn;
            ll pp;
            cin >> pn >> pp;
            ip[pn] = pp;
        }
        
        vector<pair<ll, string>> ans;
        while(n--){ 
            cin.ignore();
            string r;
            getline(cin, r);

            ll ti;
            cin >> ti;

            ll finalprice=0;
            while(ti--){
                string i;
                ll q;
                cin >> i >> q;
                finalprice += ip[i]*q;
            }
            if(finalprice <= c) ans.emplace_back(finalprice, r);
        }

        for(auto &x : b)
            x = (char) toupper(x);
        cout << b << '\n';
        if(ans.empty()){
            cout << "Too expensive!\n\n";
            continue;
        }

        sort(ans.begin(), ans.end());
        for(auto [p, r] : ans)
            cout << r << '\n';

        cout << '\n';
    }
    return 0;
}

// AC.
