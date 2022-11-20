// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a, b;
    cin >> a >> b;

    ll ans = (((a+1)/2) * ((b+1)/2)) + ((a/2) * (b/2));

    cout << ans << '\n';
    return 0;
}
