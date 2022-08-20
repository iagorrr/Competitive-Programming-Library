// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;
#define MAX_N 1000+1
#define MAX_M 1000+1

ll editdp[MAX_N+1][MAX_M+1];
ll edit_distance(const string  &s1, const string &s2){
    // cost to : insert, delete, substitute
    const ll c_i = 1, c_d = 1, c_s = 1;

    const ll m = s1.size(), n = s2.size();

    // if there is i-characters at s1 and 0 at s2, the cost is the cost to remove from s1.
    for(ll i = 0; i <= m; ++i) editdp[i][0] = i*c_d;

    /* now if there is j-characters at s2 and 0 at s1 the total cost is the cost to insert 
    j-characters at s1.
    */
    for(ll j = 1; j <= n; ++j) editdp[0][j] = j*c_i;


    /*
        now for each pair i and j we check which is the best operation, and for that pair, the best
        one is the one with the lowest cost, and so on.

        - note that we already calculate every positon for i or j = 0.
    */
    for(ll i = 1; i <= m; ++i){
        for(ll j = 1; j <= n; ++j){
            ll insertion = editdp[i][j-1] + c_i;
            ll deletion = editdp[i-1][j] + c_d;
            ll change = editdp[i-1][j-1] + c_s*(s1[i-1] == s2[j-1] ? 0 : 1);

            editdp[i][j] = min({insertion, deletion, change});
        }
    }

    return editdp[m][n];
}
vector<string> dic(1000+5);
ll d, q;
void solve(string s){
    map <string, ll> ans;

    for(ll i = 0; i < d; ++i)
        ans[dic[i]] = edit_distance(s, dic[i]);
    


    for(ll i = 0; i < d; ++i){
        if(ans[dic[i]] <= 2) cout << dic[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> d >> q;

    for(ll i =0 ; i < d; ++i) cin >> dic[i];

    while(q--){
        string s;
        cin >> s;
            solve(s);
    }
    return 0;
}

// AC
