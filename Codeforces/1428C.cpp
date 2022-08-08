// iagorr ;) O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string shrink(vector<bool> c, string s){
    string ans;

    for(int i = 0; i < s.size(); ++i) if(c[i]) ans.push_back(s[i]);

    return ans;
}


int solve(string s){
    // c works like a stack, if there is some element not removed wait until the next 'B' to me removed...
    int c = 0;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'B' and c!=0) c--;
        else c++;
    }

    return c;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
}

// Accepted.
