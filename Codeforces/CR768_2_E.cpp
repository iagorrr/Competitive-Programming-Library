#include <bits/stdc++.h>

using namespace std;

int main(void){
    // Receiving inputs.
    int n;
    cin >> n;
    int array[n];
    int c[n] = {0};
    int i;
    for (i = 0; i < n; i++){
        cin >> array[i];
    }

    // Findig total sum from left to right
    int ileft, iright;
    int j;
    for (i = 0; i < n; i++){
        if (c[i] == 0){
            ileft = i;
            // Finding the right position.
            for (j = ileft+2; j < n; j++){
                if ((array[j] == array[ileft]) && (c[j] == 0)){ 
                    iright = j;
                    break;
                }
            }
            
            // All the numbers between the two that are bigger will be "painted"
            for (j = ileft+1; j < iright; j++){
                c[j] = 1;
            }
            
        }
        

    }
    // Just sum C.
    int totalsum = 0;
    for (i = 0; i < n; i++){
        totalsum = totalsum + c[i];
        c[i] = 0;

    }

    // Finding total sum from right to left. 
    for (i = n-1; i > -1; i--){
        if (c[i] == 0){
            iright = i;
            // Finding the left position.
            for (j = iright-2; j > 0; j--){
                if ((array[j] == array[iright]) && (c[j]== 0)){
                    ileft = j;
                    cout << "achou" << ileft << iright << endl;
                    break;
                }
            }

            // All the numbers ....
            for (j = ileft+1; j < iright; j++){
                c[j] = 1;
            }
        }
    }

    int totalsum2 = 0;
    for (i = 0; i <n; i++){
        totalsum2 = totalsum2 +c[i];
        if (c[i] == 1){
        }
    }

    if (totalsum > totalsum2){
        cout << totalsum << endl;
    }
    else{
        cout << totalsum2 << endl;
    }
}