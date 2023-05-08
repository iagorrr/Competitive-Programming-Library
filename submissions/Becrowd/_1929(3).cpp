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
    lli A, B, C, D;

    cin >> A >> B >> C >> D;
    bool valido = false;
    // Simply try all combinations.

    // A B C 
    if ((A + B > C) && (B + C > A) && (C + A > B)){
        valido = true;
    }

    // D B C
    if ((D + B > C) && (B + C > D) && (C + D > B)){
        valido = true;
    }
    
    // A D C
    if ((A + D > C) && (D + C > A) && (C + A > D)){
        valido = true;
    }
    
    // A B D
    if ((A + B > D) && (B + D > A) && (D + A > B)){
        valido = true;
    }

    if(valido){
        cout << 'S' << endl;
    }
    else{
        cout << 'N' << endl;
    }
    
	return 0;
}

// Accpted Iagorrr 11.02.2022
