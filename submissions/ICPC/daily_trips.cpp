#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL):
#define all(x) x.begin(), x.end()

void solve(){
    ll n, h, w;
    cin >> n >> h >> w;

    for(int i = 0; i < n; ++i){
        char a, b;
        cin >> a >> b;

        char c='N', d='N';
        if(a == 'Y') {
            h--;
            w++;
            c = 'Y';
        }
        else if(a == 'N' and w == 0) {
            h--;
            w++;
            c  = 'Y';
        }

        if(b == 'Y') {
            w--;
            h++;
            d = 'Y';
        }
        else if(b == 'N' and h == 0) {
            w--;
            h++;
            d  = 'Y';
        }
        cout << c << ' ' << d << '\n';
        
    }    
}
int main() {
    int t; t=1;
    // cin >> t;

    for(int i = 0; i < t; ++i) {
        solve();
    }
}

// AC, implementation.

