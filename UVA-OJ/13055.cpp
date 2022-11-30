// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    stack<string> S;
    while(t--){
        string op;
        cin >> op;

        string x;
        if(op == "Sleep"){
            cin >> x;
            S.push(x);
        }
        else if(op == "Kick"){
            if(!S.empty())
                S.pop();
        }
        else{
            if(!S.empty())
                cout << S.top() << '\n';
            else
                cout << "Not in a dream\n";
        }
        
    }
}

// AC.
