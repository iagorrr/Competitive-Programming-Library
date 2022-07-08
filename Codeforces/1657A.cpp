#include <bits/stdc++.h>

#define vll vector <long long int>
#define lli long long int
#define ulli unsigned long long int 
#define vbool vector <bool> 


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
    lli N;
    cin >> N;
    
    lli x, y;
    lli moves;
    long double distanceFloat;
    lli distanceInt;
    LOOP(i, 0, N){
        cin >> x >> y;
        
        distanceFloat = sqrt(x*x + y*y);
        distanceInt = sqrt(x*x + y*y);

        if(x == 0 && y == 0){
            cout << "0" << endl;
        }
        else if(distanceInt == distanceFloat){
            cout << "1" << endl;
            continue;
        }
        else if(distanceInt != distanceFloat){
            cout << "2" << endl;
            continue;
        }

        

    }
	return 0;
}
/*====================================================================================================*/

// Function to return the ~X.
ulli nop(ulli number){
    return (~number)^(ULLONG_MAX<<(hibit(number)));
    
} 

// Function to return the highest bit position of a number.
ulli hibit(ulli x){
    return (lli)log2(x)+1;
}
