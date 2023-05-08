#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli sumDigits(lli X);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli N;
    lli M;
    lli S;

    cin >> N >> M >> S;

    for(int i = M; i >= N; i--){
        if(sumDigits(i) == S){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

lli sumDigits(lli X){
    lli rest;
    lli result =0;

    do{
        rest = X % 10;
        result += rest;
        X = X / 10;

    }while(X > 0);

    return result;
}