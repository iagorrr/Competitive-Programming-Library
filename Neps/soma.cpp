#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main(){
    lli N;
    lli K;

    cin >> N >> K;

    // lendo valores e fazendo delta sum.
    vector <lli> sum(N+2, 0);
    for(int i = 1; i < N+1; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    sum[N+1] += sum[N];



    int totalAns = 0;
    int j;
    for(int i = 0; i < N+1; i++){
        for(int j = i+1; j < N+1; j++){
            if(sum[j] - sum[i] == K){
                totalAns++;
            }
            else if(sum[j] - sum[i] > K){
                break;
            }
        }
    }


    cout << totalAns << endl;
    return 0;
}

// Não corrigido ainda.
