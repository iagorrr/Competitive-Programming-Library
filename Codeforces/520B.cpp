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
    lli N, M;
    cin >> N >> M;

    queue <pair<lli,lli>> Values;
    Values.push(make_pair(N, 0));

    pair <lli,lli> tempTop;
    vector <bool> alreadyHere(10001,false);
    while(!Values.empty()){
        tempTop = Values.front();      
        Values.pop();

        // Found !
        if(tempTop.first == M){
            break;
        }

        // Already checked.
        alreadyHere[tempTop.first] = true;

        // Add given some restrictions.
        if((tempTop.first > 0) && (!alreadyHere[tempTop.first-1])){
            Values.push(make_pair(tempTop.first-1, tempTop.second+1));
        }

        if((tempTop.first*2 <= 10000) && (!alreadyHere[tempTop.first*2])){
            Values.push(make_pair(tempTop.first*2, tempTop.second+1));
        }
    }
    
    cout << tempTop.second << endl;
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

// Accepted.