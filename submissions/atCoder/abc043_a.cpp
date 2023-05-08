#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 0;
    int i = 1;
    while(i < N){
        ans += i;
        i++;
    }
    ans += i;
    cout << ans << endl;
    return 0;
}