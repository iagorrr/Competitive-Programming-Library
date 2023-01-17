// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
#define all(x) x.begin(), x.end()
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;

    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    string t; cin >> t;

    map<char, vector<ll>> pos;
    set<char> hist;
    for(int i = 0; i < n;  ++i)
    {
        hist.insert(s[i]);
        pos[s[i]].push_back(i);
    }

    ll c = 0;
    ll tk = 1;
    for(int i = 0; i < m; ++i)
    {
        if(not hist.count(t[i]))
        {
            cout << "S\n";
            exit(0);
        }
        // primeira posição que o char t[i] aparece depois de c.
        auto p = lower_bound(all(pos[t[i]]), c);
        if(p == pos[t[i]].end())
        {
            tk++;
            c = pos[t[i]].front();
        }
        else
            c  = *p;

        if(tk > k)
        {
            cout << "S\n";
            exit(0);
        }
    }

    cout << "N\n";
    return 0;
}
