// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        
        if(s == "grafico") cout << "Paciencia..." << '\n';
        else if(s == "grafo") cout << "Certo" << '\n';
        else cout << "Errado" << '\n';
        
    }
       return 0;
}