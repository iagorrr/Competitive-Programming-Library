// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<long long>;

void solve(vector <string> p1, vector <string> p2, vector<string> p3){
    map<string, ll> total;

    for(auto s : p1) total[s]++;
    for(auto s : p2) total[s]++;
    for(auto s : p3) total[s]++;

    ll ans1 = 0, ans2 = 0, ans3 = 0;
    for(auto s : p1){
        if(total[s] == 1) ans1 += 3;
        if(total[s] == 2) ans1 += 1;
    }

    for(auto s : p2){
        if(total[s] == 1) ans2 += 3;
        if(total[s] == 2) ans2 += 1;
    }

    for(auto s : p3){
        if(total[s] == 1) ans3 += 3;
        if(total[s] == 2) ans3 += 1;
    }

    cout << ans1 << " " << ans2 << " " << ans3 << endl;
}
int main(){
    fast
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <string> p1;
        vector <string> p2;
        vector <string> p3;

        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            p1.push_back(s);
        }

        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            p2.push_back(s);
        }

        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            p3.push_back(s);
        }

        solve(p1, p2, p3);
    }   

    return 0;
}