// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

struct person {
	ll entrada;
	ll id;
	ll gasta;
	ll paciencia;
	ll delay;
	inline bool const operator < (const person &a1) const  {
		if(entrada != a1.entrada)
			return a1.entrada < entrada;
		else 
			return a1.id < id;
	}
};

void run() {
	ll n; cin >> n;
	priority_queue<person> pq;

	for(int i = 0; i < n; ++i) {
		person p;
		cin >> p.gasta >> p.paciencia >> p.delay;
		p.entrada = 0;
		p.id = i;
		pq.push(p);
	}

	ll time = 0;
	while(!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		// chegou esperou e vazou, o tempo ja tá lá na frente.
		if(cur.entrada + cur.paciencia < time) {
			cur.entrada += cur.paciencia + cur.delay;
			pq.push(cur);
		}
		else {
			time = max(time, cur.entrada)+ cur.gasta;
		}
	}

	cout << time << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}
