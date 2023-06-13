#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1e5+1;

ll N, M;
ll L, R;
ll O;
vector<pair<ll,ll>> E(MAXN); // age and manager.
vector<set<ll>> S(MAXN); // every subordinate to S.
vector<ll> ANS(MAXN);

// spread the party !
void bfs() {
	queue<ll> q;
	q.push(O);	

	vector<char> vis(N);
	vis[O] = true;
	while(!q.empty()){
		ll cur = q.front(); q.pop();
		ANS[cur]++;
		
		// call subordinates.
		for(auto s : S[cur]) {
			ll age = E[s].first;
			if(not vis[s] and age >= L and age <= R){
				q.push(s);
				vis[s] = true;
			}
		}

		// call manager.
		ll age  = E[E[cur].second].first;
		if(!vis[E[cur].second] and age >= L and age <= R) {
			q.push(E[cur].second);
			vis[E[cur].second] = true;
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;	
	for(int i = 0; i < N; ++i) {
		cin >> E[i].first >> E[i].second;
		E[i].second--;
		S[E[i].second].insert(i);
	}

	for(int i = 0; i < M; ++i) {
		cin >> O >> L >> R;
		O--;
		bfs();
	}

	for(int i = 0; i < N; ++i) cout<< ANS[i] << ' '; cout << '\n';

}

// TLE on test 23
