/*
    Given a string returns a value for the respective hash.
    Not the most eficientt way to make the hash of a string but good to start.
    Aim to remove the time necessary to compare one string with another when mapping.

    in this case considering :
    a b c d e f g h i j k l m n o p q r s t u v x y z
    1 2 3 4 5 6 7 8 9 ...

    chance to get a colision 1/q

    ideal number to q : 10^9 + 7
    idel number to p: greater than the alphabet or the given set.

    reference : https://github.com/edsomjr/TEP/blob/master/Strings/slides/hashes/hashes.pdf

*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll hashString(const string &S, ll p = 1000000007, ll q = 53){
    ll ans = 0;
    for(auto it = S.rbegin(); it != S.rend(); ++it){// Goes from the last character to the first.
        ans = (ans * p) % q;
        ans = (ans + (*it -'a'+1)) % q;
    }

    return ans;
}


int main(){
    ll p = 1000000007;
    ll q = 31;
    string S;

    int T;
    cin >> T;
    while(T--){
        cin >> S;
        cout << hashString(S, p, q) << endl;
    }
    return 0;
}
