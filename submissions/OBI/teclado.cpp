// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;


int main(){
    map<char, string> teclado;
    teclado['2'] = "abc";
    teclado['3'] = "def";
    teclado['4'] = "ghi";
    teclado['5'] = "jkl";
    teclado['6'] = "mno";
    teclado['7'] = "pqrs";
    teclado['8'] = "tuv";
    teclado['9'] = "wxyz";
    
    string numero;
    cin >> numero;

    int q;
    cin >> q;
    int ans = 0 ;
    while(q--){
        string palavra;
        cin >> palavra;

        if(palavra.size() != numero.size()) continue;

        bool check = true;
        for(int i = 0; i < numero.size(); ++i){
            if(teclado[numero[i]].find(palavra[i]) == teclado[numero[i]].npos){
                check = false;
                break;
            }
        }
        if(check) ans++;
    }

    cout << ans << '\n';
    return 0;
}

// 100/100 aceito
