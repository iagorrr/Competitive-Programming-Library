#include <bits/stdc++.h>

using namespace std;

int main(void){

    // Receiving inputs.
    int n, k;
    cin >> n >> k;
    k = k -1;

    int i;
    int total=0;
    int array[n];
    for (i = 0; i < n; i++){
        cin >> array[i];
    }

    // Counting how many are bigger than the others.
    for (i = 0; i < n; i++){
        if ((array[i] >= array[k]) && (array[i] > 0)){
            total += 1;
        }
    }

    // Just showing the output.
    cout << total << endl;
}

// Accepted Iagorr 01.02.2022
