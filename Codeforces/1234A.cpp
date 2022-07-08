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
bool isPalindrome(string s);
bool validBracket(string b);


/*====================================================================================================*/
int main(void){
	sws
    lli N;
    cin >> N;

    lli size;
    LOOP(i, 0, N){

        // Receiving all the values.
        cin >> size;
        vll v(size);
        lli originalSum = 0;
        LOOP(j, 0, size){
            cin >> v[j];
            originalSum += v[j];
        }
        sort(v.begin(), v.end());
        
        // Looking for the lower value that we can put all in the same price. USING LOWER BOUND !
        lli l = 0;
        lli r = 10000001;
        lli mid;

        while(l < r){
            mid = (l+r)/2;

            if(mid*size >= originalSum){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }

        cout << l << endl;
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

// Function to verify if a given string is a palindrome or not.
bool isPalindrome(string s){
    string aux = s;
    reverse(aux.begin(), aux.end());

    LOOP(i, 0, s.size()){
        if(aux[i] != s[i]){
            return false;
        }
    }

    return true;
}

// Function to verify if a string with brackets is valid or not.
bool validBracket(string b){
    stack <char> verify;

    LOOP(i, 0, b.size()){
        if(b[i] == ')' && verify.top() == '('){
            verify.pop();
        }
        else{
            verify.push(b[i]);
        }
    }

    if(!verify.empty()){
        return false;
    }
    else{
        return true;
    }
}

// Accepted.
