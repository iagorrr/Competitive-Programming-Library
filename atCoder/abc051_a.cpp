// iagorrr ;) O(N)
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char temp;
    do{
        temp = getc(stdin);
        if(temp != ',') cout << temp;
        else cout << ' ';
    }while(temp != '\n');
    cout << endl;
    return 0;
}