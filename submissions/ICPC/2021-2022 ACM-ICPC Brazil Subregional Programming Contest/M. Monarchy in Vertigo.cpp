/*
	- Build the whole tree considering that everyone is already born
	- Label everyone in the 'time of visitation' of the node
	- Than every node has an id which matchs the input, and id
	that matches the dfs order
	- The lowest 'dfs order id' alive should be the king :D
	- Process the queries from the end to the begining
		- case is a birth:
			- you can't consider this node in the previous query
			anymore, remove it from the 'alives set'
		- case is a death:
			- you can consider this node in the previous query
			insert it in the 'alives set'
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int Q; cin >> Q;
	vector<vector<int>> sons(Q+1);
	vector<int> true_to_fake(Q+1), fake_to_true(Q+1);
	int trueidcntid = 1, fakeidcnt = 2;
	vector<pair<int,int>> queries;

	while (Q--) {
		int a, b;
		cin >> a >> b;

		if (a == 1) {
			sons[b].emplace_back(fakeidcnt++);
		}
		queries.emplace_back(a, b);
	}

	auto putid = [&](auto &&self, int fakeid, int p = -1) -> void {
		true_to_fake[fakeid] = trueidcntid;
		fake_to_true[trueidcntid] = fakeid;
		trueidcntid++;
		for (auto v : sons[fakeid]) {
			if ( v != p) {
				self(self, v, fakeid);
			}
		}
	};

	putid(putid, 1, -1);

	set<int> trueidalive;
	for (int i = 1; i < trueidcntid; i++) {
		trueidalive.emplace(i);
	}

	for (auto [a, b] : queries) {
		if (a == 2)
			trueidalive.erase(true_to_fake[b]);
	}


	vector<int> ans;
	while (!queries.empty()) {
		auto [a, b] = queries.back();
		queries.pop_back();


		if (a == 1) {
			trueidalive.erase(true_to_fake[sons[b].back()]);
		}
		else {
			ans.emplace_back(fake_to_true[*trueidalive.begin()]);
			trueidalive.emplace(true_to_fake[b]);
		}

	}

	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		cout << *it << '\n';
	}
}

// AC, trees
