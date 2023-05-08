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

    int i;
    int j;
    int matrix[5][5];
    int totalmoves=0;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] == 1){

                if (i >= 2){
                    totalmoves += i-3+1;
                }
                else{
                    totalmoves += 3-i-1;
                }

                if (j >= 2){
                    totalmoves += j-3+1;
                }
                else{
                    totalmoves += 3-j-1;
                }
            }
        }
    }

    cout << totalmoves << '\n';
	return 0;
}

// Accepted Iagorr 02.02.2022
