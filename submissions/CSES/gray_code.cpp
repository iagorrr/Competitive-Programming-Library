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

string binToGray(string bin){
	string gray(bin.size(), '0');
	int n =  bin.size()-1;
	gray[0] = bin[0];
	for(int i = 1; i <= n; i++){
		gray[i] = '0'+(bin[i-1]=='1')^(bin[i]=='1');
	}
	return gray;
}

void run(){
  int n; cin >> n;
  vector<string> ans;
  for(int i = 0; i < (1<<n); ++i) {
	  string bin = bitset<32>(i).to_string().substr(32-n);
	  auto gray = binToGray(bin);
	  cout << gray << '\n';
  }
}

int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, gray code, strings
