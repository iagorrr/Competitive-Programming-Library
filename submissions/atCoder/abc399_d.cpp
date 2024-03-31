/*
	> pra ficar junto um dos dois vai ter que ficar
       	travado em uma parede ou obstáculo
		> como move na mesma direção é como se
		estivesse um correndo do outro ent pre
		cisa traver né po
	> tem N*N*N*N estados
		> 1,2960000 * 10^17
		? é mucho ???
		> compilou no custom !
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 60;
int n;
vector<string> grid(maxn);
bitset<maxn> vis[maxn][maxn][maxn];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int solve(vector<pair<int,int>> pos) {
	auto [a, b] = pos.back();
	auto [c, d] = pos.front();

	vis[a][b][c][d] = 1;
	using tuplao = tuple<int,int,int,int,int>;
	queue<tuplao> q;
	q.emplace(0, a, b, c, d);

	while (!q.empty()) {
		auto [e, a, b, c, d] = q.front();
		q.pop();
		if (a == c and b == d) {
			return e;
		}

		auto f = [&](int x, int y, int xo, int yo) -> pair<int,int> {
			if (x < 0 or y < 0 or x == n or y == n)
				return {xo, yo};
			if (grid[x][y] == '#')
				return {xo, yo};
			return {x, y};
		};

		for (int i = 0; i < 4; i++) {
			auto a2 = a + dx[i];
			auto b2 = b + dy[i];
			auto c2 = c + dx[i];
			auto d2 = d + dy[i];
			tie(a2, b2) = f(a2, b2, a, b);
			tie(c2, d2) = f(c2, d2, c, d);
			if (vis[a2][b2][c2][d2]) continue;
			vis[a2][b2][c2][d2] = 1;
			q.emplace(e+1, a2, b2, c2, d2);
		}	
	}


	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	vector<pair<int,int>> pos;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'P') {
				grid[i][j] = '.';
				pos.emplace_back(i, j);
			}
		}
	}

	cout << solve(pos) << '\n';
}
