#include <bits/stdc++.h>

using namespace std;
/*====================================================================================================*/
int main(void){
    vector <string> S;
    int N, L;
    cin >> N >> L;

    while(N--){
        string temp;
        cin >> temp;

        S.push_back(temp);
    }

    sort(S.begin(), S.end());
    for(int i =0 ; i < S.size(); i++){
        cout << S[i];
    }
    cout << endl;
	return 0;
}