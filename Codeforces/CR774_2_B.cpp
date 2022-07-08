#include <bits/stdc++.h>

#define vll vector<long long int>
#define lli long long int
#define ulli unsigned long long int


#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
using namespace std;

ulli nop(ulli number);
ulli hibit(ulli x);


/*====================================================================================================*/
int main(void){
	sws
    lli testcases;
    cin >> testcases;

    lli N;
    bool possible;
    lli sumblue, sumred;
    lli contblue, contred;
    LOOP(i, 0, testcases){
        // Receiving sequence.
        cin >> N;
        vll sequence(N+2, 0);
        LOOP(j, 1, N+1){
            cin >> sequence[j];
        }

        // Generating psum.
        possible = true;
        sort(sequence.begin()+1, sequence.end()-1);
        LOOP(j, 1, N+1){
            sequence[j] = sequence[j] + sequence[j-1];
        }

        // Verifying.
        contblue = (N/2) +1;
        contred = (N/2) - 1;
        sumblue = sequence[contblue];
        sumred = sequence[N] - sequence[contblue];

        if(sumblue < sumred){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
	return 0;
}
/*====================================================================================================*/

// Function to return the ~X.
ulli nop(ulli number){
    long double numberfloat = number;
    ulli toshift = 0;
    return (~number)^(ULLONG_MAX<<(hibit(number)));
    
} 

// Function to return the highest bit position of a number.
ulli hibit(ulli x){
    return (lli)log2(x)+1;
}   