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
	ll n, r;
	cin >> n >> r;

	set<pair<ll, ll>> check;
	for(int i = 0; i < r; ++i){
		ll a , b;
		cin >> a >> b;

		check.insert({min(a,b), max(a,b)});
	}

	n--;
	cout << n*(n+1) / 2 - check.size() << '\n';

    return 0;
}

// AC.
