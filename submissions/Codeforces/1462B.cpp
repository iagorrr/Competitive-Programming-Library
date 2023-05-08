// Iagorr ;)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

string vintevinte = "2020";
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
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    int N;
    string S;
    for(int t = 0; t < T; t++){
        cin >> N;
        cin >> S;
        if (hasXremovingInOrder(S, vintevinte)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}

// Wrong answer test 2
