#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;

    int i;
    char word[102];
    for (i = 0; i < n; i++){
        cin >> word;
        if (strlen(word) > 10){
            cout << word[0] << strlen(word)-2 << word[strlen(word)-1] << endl;
        }
        else{
            cout << word << endl;
        }
    }
}

// Accepted Iagorrr 29/01/2022