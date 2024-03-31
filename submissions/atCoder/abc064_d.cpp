#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	deque<char> ans;
	vector<char> stk;

	for (auto c : s) {
		if ( c == '(') {
			ans.push_back('(');
			stk.push_back('(');
		}
		else {
			if (stk.empty() or stk.back() != '(') {
				ans.push_back(')');
				stk.push_back(')');
			}
			else{
				ans.push_back(')');
			       	stk.pop_back();
			}
		}
	}

	for (auto i : stk) {
		if (i == ')')
			ans.push_front('(');
		else
			ans.push_back(')');
	}

	for (auto c : ans) {
		cout << c;
	}
	cout << '\n';
}

// AC, strings, greddy
