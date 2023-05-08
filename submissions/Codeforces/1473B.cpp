#include <bits/stdc++.h>

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        string A;
        string B;

        cin >> A;
        cin >> B;
        string finalA = A;
        string finalB = B;
        while(finalA.size() != finalB.size()){
            // cout << "A: " << finalA << endl;
            // cout << "B: " << finalB << endl;
            if(finalA.size() < finalB.size()){
                finalA += A;
            }
            else if (finalA.size() > finalB.size()){
                finalB += B;
            }
        }

        bool valid = true;
        for(int i = 0; i < finalA.size(); i++){
            if(finalA[i] != finalB[i]){
                valid = false;
                break;
            }
        }
        if(valid) cout << finalA << endl;
        else cout << -1 << endl;
        
    }

    return 0;
}