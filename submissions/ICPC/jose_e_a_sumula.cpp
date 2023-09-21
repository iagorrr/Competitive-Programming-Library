
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(ll min, string tempo){
    char t = tempo[0];
    string ans;

    if(t == '1'){
        if(min <= 45){
            ans = to_string(min);
        }
        else{
            ans = to_string(45) + '+' + to_string(min%45);
        }
    }
    else {
        if(min <= 45){
            ans = to_string(45 + min);
        }
        else {
            ans = to_string(90) + '+' + to_string(min%45);
        }
    }

    return ans;
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll min;
        string tempo;
        cin >> min >> tempo;

        cout <<solve(min, tempo) << '\n';
    }

    return 0;
}

// Accepted.
