// iagorrr :)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    int ans = -1;    
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == 'a') ans = i;

    cout << (ans == -1 ? -1 : ans+1) <<'\n';
    return 0;
}

// AC.