#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll INF = 1e18;

// impossível :
// adicionei, fiz query e tava ordenado, dai tirei e ficou desordenado
// deixei só um elemento e estava desordenado
// vazio e estar desordenado

// possível:
// partir de um ordenado ou vazio e a query ser ordenado
bool run() {
	string s;
	cin >> s;

	int desordenados = 0;
	vi cur;
	int numsei = '?';
	int ordem = '1';
	int desordem = '0';
	int i = 0;
	for(auto &c : s) {
		/*
		cout << "i: " << i << " c: " << c << "  ";
		for(auto &cur_i : cur) cout << (char)cur_i << ' ';
		cout << endl;
		*/

		if(c == ordem or c == desordem) {
			if(c == desordem) {
				if(len(cur) <= 1) return false;
				if(cur.back() == ordem) return false;
				if(cur.back() == numsei) {
					cur.back() = desordem;
					desordenados++;
					continue;
				}
			}
			if(c == ordem) {
				if(len(cur) <= 1) continue;
				if(desordenados >= 1){
				 	return false;
				}
				if( cur.back() == desordem){
					return false;
				}
				if(cur.back() == numsei) {
					cur = vi(len(cur), ordem);
					cur[0] = '?';
					continue;
				}
			}
		}
		else {
			if(c == '+') {
				cur.pb(numsei);
			}
			else {
				if(cur.back() == desordem) desordenados--;
				cur.pop_back();
			}
		}
		i++;
	}
	return true;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) {

		if(run())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}

// AC, implementation
