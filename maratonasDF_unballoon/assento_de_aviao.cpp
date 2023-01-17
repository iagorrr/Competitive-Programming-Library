// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
	ll t;
	cin >> t;

	while(t--)
	{
		ll n; cin >> n;

		string s; cin >> s;

		char c = s.back();

		string a; for(int i = 0; i < n; ++i) a+= alphabet[i]; 
		string b = a; reverse(b.begin(), b.end());

		bool ans = false;
		for(int i = 0; i < n; ++i){
			if(a[i] == c)
				if(b[i] == c) ans = true;
		}

		cout << (ans ? "S" : "N") << '\n';
	}	
    return 0;
}
// AC.