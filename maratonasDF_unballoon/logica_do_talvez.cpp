// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


char op(char a, char b, char op){
    if(b == 'T'){
        char t = a;
        a = b;
        b = t;
    }
    if(a == 'T' and b == 'T') return 'T';
    if(op == '&'){
        if(a == 'T' and b == 'F') return 'F';
        if(a == 'T' and b == 'V') return 'T';
        if(a == 'F' or b == 'F') return 'F';

        return 'V';
    }
    else{
        if(a == 'T' and b == 'F') return 'T';
        if(a == 'T' and b == 'V') return 'V';
        if(a == 'V' or b == 'V') return 'V';

        return 'F';
    }
}
void solve(string s){
    if(s.size() == 1){
        cout << s << '\n';
        return;
    }

    char ans;
    string f;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '&'){
            char prev = f.back();

            f.pop_back();

            f.push_back(op(prev, s[i+1], '&'));
            ++i;
        }
        else
            f.push_back(s[i]);
    }

    if(f.size() == 1){
        cout << f << '\n';
        return;
    }
    char c = f[0];
    for(int i = 0; i < f.size(); ++i){
        if(f[i] == '|' or f[i] == '&'){
            c = op(c, f[i+1], f[i]);
        }
    }
    
    cout << c<< '\n';
}
int main(){
    ll n;
    cin >> n;
    

    string s;
    for(int i = 0; i < n*2 -1; ++i){
        char c;
        cin >> c;
        s += c;
    }

    solve(s);
    return 0;
}

// Accepted.
