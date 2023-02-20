// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

set<string> solve(string f){
    stringstream is {f};

    string t;
    set<string> vans;
    while(is >> t){
        deque<char>  dq{t.begin(), t.end()};

        // remove non letters.
        while(!dq.empty() and !isalpha(dq.back()) and dq.back() != '-') dq.pop_back();
        while(!dq.empty() and !isalpha(dq.front()) and dq.front() != '-') dq.pop_front();

        string ans;
        while(!dq.empty()){
            if(!isalpha(dq.front()) and dq.front() != '-'){
                // to lower bound.
                for(auto &x : ans)
                    x = (char)tolower(x);

                if(!ans.empty() and ans != "\n") vans.insert(ans);

                dq.pop_front();
                ans.clear();
                continue;
            }
            ans.push_back(dq.front());
            dq.pop_front();
        }

        // to lower bound.
        for(auto &x : ans)
            x = (char)tolower(x);
        
        if(!ans.empty() and ans != "\n"){
            vans.insert(ans);
        }
    }

    return vans;
}

int main(){ 
    fastio
    string l;
    string f;
    getline(cin, l);
    f += l;
    while(getline(cin, l)){
        
        if(f.back() == '-'){
            f.pop_back();
            f += l;
        }
        else{
            f+= ' ' + l;
        }
    }
    // cout << f << '\n';
    set<string> ans = solve(f);

    vector<string> finalans;
    for(auto x : ans)
        finalans.push_back(x);

    for(int i = 0; i < (int)finalans.size(); ++i)
        cout << finalans[i] << '\n';

    return 0;
}
// AC.

