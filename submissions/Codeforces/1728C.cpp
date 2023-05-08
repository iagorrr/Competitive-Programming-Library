// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n;
ll fx(ll x){
    ll cont =0;
    while(x > 0){
        x = x/10;
        cont++;
    }

    return cont;
}

ll solve(priority_queue<ll> a, priority_queue<ll> b){
    ll op = 0;
    while(!a.empty() and !b.empty()){
        if(a.top() == b.top()) a.pop(), b.pop();
        else if(a.top() > b.top()){
            ll x = a.top();
            a.pop();
            a.push(fx(x));
            op++;
        }
        else{
            ll x = b.top();
            b.pop();
            b.push(fx(x));
            op++;
        }
    }

    return op;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while(t--){
        cin >> n;

        priority_queue<ll> at;
        for(ll i = 0; i < n; ++i){
            ll x;
            cin >> x;
            at.push(x);
        }

        priority_queue <ll> bt;
        for(ll i = 0; i < n; ++i){
            ll x;
            cin >> x;
            bt.push(x);
        }

        cout << solve(at, bt) << endl;
    }
    return 0;
}

// Accepted.
