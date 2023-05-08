// iagorrr ;)
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main(){
    vector<string> matrix;
    for(ll i =0; i < 10; ++i){
        string x;
        cin >> x;
        matrix.push_back(x);
    }

    ll a, b, c ,d;

    bool first = true;

    for(ll i = 0; i < (ll)matrix.size(); ++i){
        for(ll j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == '#') d = j+1;
            if(matrix[i][j] == '#' and first){
                a = i+1;
                first = false;
            }
            if((j == 0 and matrix[i][j] == '#') || (matrix[i][j] == '#' and matrix[i][j-1] == '.')) c = j+1;
            if(matrix[i][j] == '#') b = i +1;

        }
    }

    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';
    return 0;
}

// Accepted.