#include <bits/stdc++.h>

using namespace std;

// Macros/templates
#define LOOP(I, S, E) for(int I = S; I < E; I++)
#define SWAP(A, B) A ^= B ^= A ^= B

template<typename... T>
void readInput(T&... args){
	((cin >> args), ...);
}



int main(void){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    // Just divide the area of the square by the area of a single piece of domino.
    cout << A*B / 2 << '\n';
	return 0;
}

// Accepted Iagorrr 02.02.2022
