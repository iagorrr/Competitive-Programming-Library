#include <bits/stdc++.h>

#define vll vector<long long int>
#define lli long long int


#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
using namespace std;



int main(void){
	sws
    vll cartas(5);
    bool crescente = true;
    bool decrescente = true;

    LOOPIN(i, 5, cartas);

    LOOP(i, 1, 5){
        if (cartas[i] < cartas[i-1]){
            crescente = false;
        }

        if(cartas[i] > cartas[i-1]){
            decrescente = false;
        }
    }

    if (crescente){
        cout << 'C' << endl;
    }
    else if (decrescente){
        cout << 'D' << endl;
    }
    else{
        cout << 'N' << endl;
    }
	return 0;
}

// Accepted Iagorrr 02.11.2022
