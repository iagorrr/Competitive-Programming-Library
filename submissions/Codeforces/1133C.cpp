#include <bits/stdc++.h>

using namespace std;

// Exercise based in two pointers.
typedef long long int lli;

int main(){
    lli V;
    cin >> V;

    vector <lli> values(V);

    for(lli i = 0; i < V; i++){
        cin >> values[i];
    }
    sort(values.begin(), values.end());

    
    return 0;
}