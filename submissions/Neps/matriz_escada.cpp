// https://www.beecrowd.com.br/judge/pt/problems/view/2450
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
lli sumdigits(lli x);

lli N, M;
unsigned int matriz[500][500];
bool verificaEscada(lli x, lli y){
    // Verificar se é o elemento mais a esquerda.
    bool maisAesquerda = true;
    LOOP(i, 0, y){
        if(matriz[x][i] != 0){
            maisAesquerda = false;
            break;
        }
    }
    if(maisAesquerda){
        LOOP(i, x+1, N){ // linhas abaixo de x
            LOOP(j, 0, y+1){ // colunas antes de x;
                if(matriz[i][j] != 0) return false;
            }
        }
    }

    return true;
}
/*====================================================================================================*/
int main(void){
	sws
    cin >> N >> M;

    bool escada = true;
    LOOP(i, 0, N){
        LOOP(j, 0, M){
            cin >> matriz[i][j];
        }
    }

    lli zeros;
    bool temquezerar;
    LOOP(i, 0, N){
        zeros = 0;
        LOOP(j, 0, M){
            if(matriz[i][j] != 0){
                if(!verificaEscada(i, j)){
                    // cout << "N" << i << " " << j << endl;
                    cout << "N" << endl;
                    return 0;
                }
            }
            else{
                zeros++;
            }
        }

        if(zeros == M-1) temquezerar = true;

        if((temquezerar) && (zeros < M-1)){
            cout << "N" << endl;
            return 0;
        }

    }
    cout << "S" << endl;
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

// Accepted.
