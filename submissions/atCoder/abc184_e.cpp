#include <bits/stdc++.h>
using namespace std;

const int maxd = 2'000;
string grid[maxd];
int moves[maxd][maxd];
int h, w;
map<char, vector<pair<int,int>>> teles;


int xs, ys, xe, ye;
void parse() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ('a' <= grid[i][j] and grid[i][j] <= 'z') {
				teles[grid[i][j]].emplace_back(i, j);
			}
			
			if (grid[i][j] == 'S') xs = i, ys = j;
			if (grid[i][j] == 'G') xe = i, ye = j;
		}
	}
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
	if (x < 0 or y < 0) return false;
	if (x >= h or y >= w) return false;
	if (grid[x][y] == '#') return false;
	return true;
}

void bfs() {
	queue<tuple<int,int,int>> q;
	q.emplace(0, xs, ys);
	moves[xs][ys] = 0;


	set <char>  vis;

	while (!q.empty()) {
		auto [du, xu, yu] = q.front();
		if (du > moves[xu][yu]) continue;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x2 = xu + dx[i];
			int y2 = yu + dy[i];
			if (!valid(x2, y2)) 
				continue;
			if (moves[x2][y2] <= moves[xu][yu] + 1)
				continue;
			moves[x2][y2] = moves[xu][yu] + 1;
			q.emplace(moves[x2][y2], x2, y2);
		}

		if ('a' <= grid[xu][yu] and grid[xu][yu] <= 'z') {
			if (vis.count(grid[xu][yu]))
				continue;
			vis.emplace(grid[xu][yu]);
			for (auto [x2, y2] : teles[grid[xu][yu]]) {
				if (moves[x2][y2] <= moves[xu][yu] + 1)
					continue;
				moves[x2][y2] = moves[xu][yu] + 1;
				q.emplace(moves[x2][y2], x2, y2);
			}
		}

	}
}

void dbg() {
	for (auto [c, xs] : teles) {
		cerr << c << " : ";
		for (auto [x, y] : xs) cerr << "[" << x << ", " << y << "] ";
		cerr << '\n';
	}
}

auto run() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			moves[i][j] = 1'000'000'000;
		}
	}

	for (int i = 0; i  < h;i ++) {
		cin >> grid[i];
	}

	parse();
	// dbg();

	bfs();

	cout << (moves[xe][ye] == 1'000'000'000 ? -1 : moves[xe][ye]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	run();
}


// AC, bfs
