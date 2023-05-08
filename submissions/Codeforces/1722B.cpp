// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<long long>;

string solve(string a, string b){

    for(int i = 0; i < (int)a.size(); ++i){
        if(!(a[i] == b[i] or (a[i] == 'G' and b[i] == 'B') or (a[i] == 'B' and b[i] == 'G'))) return "NO";
    }

    return "YES";
}
int main(){
    fast
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        string a;
        string b;
        cin >> a >> b;

        cout << solve(a, b) << endl;
    }

    return 0;
}