// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    unordered_set<string> check;
    vector<string> ans;

    // mini bfs.
    queue<string> q;

    ans.push_back(s);
    check.insert(s);
    q.push(s);


    // h depois das vogais que já tinha h mesmo.
    set<char> vogais {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < (int)s.size()-1; ++i){
        if(vogais.count(s[i])){
            string temp;
            temp = s.substr(0, i+1) + 'h' + s.substr(i+1);

            if(!check.count(temp)){
                check.insert(temp);
                ans.emplace_back(temp);
                q.push(temp);
            }
        }
    }

    // dfs bro.
    while(!q.empty()){
        string current = q.front(); q.pop();

        // Adicionar toda posicao possivel.
        for(int i = 0; i < (int)current.size()-1; ++i){
            if(vogais.count(current[i]) and current[i+1] != 'h'){
                string temp;
                temp = current.substr(0, i+1) + 'h' + current.substr(i+1);

                if(!check.count(temp)){
                    check.insert(temp);
                    ans.push_back(temp);
                    q.push(temp);
                }
            }
        }

        // vogal na ultima pos.
        if(vogais.count(current.back())){
            string temp = current;
            temp.push_back('h');
            if(!check.count(temp)){
                    check.insert(temp);
                    ans.push_back(temp);
                    q.push(temp);
                }

        }
    }

    // PRINTAAAA.
    sort(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    solve(s);
}

// Accepted.
