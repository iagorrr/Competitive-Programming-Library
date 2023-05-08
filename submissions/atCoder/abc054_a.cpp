// iagorrr ;) O(1)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    short int A, B;

    cin >> A >> B;

    if(A == B){
        cout << "Draw" << endl;
    }
    else if(A != 1 and B != 1){
        cout << (A > B ? "Alice" : "Bob") << endl;
    }
    else{
        cout << (A == 1 ? "Alice" : "Bob")  << endl;
    }

    return 0;
}

// Accepted.