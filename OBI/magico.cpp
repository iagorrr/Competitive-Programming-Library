#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli N;
    cin >> N;
    lli quadrado[N][N];

    lli ansColuna;
    lli ansLinha;
    bool achou = false;
    for(int i = 0;  i < N; i++){
        for(int j = 0; j < N; j++){
            lli temp;
            cin >> temp;
            quadrado[i][j] = temp;
            if(temp == 0){
                ansLinha = i;
                ansColuna = j;
            }
        }
    }

    lli somaLinhaErrada = 0;
    for(int j = 0; j < N; j++){
        somaLinhaErrada += quadrado[ansLinha][j];
    }

    lli somaLinha = 0;
    for(int i = 0; i < N; i++){
        if(i != ansLinha){
            for(int j = 0; j < N; j++){
                somaLinha += quadrado[i][j];
            }
            break;
        }
    }

    cout << somaLinha - somaLinhaErrada << endl;
    cout << ansLinha +1<< endl;
    cout << ansColuna +1<< endl;

    return 0;
}