// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    int t;
    cin >> t;cin.ignore();
    const string vogais = "aeiou";

    while(t--){
        string s;
        getline(cin, s);
        int posvogal = 0;
        for(int i = 0; i < (int)s.size(); ++i){
            cout << s[i];
            if(s[i] != ' '){
                cout << vogais[posvogal % (int)vogais.size()];
                posvogal++;
            }
        }
        cout << endl;
    }    
    return 0;
}

