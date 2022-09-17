// iagorrr ;)
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = unsigned long long;
using vll = vector<ll>;
ll hibit(ll x) { return (ll)log2(x) + 1; }

void solve(ll n){
    ll mostleftbit = hibit(n);
    string mainbin = bitset<64>(n).to_string();
    
    // generate every binary that the problem allows.


    vector<ll> ans;
    map<ll, bool> done;
    queue<string> generate;
    generate.push(mainbin);
    done[bitset<64>(mainbin).to_ullong()] = true;
    while(!generate.empty()){
        string current = generate.front();
        generate.pop();

        for(ll i = 0; i < current.size(); ++i){
            if(current[i] == '1'){
                string temp = current;
                temp[i] = '0';
                if(!done[bitset<64>(temp).to_ullong()]){
                    generate.push(temp);
                    done[bitset<64>(temp).to_ullong()] = true;
                }
            }
        }
    }

    for(auto x : done) cout << x.first << '\n';
}


int main(){
    fastio;

    ll n;
    cin >> n;

    solve(n);

    return 0;
}

// Accepted.
