// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
 
void solve(vll a, vll b, int n){
  vll psum(n+2, 0); 
  for(int i = 1; i <= n; ++i) 
    psum[i] += psum[i-1] + b[i-1];
 
  vector<pair<ll, ll>> ans(n+2, {0ll, 0ll});
  
  for(int i = 0; i < n; ++i){
    ll l = i+1;
    ll r = n;
    ll anspos = i;
    while(l <= r){
      ll mid = l + (r-l)/2; 
      if(psum[mid]-psum[i] <= a[i]){
        anspos = mid;
        l = mid+1; 
      }
      else{
        r = mid-1;
      }
    }
    ll rest = a[i] - (psum[anspos] - psum[i]);
    
    ans[i+1].first++;
    ans[anspos+1].first--;
    ans[anspos+1].second += rest;
  }
   
  for(int i = 1; i <= n; ++i){
    ans[i].first += ans[i-1].first;
    cout << ans[i].first * b[i-1] + ans[i].second << ' ';
  }
  cout << '\n';
}
int main(){ // fastio;
  ll t; cin >> t;
  while(t--){
    int n; cin >> n;
 
    vll as(n);
    for(int i = 0; i < n; ++i) cin >> as[i];
 
 
    vll bs(n); 
    for(int i = 0; i < n; ++i) cin >> bs[i];
 
    solve(as, bs, n);
  }
}
