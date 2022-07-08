#include <bits/stdc++.h>
// This solution consist in let the largest numbers in one arraye.

using namespace std;

int main(void){
    int test;

    cin >> test;

    int i, j;
    int lenArray, temp;
    int maxA, maxB;
    for (i = 0; i < test; i++){

        // Receiving array.
        cin >> lenArray;
        int arrayA[lenArray];
        int arrayB[lenArray];
        for (j = 0; j < lenArray; j++){
            cin >> arrayA[j];
        }
        for (j = 0; j < lenArray; j++){
            cin >> arrayB[j];
        }

        // Put all the larges values in the first array.
        for (j = 0; j < lenArray; j++){
            if (arrayA[j] < arrayB[j]){
                temp = arrayA[j];
                arrayA[j] = arrayB[j];
                arrayB[j] = temp;
            }
        }
        
        // find the max in each array.
        maxA = arrayA[0];
        maxB = arrayB[0];
        for (j = 0; j < lenArray; j++){
            if (arrayA[j] > maxA){
                maxA = arrayA[j];
            }

            if (arrayB[j] > maxB){
                maxB = arrayB[j];
            }
        }

        cout << maxA*maxB << endl;
    }
}
