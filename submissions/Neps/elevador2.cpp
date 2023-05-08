#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main(){
    int N;
    cin >> N;

    vector <int> caixas(N);
    for(int i = 0; i < N; i++) cin >> caixas[i];

    sort(caixas.begin(), caixas.end());
    for(int i = 1; i < N; i++){
        if(caixas[i] - caixas[i-1] > 8){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;
    return 0;
}