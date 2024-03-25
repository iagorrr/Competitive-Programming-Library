#include <bits/stdc++.h>
using namespace std;

string pi = "wbwbwwbwbwbw";
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int TW = 7, TB = 5;


	int tw, tb;
	tw = tb = 0;
	vector<int> wpre(1), bpre(1);
	for (auto c : pi) {
		tw += (c == 'w');
		tb += (c == 'b');
		wpre.emplace_back(tw);
		bpre.emplace_back(tb);
	}

	tw = tb = 0;
	vector<int> wsuff(1), bsuff(1);
	for (int i = (int)pi.size() -1; i >= 0; i--) {
		char c = pi[i];
		tw += c == 'w';
		tb += c == 'b';
		wsuff.emplace_back(tw);
		bsuff.emplace_back(tb);
	}

	int w, b;
	cin >> w >> b;

	for (int i = 0; i < (int)pi.size(); i++) {
		int tw = 0, tb = 0;
		for (int j = i; j < (int)pi.size(); j++) {
			tb += pi[j] == 'b';
			tw += pi[j] == 'w';
			if (tb == b and w == tw) {
				cout << "Yes\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < (int)wsuff.size(); i++) {
		for (int k = 0; k <= 100; k++) {
			for (int j = 0; j < (int)wpre.size(); j++) {
				int tw = wsuff[i] + wpre[j] + TW*k;
				int tb = bsuff[i] + bpre[j] + TB*k;
				if (tw == w and tb == b) {
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	
	cout << "No\n";
}

// AC, strings, math
