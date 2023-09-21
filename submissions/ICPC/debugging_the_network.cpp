// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;


int check(int curk, int maxk, string s){
    int cursoma = 0;

    int pow = 1;
    for(int i = s.size()-1; i >= 0; --i) {
        cursoma = cursoma + (s[i]-'0')*pow;
        //cout << "s: " << s << " curosma: " << cursoma << " i: " << i << " curk: " << curk << " maxk: " << maxk << '\n';
        if(cursoma + curk > maxk) return -1;
        pow *= 10;
    }

    return cursoma;
}
string solve(string s, int k){

    vector<pair<char, string>> parsed1;
    string curnum="";
    bool opennum = false;
    for(auto c : s) {
        if(c <= '9' and c >= '0') {
            opennum = true;
            curnum = curnum+c;
        }
        else {
            if(opennum) {
                parsed1.push_back({c, curnum});
                curnum="";
                // cout << "c: " << c.first << " qtd: " << c.second << '\n';
                opennum = false;
            }
            else {
                parsed1.push_back({c, "1"});
            }
        }
    }

    string ans = "";
    for(pair<char, string> c : parsed1) {
        int qtd = check((int)ans.size(), k, c.second);
        if(qtd == -1) {
            return "unfeasible";
        }
        ans += string(qtd, c.first);
        // cout << "c: " << c.first << " qtd: " << c.second << '\n';
    }
    return ans;
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        int k; cin >> k;

        cout << solve(s, k) << '\n';
    }
}

// AC ,strings, implementation
