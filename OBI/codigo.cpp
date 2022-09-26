// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

/*
    Determinar se alguma das s strings é subsequencia da contatenação de duas  outras strings
    s_a, s_b.

    * a <= b.
*/
inline bool issubstr(const string p, const string s){// determina se p é substring de s.

    for(int i = 0; i < s.size()-p.size()-1; ++i){
        bool check = true;
        for(int j = 0; j < p.size(); ++j){
            if(s[i+j] != p[j]){
                check = false;
                break;
            }
        }

        if(check) return true;
    }


    return false;
}
string solve(const vector<string> ss, int n){
    if(n == 1) return "ok";

    for(int i = 0; i < n; ++i){
        
        // todas as combinações dois a dois de a ,b.
        for(int j = 0; j < i; ++j){
            for(int k = j; k < i; ++k){
                string s = ss[j]+ss[k];
                
                if(issubstr(ss[i], s)) return ss[i];

                s = ss[k] + ss[j];
                if(issubstr(ss[i], s)) return ss[i];
            }
        }
    }

    // passou em todos os caos é válido.
    return "ok";
}
int main(){
    int n;
    cin >> n;
    vector<string> ss(n);
    for(int i = 0; i < n; ++i) cin >> ss[i];

    cout << solve(ss, n) << '\n';
    


    return 0;
}

// 40/100 TLE