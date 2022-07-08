#include <bits/stdc++.h>

using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void recursive_permutation(char *str, int l, int r){
    if(l == r){ // Final swap, last branch.
        cout << str << endl;
    }
    else{
        int i;
        for(i = l; i <= r; i++){
            swap((str+l), (str+i));
            recursive_permutation(str, l+1, r);
            swap((str+l), (str+i));
        }
    }
}

int main(){
    char str[] = "ABA\0";
    recursive_permutation(str, 0, strlen(str)-1);
}