#include <bits/stdc++.h>

using namespace std;
vector <int> posicoesBorradas;
vector <string> palavrasSubs;
int N, M, K;
string s;


bool hashIn(string s){
    for(auto it = s.begin(); it != s.end(); ++it) if(*it == '#') return false;
    return true;
}

int main(){
    cin >> N >> M >> K;
    cin >> s;
    for(int i = 0; i < M; ++i){ 
        string temp;
        cin >> temp;
        palavrasSubs.push_back(temp);
    }
    int P;
    cin >> P;


    // Mapear as posições  borradas.
    for(int i = 0; i < N; ++i){
        if(s[i] == '#'){
            // cout << i << endl;
            posicoesBorradas.push_back(i);
        }
    }


    return 0;
}

// Não saiu.