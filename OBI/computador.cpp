// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;

    vll a(n+1, 0);
    /*
        1 = frente 
        2 = tras
        3 = imprime
    */
    while(m--){
        ll I, V, P;
        cin >> P;
        if(P != 3) cin >> I >> V;
        else cin >> I;
        
        switch (P){
            case 1:
                while(I <= n && V){
                    a[I] += V;
                    I++;
                    V--;
                }
                break;
            case 2:
                while(I >= 1 && V){
                    a[I] += V;
                    I--;
                    V--;
                }
                break;
            case 3:
                cout << a[I] << '\n';
                break;
            default:
                break;
        }
    }
    return 0;
}

// 20/100 TLE