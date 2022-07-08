#include <bits/stdc++.h>

#define vll vector <long long int>
#define lll list <long long int>
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
lli fullProduct(lll v);

struct tCase{
    lll arra;
    lli front=0;
    lli back=0;
};
typedef struct tCase Tcase;

/*====================================================================================================*/
int main(void){
	sws
    lli N;
    cin >> N;

    lli size;
    LOOP(i, 0, N){

        // Receive the vector.
        cin >> size;
        lll v;
        lli temp;
        LOOP(j, 0, size){
            cin >> temp;
            v.push_back(temp);
        }

        // ====================================
        Tcase tempCase;
        tempCase.arra = v;
        tempCase.back = 0;
        tempCase.front = 0;

        Tcase maximalCase = tempCase;
        lli maximalValue = fullProduct(tempCase.arra);
        queue <Tcase> tree;
        tree.push(tempCase);

        map <pair<lli,lli>, bool> checked;
        while(!tree.empty()){

            // Padrão, tira e da check.
            tempCase = tree.front();
            tree.pop();
            checked[make_pair(tempCase.back,tempCase.front)] = true;

            // Verificando se essa configuração é maior.
            lli currentFullProduct = fullProduct(tempCase.arra);
            if(currentFullProduct > maximalValue){
                maximalValue = currentFullProduct;
                maximalCase = tempCase;
            }

            // Adicionar a possibilidade de remover das BACK, não vazio e não checado.
            Tcase caseToadd;
            if(!tempCase.arra.empty() && !checked[make_pair(tempCase.back+1,tempCase.front)]){
                caseToadd = tempCase;
                caseToadd.arra.pop_back();
                caseToadd.back++;
                tree.push(caseToadd);
            }

            // Adicionar a possibilidade de remover das front, não vazio e não checado.
            if(!tempCase.arra.empty() && !checked[make_pair(tempCase.back,tempCase.front+1)]){
                caseToadd = tempCase;
                caseToadd.arra.pop_front();
                caseToadd.front++;
                tree.push(caseToadd);
            }
        }

        cout << maximalCase.front << " " << maximalCase.back << endl;


    }
	return 0;
}
/*====================================================================================================*/
// Function to return the multiplications of all numbers of an vector.
lli fullProduct(lll v){
    lli result = 1;
    while(!v.empty()){
        result = result* v.front();
        v.pop_front();
    }
    return result;
}

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