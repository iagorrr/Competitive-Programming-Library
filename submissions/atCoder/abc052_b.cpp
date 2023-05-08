// iagorrr ;) O(N)
#include <bits/stdc++.h>

using namespace std;

int solve(string s){
    int ans = 0;
    int x = 0;
    for(auto i = s.begin(); i < s.end(); i++){
            x = *i == 'I' ? x +1 : x -1;
            ans = max(x, ans);
     }

    return ans;
}
int main(){
    int N;
    cin >> N;

    string s;
    cin >> s;

    cout << solve(s) << endl;
    return 0;
}

// AC
