#include <bits/stdc++.h>
using namespace std;

const int MAXN(1'000'000 + 10);
vector<vector<int>> ga(MAXN+1);
vector<vector<int>> gb(MAXN+1);

int buildg(const string &s, vector<vector<int>> &g) {
	assert(s[0] != '(');
	assert(s.back() != '(');
	vector<string> stk;
	int pai = -1;
	for (auto c : s) {
		if (c == ' ' or c == '\n') continue;
		if (isdigit(c)) {
			if (stk.empty()) {
				stk.push_back(string(1, c));
			}
			else {
				if (isdigit(stk.back().back())) {
						stk.back().push_back(c);
				}
				else {
					stk.push_back(string(1, c));
				}
			}
		}
		else {
			if (c == '(') {
				pai = stoi(stk.back());
				stk.push_back(string(1, c));
			}
			else {
				int filho = stoi(stk.back());
				stk.pop_back();
				stk.pop_back();
				pai = stoi(stk.back());
				g[pai].emplace_back(filho);
			}
		}
	}
	if (pai == -1) return stoi(s);
	return pai;
}

void run() {
	string a, b;
	getline(cin, a);
	getline(cin, b);

	int pa =buildg(a, ga);
	int pb =buildg(b, gb);

	for (int i = 0; i <= MAXN; i++) {
		sort(ga[i].begin(), ga[i].end());
		sort(gb[i].begin(), gb[i].end());
		if (ga[i] != gb[i]) {
			cout << "No\n";
			return;
		}
	}

	if (pb != pa) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int main() {
	run();
}
