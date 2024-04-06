#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
using vi = vector<int>;

struct DSU {
  vi ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(all(ps), 0);
    // for (int i = 0; i < N; i++) sts[i].insert(i);
  }
  int find_set(int x) {
    return ps[x] == x ? x : ps[x] = find_set(ps[x]);
  }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py]) swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};


const int MAXH = 2*200, MAXN = 2*300;
const int oo = 1'000'000'000ll;
int H, W, N;
string grid[MAXH];
int SX, SY, FX, FY;
DSU dsu(MAXN);

map<pair<int,int>, int> MED_ID;
int MED_E[MAXN];
pair<int,int> MED[MAXN];


bool valid(int x, int y) {
	if (x < 0 or y < 0) return false;
	if (x >= H or y >= W) return false;
	if (grid[x][y] == '#') return false;
	return true;
}

bitset<MAXH> vis[MAXH];
set<int> to_run, runned;
void med_bfs(int id)  {
	for (int i = 0; i < H; i++) vis[i].reset();

	auto [xs, ys] = MED[id];
	
	queue<tuple<int,int,int>> q;
	q.emplace(MED_E[id], xs, ys);
	vis[xs][ys] =  1;

	while(!q.empty()) {
		auto [d, x, y] = q.front();
		if (MED_ID.count({x, y})) {
			dsu.union_set(id, MED_ID[{x,y}]);
			if (!runned.count(MED_ID[{x,y}])) {
				to_run.emplace(MED_ID[{x,y}]);
			}
		}

		q.pop();

		if (d == 0) continue;

		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (!valid(x2,y2)) continue;	
			if (vis[x2][y2]) continue;
			vis[x2][y2] = 1;
			q.emplace(d-1, x2, y2);
		}
	}
}

int dist_t[MAXH][MAXH];
void t_bfs() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			dist_t[i][j] = oo;
		}

	}
	
	queue<tuple<int,int>> q;
	int xs = FX;
	int ys = FY;
	q.emplace(xs, ys);
	dist_t[xs][ys] =  0;

	while(!q.empty()) {
		auto [x, y] = q.front();
		// cerr << "x : " << x << " y: " <<  y << '\n';
		int d = dist_t[x][y];
		q.pop();


		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (!valid(x2,y2)) continue;	
			if (dist_t[x2][y2] != oo) continue;
			dist_t[x2][y2] = d+1;
			q.emplace(x2, y2);
		}
	}
	
}


bool solve() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> grid[i];
		for (int j = 0; j < W; j++) {
			if (grid[i][j] == 'S') {
				SX = i, SY=  j;
			}
			if (grid[i][j] == 'T') {
				FX = i, FY = j;
			}
		}
	}

	cin >> N;
	for (int i = 1, x, y, e; i <= N; i++) {
		cin >> x >> y >> e;
		x--, y--;
		MED_ID[{x,y}] = i;
		MED_E[i] = e;
		MED[i] = {x, y};
	}

	if (MED_ID.count({SX, SY})) {
		to_run.emplace(MED_ID[{SX, SY}]);
	}

	while (!to_run.empty()) {
		auto u = *to_run.begin();
		to_run.erase(to_run.begin());
		med_bfs(u);
		runned.emplace(u);
	}

	t_bfs();

	if (MED_ID.count({SX, SY})) {
		int idi = MED_ID[{SX,SY}];
		for (int i = 1; i <= N; i++) {
			if (dsu.same_set(i, idi)) {
				// cerr << "i: " << i << '\n';
				auto [x, y] = MED[i];
				if (dist_t[x][y] <= MED_E[i]) return true;	
			}
		}
	}

	return false;
																								           
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << (solve() ? "Yes" : "No") << '\n';
}


// AC, graphs, dsu
