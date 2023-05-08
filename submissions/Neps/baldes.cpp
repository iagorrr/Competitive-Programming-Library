// iagorrr ;) abordage naive O(n⁴)
#include <bits/stdc++.h>
using namespace std;
int mod(int x, int y){
    return max(x -y, y -x);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    // só nos interessa o maior e o menor valor dentro do balde.
    vector<int> baldes[n];
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        baldes[i].push_back(x);
    }

    for(int q = 0; q < m; ++q){
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 1){
            baldes[b-1].push_back(a);
        }
        else { // brutar qual a maior distancia.
            int maiordis = -1;
            a--; b--;
            for(int i = a; i <= b; ++i){
                for(int j = a; j <= b; ++j){
                    if(i == j) continue;
                    for(auto x : baldes[i]){
                        for(auto y : baldes[j]){
                            maiordis = max(maiordis, mod(x, y));
                        }
                    }
                }
            }
            cout << maiordis << '\n';
        }
    }
    return 0;
}

// Time limit Exceeded 10/100