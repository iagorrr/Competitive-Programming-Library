// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s){
    istringstream i(s);
    
    int x;
    vector<int> a;
    while(i >> x){
        a.push_back(x);
    }
    return a;
}
bool check(vector<int> a){
    for(int i = 0; i < a.size()-1; ++i)
        if(a[i] != i+1)
            return false;

    return true;
}
void solve(string s){
    // cout << "=====================================\n";
    // to put an element at top flip his position and then the entire stack.
    vector<int> o = split(s);
    vector<int> ans;

    // put the largest value until now at the bottom.
    vector<int> m = o;
    int n = o.size();
    for(int i = n-1; i >= 0; --i){
        // for(auto x : m)
        //     cout << x << ' ';
        // cout << '\n';
        int mpos = i;
        for(int j = i-1; j >= 0; --j){
            if(m[j] > m[mpos]){
                mpos = j;
            }
        }

        // the largest is in the correct position already.
        if(mpos == i) continue;

        // put the largest at top, so we can move it to whatever position.
        if(mpos != 0){
            // cout << "p1 " << mpos << '\n';
            ans.push_back(n-mpos);
            reverse(m.begin(), m.begin()+mpos+1 );
        }

        // with the largest one at the top put it at the respective bottom.
        // cout << "p2 " << i << '\n';
        ans.push_back(n-i);
        reverse(m.begin(), m.begin()+i+1);
    }

    // output the original.
    for(auto x : o)
        cout << x << ' ';
    cout << '\n';

    // output the flips.
    for(auto x : ans)
        cout << x << ' ';
    cout << "0\n";
    
}
int main(){
    string s;
    while(getline(cin, s)){
        solve(s);
    }


    return 0;
}
// AC.
