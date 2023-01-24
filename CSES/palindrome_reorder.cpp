#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    map<char,int> hist;
    for(auto c : s) hist[c]++;

    int odd = 0;
    for(auto [c, cc] : hist)
        if (cc&1) odd++;

    if(odd > 1) return "NO SOLUTION";
    if(odd == 1){
    int qtd;
    char q;
    string ans;
    for(auto [c, cc] : hist)
    {
        if(cc&1)
        {
            qtd = cc;
            q = c;
        }
    }
        ans.insert(0, qtd, q);
    }

    for(auto [c, cc] : hist){
        ans.insert(0,cc/2,c);
        ans.insert(ans.size()-1, cc/2, c);
    }
    return ans;
}

int main()
{
    string s; cin >> s;

    cout << solve(s) << '\n';
}
