#include <bits/stdc++.h>
using namespace std;


#define all(x) x.begin(), x.end()
const int MAXN(1'00'000);
int N, K, M;
int needKey[MAXN], hasKey[MAXN];
vector<int> G[MAXN];

void clearall() {
	fill(needKey, needKey+N, -1);
	fill(hasKey, hasKey+N, -1);
	for (int i = 0; i < N; i++) G[i].clear();
}

char vis[MAXN];
void bfs() {
	queue<int> q;
	q.emplace(0);
	fill(vis,vis+N,0);
	vis[0] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v : G[u]) {
			int keyinv = hasKey[v];
			int keyV = needKey[v];

			if (keyV == -1 and !vis[v]) {
				vis[v] = 1, q.emplace(v);
			}

			if (keyinv != -1) {
				if (vis[keyinv] == 2) {
					q.emplace(keyinv);
					vis[keyinv] = 1;
				}
			}

			if(keyV != -1 and !vis[v]) {
				if (vis[keyV]) 
					q.emplace(v), vis[v]=1;
				else vis[v] = 2;
			}

		}
	}
}

void run() {
	clearall();

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		hasKey[a] = b;
		needKey[b] = a;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	
	bfs();

	cout << "NY"[vis[N-1]] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> N >> K >> M) {
		if (N == -1 and M == -1 and K == -1) break;
		run();
	}

}
