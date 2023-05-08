#include <bits/stdc++.h>

using namespace std;
/*====================================================================================================*/
int main(void){
    string a, b;

    int T;
    cin >>T;
    while(T--){
        int N;
        string S;
        cin >> N;
        cin >> S;

        // Empilhar e desempilhar.
        stack <char> pilha;
        for(int i = 0; i < N; i++){
            if(S[i] == '(') pilha.push('(');
            else if (S[i] == ')'){
                if(pilha.empty() || pilha.top() == ')') pilha.push(')');
                else pilha.pop();
            }
        }

        cout << pilha.size()/2 << endl;
    }

	return 0;
}