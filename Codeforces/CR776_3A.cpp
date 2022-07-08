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
	// sws
    lli T;
    cin >> T;

    char string[49];
    char precious;
    bool possible;
    lli current;
    lli followTemp;
    LOOP(i, 0, T){
        cin >> string;
        cin >> precious;


        vector <pair<lli, lli>> sides;
        possible = false;
        LOOP(j, 0, strlen(string)){
            if(string[j] == precious){
                if((j % 2 == 0) && ((strlen(string)-j-1) % 2 == 0)){
                    possible = true;
                    break;
                }
            }
        }

        if(possible){
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