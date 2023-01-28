// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>

//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
	ll n;
	cin >> n;
	set<pair<int, string>> diff;
	for(int i = 0; i < q; ++i){
		int x;
		string c;
		cin >> x>> c;
		diff.insert({x, c});
	}

	cout << diff.size() << '\n';

    return 0;
}

// AC.
