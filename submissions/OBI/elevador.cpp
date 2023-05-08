#include <bits/stdc++.h>
#define endl '\n'
typedef long long int lli;

using namespace std;

int main(){
    lli N;
    cin >> N;

    vector <lli> V(N);
    for(lli i = 0; i < N; i++) cin >> V[i];
    sort(V.begin(), V.end());

    queue <lli> A;
    for(lli i = 0; i < N; i++){
        A.push(V[i]);
    }
    stack <lli> B;

    lli P, Q=0;
    while(!A.empty()){
        if(A.front() <= 8){
            B.push(A.front());
            A.pop();
        }
        else{
            if(!B.empty() && A.front() - B.top() <= 8){
                A.push(B.top());
                B.pop();
                B.push(A.front());
                A.pop();
            }
            else{
                cout << 'N' << endl;
                return 0;
            }
        }
    }
    cout << 'S' << endl;
    return 0;
}

// Accepted.