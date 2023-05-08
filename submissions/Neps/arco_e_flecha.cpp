#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    lli T;
    cin >> T;
    vector <lli> V;
    lli penalidade = 0;
    while(T--){
        lli X, Y;
        cin >> X >> Y;

        X += penalidade;
        Y += penalidade;
        lli D = X*X + Y*Y;
        penalidade = 0;
        while(penalidade < V.size() && V[penalidade] <= D) penalidade++;
        V.push_back(D);
        cout << penalidade << endl;
    }
    return 0;
}