#include <bits/stdc++.h>
using namespace std;

const int maxnote = 100;
int trans[maxnote];
vector<string> notas({
	"^", "do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"
});

vector<set<int>> scales(1);
void build_scale(int x) {
	vector<int> increment({2, 2, 1, 2, 2, 2, 1});
	
	set<int> scale;
	scale.emplace(x);
	for (auto i : increment) {
		x += i;
		scale.emplace(trans[x]);
	}

	scales.emplace_back(scale);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i  = 1; i < maxnote; i++) {
		trans[i] = (trans[i-1]+1) % 13;
		if (!trans[i]) trans[i]++;
	}


	for (int i = 1; i <= 12; i++) {
		build_scale(i);
	}

	int n;
	cin >> n;
	set<int> input_notes;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		x = trans[x];
		input_notes.emplace(x);
	}

	auto check = [](set<int> &a, set<int> &b) -> bool {
		for (auto ai : a) {
			if (!b.count(ai)) return false;
		}
		return 1;
	};
	for (int i = 1; i <= 12; i++)  {
		if (check(input_notes ,scales[i])) {
			cout << notas[i] << '\n';
			return 0;
		}
	}

	cout << "desafinado\n";


}


