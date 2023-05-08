#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long int lli;
typedef unsigned long long int ulli;


#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

ulli nop(ulli number);
ulli hibit(ulli x);
bool isPalindrome(string s);
bool validBracket(string b);
lli sumdigits(lli x);
bool hasXremovingInOrder(string S, string X);

/*====================================================================================================*/
int main(void){
    lli temp;
    vll amigos(4);
    lli time1=0;
    lli time2=0;

    LOOP(i, 0, 4){
        cin >> amigos[i];
    }
    sort(amigos.begin(), amigos.end());
    time1 += amigos[0];
    time1 += amigos[3];
    time2 += amigos[1];
    time2 += amigos[2];

    lli ans = time1 - time2 > 0 ? time1 - time2 : time2 - time1;
    cout << ans << endl;
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

// Function to return the sum of digits of a number.
lli sumdigits(lli x){
    lli rest;
    lli result = 0;

    do{
        rest = x % 10;
        result += rest;
        x = x/10;
    }while(x > 0);

    return result;
}

// to find if there is an string X in S by removing in blocks.
bool hasXremovingInOrder(string S, string X){
    ulli maskRemove = S.size() - X.size();
    for(ulli l = 0; l < S.size(); l++){
        vector <bool> mark(S.size(), true);
        ulli r = 0;
        while(r+l < S.size() && r < maskRemove){
            mark[r+l] = false;
            r++;
        }   

        string aux;
        for(ulli i = 0; i < S.size(); i++){
            if(mark[i]) aux.push_back(S[i]);
        }
        // cout << aux << endl;
        if(aux == X) return true;
    }

    return false;
}

// Accepted.
