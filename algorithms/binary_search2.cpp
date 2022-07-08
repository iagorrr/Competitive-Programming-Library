/*
    Second version using a 'check()' function, that can be changed according to the parameters you want,
    and also looking for the lower value possbile.
*/
#include <bits/stdc++.h>
using namespace std;

bool check(int val);
int binary_search2(vector <int> A);

int main(){

    return 0;
}

// The value of 'x' and if is bigger or lower need to be according to your need.
int x;
bool check(int val){
    return val < x;
}

// Returns the position of the lower value possible.
int binary_search2(vector <int> A){
    int l = 0;
    int r = A.size();
    int mid;
    while(r > l+1){// While our interval is larger than 2.
        int mid = (l+r)/2;

        if(check(A[mid])){// If the mid is valid, we will look at the elements at left, minors
            r = mid;
        }
        else{// Isn't valid, so look at the bigger.
            l = mid + 1;
        }
    }

    // Now the answer is in the 'l' or 'r' position so we should check if the 'l' is valid as we want the lower
    int answer = r;
    if(check(A[l])){
        answer = l;
    }

    return answer;
}

/*
    It can be easly changed to find the lower value.
*/
