#include <bits/stdc++.h>

using namespace std;

int main(void){

    int total_casas, total_encomendas;

    cin >> total_casas;
    cin >> total_encomendas;

    // Recebendo número das casas.
    long long int num_casas[total_casas];
    int i;
    for (i = 0; i < total_casas; i++){
        cin >> num_casas[i];
    }

    // Recebendo ordem das entregas
    long long int ordem[total_encomendas];
    for (i = 0; i < total_encomendas; i++){
        cin >> ordem[i];
    }

    long int tempo_total = 0;
    int andou = 0;
    long int posicao_atual = 1;
    int j=0;
    for (i = 0; i < total_encomendas; i++){

        andou = 0;
        while(ordem[i] != num_casas[j]){

            if(ordem[i] > num_casas[j]){
                j++;
            }
            else{
                j--;
            }
            andou++;
        }

        tempo_total = tempo_total + andou;

    }

    cout << tempo_total << '\n';
    return 0;
}