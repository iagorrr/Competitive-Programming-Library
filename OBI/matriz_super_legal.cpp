#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int L, C;
    cin >> L >> C;

    lli A[L][C];
    for(int i = 0; i < L; i++)
        for(int j = 0; j < C; j++)
            cin >> A[i][j];

    lli ans = 0;
    lli tempAns;
    lli l2, c2;
    for(int l1 = 0; l1 < L-2; l1++){
        for(int c1 = 0; c1 < C-2; c1++){
            l2 = 0;
            tempAns = 0;
            while(l2 + l1 < L){
                c2 = 0;
                while(c2+c1 < C){
                    if(A[l1][c1] + A[l2][c2] <= A[l1][c2] + A[l2][c1]){
                        tempAns++;
                    }
                    c2++;
                }
                l2++;
            }
            ans = max(tempAns, ans);
        }
    }

    cout << ans << endl;
    return 0;
}