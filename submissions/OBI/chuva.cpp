#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli N;
    lli S;
    cin >> N >> S;
    vector <lli> medicoes(N+2, 0);
    for(lli i = 1; i < N+1; i++) cin >> medicoes[i];

    for(lli i = 1; i < N+2; i++){
        medicoes[i] += medicoes[i-1];
    }   

    lli ans = 0;
    lli j;
    for(lli i = 0; i < N+1; i++){
        j = i+1;
        while(medicoes[j] - medicoes[i] <= S && j < N+1){
            if(medicoes[j]-medicoes[i] == S) ans++;
            j++;    
        }
    }

    cout << ans << endl;
    return 0;
}