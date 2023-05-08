// iagorrr O(n)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    map<char, string> S;

    cin >> S['A'];
    cin >> S['B'];
    cin >> S['C'];

    
    reverse(S['A'].begin(), S['A'].end());
    reverse(S['B'].begin(), S['B'].end());
    reverse(S['C'].begin(), S['C'].end());
    

    string current = S['A'];
    char c = 'A';
    char n;
    while(!S[c].empty()){
        n = toupper(S[c].back());
        S[c].pop_back();
        c = n;
    }

    cout << c << endl;
    

    return 0;
}

// Accepted.