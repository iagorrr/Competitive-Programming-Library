
#include <bits/stdc++.h>

using namespace std;

int main(){
    string A;
    string B;
    cin >> A >> B;

    map <char, int> tem;

    for(int i = 0; i < A.size(); i++){
        tem[A[i]]++;
        if(B[i] != '*') tem[B[i]]--;
    }

    char ans = 'S';
    for(auto q : tem){
        if(q.second < 0){
            ans = 'N';
            break;
        }
    }

    cout << ans << endl;
    return 0;

}

// 100/100.
