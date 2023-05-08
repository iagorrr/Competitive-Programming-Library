#include <bits/stdc++.h>

using namespace std;
/*====================================================================================================*/
int main(void){
    int temp;
    int cinco = 0;
    int sete =0;
    for(int i = 0; i < 3; i ++){
        cin >> temp;
        if(temp == 5) cinco++;
        if(temp == 7) sete++;
    }

    if(cinco == 2 && sete ==1) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}