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

#define maxgrau 200002
/*====================================================================================================*/
int main(void){
	sws
    lli totalRecipes, minimalRe, totalQuestions;
    cin >> totalRecipes >> minimalRe >> totalQuestions;

    // Receiving the recipes she knows.
    vll acceptTemp(maxgrau, 0);
    lli lTemp, rTemp;
    lli atual;
    LOOP(i, 0, totalRecipes){
        cin >> lTemp >> rTemp;
        acceptTemp[lTemp]++;
        acceptTemp[rTemp+1]--;
    }
    atual = acceptTemp[1];
    LOOP(i, 2, maxgrau-1){// Generating 'prefix sum'
        atual += acceptTemp[i];
        acceptTemp[i] = atual;
    }

    // Generating psum for the following consults.
    vll accepttRange(maxgrau,0);
    LOOP(i, 1, maxgrau-1){
        if(acceptTemp[i] >= minimalRe){
            acceptTemp[i] = 1;
        }
        else{
            acceptTemp[i] = 0;
        }
    }
    atual = acceptTemp[1];
    LOOP(i, 2, maxgrau-1){
        atual += acceptTemp[i];
        acceptTemp[i] = atual;
    }
    // Verifying admissible temperature between a and b.
    lli a, b;
    lli admissible;
    LOOP(i, 0, totalQuestions){
        cin >> a >> b;
        // Making consult to our psum.
        cout << acceptTemp[b] - acceptTemp[a-1] << endl;
        
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