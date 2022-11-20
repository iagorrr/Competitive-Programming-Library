#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

// Dividir a strings em quantos pedaços iguais possíveis, e verificar se o pedaço ordenado de cada uma é igual.
string solve(string s, int N){
    for(int i = N; i >= 2; i--){ // Quantidade de substrings.

        if(N % i == 0){ // Possível dividir em i strings iguais.
            int sizeS = N/i; // Tamanho de cada string igual.
            bool fans = false;
            vector <string> ss;
            string ans;
            for(int j = 0; j <= N -sizeS; j += sizeS){
                string temp = s.substr(j, sizeS);
                if(!fans){
                    fans = true;
                    ans = temp;
                }
                // cout << temp << ' ';
                sort(temp.begin(), temp.end());
                ss.push_back(temp);

            }
            // cout << endl;

            int equal = 1;
            for(int j = 1; j < i; j++){
                if(ss[j] == ss[j-1]) equal++;
                else break;
            }
            if(equal == i) return ans;
        }
    }

    return "*";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    string s;
    cin >> s;
    cout << solve(s,N) << endl;
    return 0;
}

// Accepted.