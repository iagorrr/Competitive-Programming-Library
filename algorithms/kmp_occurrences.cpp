// Original at : https://github.com/edsomjr/TEP/blob/master/Strings/slides/kmp/codes/kmp.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> strong_borders(const string& P)
{
    ll m = P.size(), t = -1;
    vector<ll> bs(m + 1, -1);

    for (ll j = 1; j <= m; ++j){
        while (t > -1 and P[t] != P[j - 1]) t = bs[t];

        ++t;

        bs[j] = (j == m or P[t] != P[j]) ? t : bs[t];
    }

    return bs;
}

ll KMP(const string& S, const string& P){
    ll n = S.size(), m = P.size(), i = 0, j = 0, occ = 0;

    vector<ll> bs = strong_borders(P);

    while (i <= n - m){
        while (j < m and P[j] == S[i + j]) ++j;

        if (j == m) ++occ;

        ll shift = j - bs[j];
        i += shift;
        j = max(0ll, j - shift);
    } 

    return occ;
}

int main(){
    string s;
    string p;
    cin >> s >> p;
    cout << KMP(s, p) << endl;
    return 0;
}