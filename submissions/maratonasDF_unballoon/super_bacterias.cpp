// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
void solve(vll r, vll b, ll n)
{
    vll cperm(n);
    iota(cperm.begin(), cperm.end(), 0);

    ll best = LLONG_MAX;
    vll best_perm;

    ll initial = 0;
    for(auto x : b) initial += x;
    do
    {
        ll total = initial;
        vll c(n);
        for(int i = 0; i < n; ++i) c[i] = b[i];

        for(int i = 0; i < n; ++i){
            ll current = 0;
            c[cperm[i]] = 0;

            for(int i = 0; i < n; ++i){
                c[i] *= r[i];
                current += c[i];
            }

            total += current;
        }

        if(total < best){
            best = total;
            best_perm = cperm;
        }
    
    }while(next_permutation(cperm.begin(), cperm.end()));

    cout << "Anti-" << best_perm[0]+1;
    for(int i = 1;  i < n; ++i){
        cout << " -> Anti-" << best_perm[i]+1;
    }
    cout << "\n\n";
}

int main(){ 
    fastio;
    ll t; cin >> t;

    for(int i = 1; i <= t; ++i){ cout << "Paciente #" << i << ":\n";

        ll n; cin >> n;

        vector<ll> r(n); for(auto &x : r) cin >> x;
        vector<ll> b(n); for(auto &x: b) cin >> x;

        solve(r, b, n);
    }
    return 0;
}

// AC.
