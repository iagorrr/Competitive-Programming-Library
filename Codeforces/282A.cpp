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

    int N;
    cin >> N;

    int i;
    string temp;

    int total = 0;

    for (i = 0; i < N; i++){
        cin >> temp;
        if (temp[1] == '+'){
            total++;
        }
        else{
            total--;
        }

    }

    cout << total << '\n';
	return 0;
}

// Accepted Iagorr 02.02.2022
