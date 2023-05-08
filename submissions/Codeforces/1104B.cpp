// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// based on how may movments was possible.
string solve(string s){
    
    stack<char> aux;
    ll totalmoves=0;
    for(auto c : s){
        
        if(aux.empty() or aux.top() != c){
            aux.push(c);
        }
        else if(!aux.empty() and aux.top() == c){
            totalmoves++;
            aux.pop();
        }
    }
    
    return (totalmoves&1) ? "Yes" : "No";
}
int main(){
    string s;
    cin >> s;


    cout << solve(s) << '\n';

    return 0;
}

// Accepted.