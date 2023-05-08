// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void run(){
  ll n, p, q, r;
  cin >> n >> p >> q >> r;
  vll a(n); INV(a);

  vll psum(n+1);
  for(int i = 1; i <= n; ++i) {
    psum[i] = psum[i-1] + a[i-1];
  }

  for(int x = 1; x <= n; ++x) {
    int L = x;
    int R = n;
    int y = -1;
    while(L <= R) {
      int mid = L + (R-L)/2;
      if(psum[mid]-psum[x-1] == p) {
        y = mid+1;
        break;
      }
      else if (psum[mid]-psum[x-1] < p) {
        L = mid + 1;
      }
      else {
        R = mid -1; 
      }
    }
    int z = -1;
    if(y != -1) {
      L = y;
      R = n;
      while(L <= R) {
        int mid = L + (R-L)/2;
        if(psum[mid]-psum[y-1] == q) {
          z = mid+1;
          break;
        }
        else if (psum[mid]-psum[y-1] < q) {
          L = mid + 1;
        }
        else {
          R = mid -1; 
        }
      } 
    }
    int w = -1;
    if(z != -1) {
      L = z;
      R = n;
      while(L <= R) {
        int mid = L + (R-L)/2;
        if(psum[mid]-psum[z-1] == r) {
          w = mid+1;
          break;
        }
        else if (psum[mid]-psum[z-1] < r) {
          L = mid + 1;
        }
        else {
          R = mid -1; 
        }
      }
    }
    if(y != -1 and z != -1 and w != -1) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, prefix sum, binary search.

