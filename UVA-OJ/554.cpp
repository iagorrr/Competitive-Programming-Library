// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;
string alphabet = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
map <string, bool> dicWords;
pair <string, int> ans;

void check(string S){
    for(int k = 0; k < 27; k++){
        string D;
        int TempAns = 0;
        for(int i = 0; i < S.size(); i++){
            D.push_back(alphabet[alphabet.find(S[i])+k]);
        }
        // cout << D << endl;   


        // Verificar quais palavras decodificadas realmente existem.
        string word;
        for(int i = 0; i < D.size(); i++){
            if(D[i] != ' ' && i < D.size()+1) word.push_back(D[i]);
            else {
                if(dicWords[word]){// se achar um espaço verificar se a palavra formada realmente existe.
                    TempAns++;
                }
                word.clear();
            }
        }
        if(TempAns > ans.second){
            ans.first = D;
            ans.second = TempAns;
        }
    }
}

void outputFormated(string S, int lineSize){
    istringstream outputString(S);
    size_t lineLen = 0;// Better than an int or lli.
    string currentWord;

    while(outputString >> currentWord){
        size_t wordLen = currentWord.size();
        if(lineLen == 0){
            cout << currentWord;
            lineLen = currentWord.size();
            continue;
        }
        else{
            if(lineLen + wordLen + 1 > 60){
                cout << endl;
                cout << currentWord;
                lineLen = wordLen;
            }
            else{
                cout << ' ' << currentWord;
                lineLen += wordLen + 1;
            }
        }
    }
    cout << endl;
}

int main(){
    
    // Pra qualquer primeiro valor ser melhor.
    ans.second = -1;

    // Ler as strings correspondentes aos dicionários.
    string S;
    while(getline(cin, S)){
        if(S == "#") break;
        dicWords[S] = true;
    }
    
    // Ler a string codificada.
    getline(cin ,S);

    // Verificar qual a melhor resposta, dado o dicionário e a string.
    check(S);

    // Exibir a resposta com a formatação solicitada.
    outputFormated(ans.first, 60);

    return 0;
}

// Accepted.
