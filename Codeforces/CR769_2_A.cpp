#include <bits/stdc++.h>

using namespace std;

int main(void){

    int testcase;

    cin >> testcase;


    char string[102];
    int stringsize;
    int totalzeros = 0;
    int totalone = 0;

    int i,j;
    for (i = 0; i < testcase; i++){
        cin >> stringsize;
        cin >> string;

        // Special case, isn't possible to form strings greater than 1.
        if ((strlen(string) <= 2) && (string[0] != string[1])){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}