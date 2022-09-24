#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

int main(){
  ll t;
  cin >> t;
  ll casei = 0;
  while(t--){
    ll n;
    cin >> n;

    vector<pair<string, ll>> ada; // color id.
    vector<pair<ll, ll>> charles; // durability id.

    for(ll i = 0; i < n; ++i){
        string color;
        ll durability;
        ll id;
        cin >> color >> durability >> id;

        ada.push_back({color, id});
        charles.push_back({durability, id});

    }
    sort(ada.begin(), ada.end());
    sort(charles.begin(), charles.end());

    ll ans = 0;
    for(ll i = 0; i < ada.size(); ++i){
        if(ada[i].second == charles[i].second) ans++;
    }
    casei++;
    cout << "Case #" << casei << ": " << ans << '\n';
  }
  return 0;
} 
// Accepted
