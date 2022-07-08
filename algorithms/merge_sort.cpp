#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

void merge_sort(vi &A);

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vi mainVector(n);
    for(int i = 0; i < n; i++){
        cout << "v[" << i << "]: ";
        cin >> mainVector[i];
    }

    merge_sort(mainVector);

    for(int i = 0; i < n; i++){
        cout << "v[" << i << "] = " << mainVector[i] << endl;
    }

    return 0;
}

void merge_sort(vi &A){
    int n = A.size();

    if(n < 2){// Done with split.
        return;
    }
    else{// Split and merge.
        int m = n/2;

        // Create left sub array.
        vi lA;
        for(int i = 0; i < m; i ++){
            lA.push_back(A[i]);
        }

        // Create right sub array.
        vi rA;
        for(int i = m; i < n; i++){
            rA.push_back(A[i]);
        }

        // Sort the left.
        merge_sort(lA);

        // Sort the right.
        merge_sort(rA);

        // Now that are sorted  merge it into the main one.
        int iL = 0;
        int iR = 0;
        for(int i = 0; i < n; i++){
            if(iL == lA.size()){// left vector is done.
                A[i] = rA[iR++];
            }
            else if(iR == rA.size()){// Right vector is done.
                A[i] = lA[iL++];
            }
            else if(lA[iL] <= rA[iR]){
                A[i] = lA[iL++];
            }
            else{
                A[i] = rA[iR++];
            }
        }
    }

}