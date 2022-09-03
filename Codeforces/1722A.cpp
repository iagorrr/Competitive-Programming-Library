// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<long long>;

string solve(string s){
    string nome = "Timur";
    if(s.size() > nome.size()) return "NO";

    map<char, bool> check;
    int ans = 0;
    for(auto x : s){
        if(check[x] == false and (find(nome.begin(), nome.end(), x)!= nome.end())){
            ans++;
            check[x] = true;
        }
    }

    if(ans >= 5) return "YES";
    else return "NO";
}
int main(){
    fast
    ll n;
    cin >> n;

    while(n--){
        ll s;
        cin >> s;

        string permu;
        cin >> permu;

        cout << solve(permu) << endl;
    }

    return 0;
}