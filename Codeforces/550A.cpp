// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;

    bool conseguiu = false;
    // ABBA
    int l = 0;
    int r = S.size();
    bool AB = false;
    bool BA = false;
    while(l < S.size()-1){
        if(S[l] == 'A' && S[l+1] == 'B'){
            AB = true;
            break;
        }
        l++;
    }

    while(r > l+1+1){
        if(S[r] == 'A' && S[r-1] == 'B'){
            BA = true;
            break;
        }
        r--;
    }

    if(AB && BA){
        cout << "YES" << endl;
        return 0;
    }

    // BAAB
    AB = false;
    BA = false;
    l = 0;
    r = S.size();
    while(l < S.size()-1){
        if(S[l] == 'B' && S[l+1] == 'A'){
            BA = true;
            break;
        }
        l++;
    }
    while(r > l+1+1){
        if(S[r] == 'B' && S[r-1] == 'A'){
            AB = true;
            break;
        }
        r--;
    }

    if(AB && BA){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}