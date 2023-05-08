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

    lli N;
    cin >> N;

    // Receiving and, them show the proper otput.
    lli A, B;
    lli i;
    LOOP(i, 0, N){
        cin >> A >> B;
        cout << (A^B) << endl;
    }

	return 0;
}

// Accepted Iagorrr 10.02.2022
