// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

char solve(vector<int> bolas){

    do{
        bool check = true;
        for(int i = 1; i < 8; ++i){
            if(bolas[i] == bolas[i-1]){
                check = false;
                break;
            }
        }
        if(check) return 'S';
    }while(next_permutation(bolas.begin(), bolas.end()));

    return 'N';
}
int main(){
    vector<int> bolas(8);
    for(auto &x : bolas) cin >> x;
    cout << solve(bolas) << '\n';
    return 0;
}

// 60/100 WA.