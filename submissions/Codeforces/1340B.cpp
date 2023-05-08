// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int l = 0;
    int r = s.size()-1;
    while(s[l] == s[r] && l < r){
        l++;
        r--;
    }

    return l >= r ? true : false;
}

int main(){
    int n, m;

    cin >> n >> m;

    vector<string> vs(n);
    for(int i = 0 ; i < n; ++i) cin >> vs[i];

    // Test every possible combination.
    vector <pair<string, string>> pp; // palindromes pairs
    vector <string> p; // palindrome lonely :(
    vector <bool> check(n, true); // strings already used.

    for(int i = 0; i < n; ++i){
        if(!check[i]) continue;
        
        bool pair = false;
        int j;
        for(j = 0; j < vs.size(); ++j){
            if(j != i && check[j] && isPalindrome(vs[i]+vs[j])){
                pair = true;
                break;
            }
        }

        if(pair){
            pp.push_back({vs[i], vs[j]});
            check[i] = false;
            check[j] = false;
        }
        else{
            if(isPalindrome(vs[i])){
                p.push_back(vs[i]);
                check[i] = false;
            }
        }
    }

    // for(int i = 0; i < p.size(); ++i){cout << p[i] << endl;} 
    // for(int i = 0 ; i < pp.size(); ++i){cout << "(" << pp[i].first << ", " << pp[i].second << ")" << endl;}

    list <string> ans;
    int anss = 0;
    if(p.size()){ ans.push_back(p[0]); anss+=m;}
    for(int i = 0; i < pp.size(); ++i) { ans.push_back(pp[i].first); ans.push_front(pp[i].second); anss += (m*2);}

    cout << anss << endl;
    while(!ans.empty()){ cout << ans.back(); ans.pop_back();} cout << endl;
    

    return 0;
}

// Accepted.