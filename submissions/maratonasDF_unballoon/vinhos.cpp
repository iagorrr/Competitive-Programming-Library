// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll n;

    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(n--){
        char op;
        cin >> op;
        if(op == '+'){
            ll x;
            cin >> x;

            pq.push(x);
        }
        else {
            if(pq.empty())
                cout << -1 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}
