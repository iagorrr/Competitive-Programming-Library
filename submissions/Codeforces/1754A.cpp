// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;


        string s;
        cin >> s;

        int q = 0;
        for (auto c : s){
            if(c == 'A'){
                q--;
                if(q < 0) q = 0;
            }
            else{
                q++;
            }
        }

        cout << (q==0 ? "Yes" : "No") << '\n';
    }

    return 0;
}

// Accepted.