#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector <int> valores(N);
    for(int i = 0; i < N; i++)
        cin >> valores[i];

    if(N < 3){
        cout << N << endl;
        return 0;
    }

    int melhorResultado = 0;
    for(int A = 1; A <= N; A++){
        for(int B = A+1; B <= N; B++){
            // Contar alternacao de A e B.
            bool consideraA = true;
            bool consideraB = true;
            int totalA = 0;
            int totalB = 0;
            for(int i = 0; i < N; i++){
                if(valores[i] == A){
                    if(consideraA) {
                        totalA++;
                        consideraA = false;
                    }
                    consideraB = true;
                }

                if(valores[i] == B){
                    if(consideraB){
                        totalB++;
                        consideraA = true;
                    }
                    consideraB = false;
                }
            }
            
            // Caso seja o melhor resultado possível.
            if(totalA+totalB > melhorResultado) melhorResultado = totalA + totalB;
            
        }
    }

    cout << melhorResultado << endl;

    return 0;
}