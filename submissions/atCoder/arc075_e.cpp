// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// if you want to find the elements less or equal :p 
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void run(){
  ll n, k; cin >> n >> k;
  vll a(n); INV(a);

  /*
     with that we know if a position
     contributes to increase or decrease
     the mean.
  */
  for(auto &ai : a) ai -= k;

  ordered_set<ll> os;
  os.insert(0);
  ll sum = 0;
  ll ans = 0;
  for(auto ai : a) {
    sum += ai; 
    /*
       considering i'm at *i* position,
       if i have *l* sums lower than sum[i]
       it means that the value a[i] increased
       the sum *l* times, so starting from whatever
       of these l points i can reach a[i] and
       turn the mean greater than k again !
    */
    ll l = (ll)os.order_of_key(sum+1);
    ans += l;
    os.insert(sum);

    // dbg(sum, ans, l);
  }
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, ordered set.
