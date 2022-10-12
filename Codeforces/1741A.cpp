#include <bits/stdc++.h>
using namespace std;


string solve(string a, string b){
    map<char, int> v;
    v['S'] = 1;
    v['M'] = 2;
    v['L'] = 3;

    if(v[a.back()] > v[b.back()]) return ">";
    else if (v[a.back()] < v[b.back()]) return "<";
    else{
        if(a.back() == 'S'){
            if(a.size() == b.size()) return "=";
            else if(a.size() > b.size()) return "<";
            else return ">";
        }

        if(a.back() == 'L'){
            if(a.size() == b.size()) return "=";
            else if(a.size() > b.size()) return ">";
            else return "<";
        }

        return "=";
    }
}
int main(){
    int t;
    cin >> t;

    while(t--){
        string a, b;
        cin >> a >> b;

        cout << solve(a, b) << '\n';
    }
}