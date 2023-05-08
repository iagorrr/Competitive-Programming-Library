// iagorrr O(1) no dp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector <ll> a{100, 20, 10 , 5, 1};

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll pos = 0;
    while(n > 0){
        while(a[pos] <= n){
            n = n - a[pos];
            ans++;
        }
        pos++;
    }

    cout << ans << endl;
    return 0;
}

// AC