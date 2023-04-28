// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ull = long long;

vector<ull> facts(1e5+10, -1);
const ull MOD = 1000000007;
ull ft(ull k) {
    if(facts[k] != -1) return facts[k];
    facts[k] = (ft(k-1)*k)%MOD;
    return facts[k];
}

ull aescb(ull a, ull b) { // a esoclhe b.
    ull ans = (ft(a) / (ft(a-b) * ft(b))) % MOD;
    //cout << ft(a) << " / " << ft(a-b) << " * " << ft(b) <<  " = " << ans << '\n';
    return ans;
}
int main() {
    facts[0] = 1;
    facts[1] = 1;
    int t;
    cin >> t;

    while(t--) {
        ull A, B, C, c, K;
        cin >> A >> B >> C >> K >> c;
        ull V = K-c; // quero escolehr
        ull v = A+B; // quantas posso escolher
        // cout << "mats\n";
        ull mats = aescb(C, c);
        if(V > v or K < 3) {
            cout << 0 << '\n';
            continue;
        }
        ull onlya = 0;
        if(A > V) onlya = aescb(A, V);

        ull onlyb = 0;
        if(B > V) onlyb = aescb(B, V);

        // ull others = ft(V) / ft(V-v) * ft(v);
        ull others = aescb(v, V);
        //cout << "onlyb: " << onlyb << '\n';
        //cout << "onlya: " << onlya << '\n';
        //cout << "others: " << others << '\n';
        //cout << "mats: " << mats << '\n';
        ull ans = ((others-onlya-onlyb)*mats) % MOD;

        cout << ans << '\n';
    }
}

// WA on test 2.
