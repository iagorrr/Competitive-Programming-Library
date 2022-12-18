// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

bool check(int a, int b, int c, int d){
    return a < b and c < d and a < c and b < d;

}

void rotate(int *a, int *b, int *c, int *d){
    int as, bs, cs, ds;
    as = *a;
    bs = *b;
    cs = *c;
    ds = *d;

    *a = cs;
    *b = as;
    *c = ds;
    *d = bs;
}
string solve(int a , int b, int c, int d){
    for(int i = 0; i < 4; ++i){
        if(check(a, b, c, d)) return "YES";
        rotate(&a, &b, &c, &d);
    }

    return "NO";
}
int main(){ 
    fastio;

    ll n;
    cin >> n;

    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << solve(a, b, c, d) << '\n';
    }
    return 0;
}
