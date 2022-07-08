#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(void){

    // Declare
    string first;
    string second;
    int compare;

    // Receive.
    cin >> first;
    cin >> second;

    // Put both in lower case
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);

    // Compare :P
    compare = first.compare(second);

    // Output according with the result.
    if (compare == 0){
        cout << '0' << '\n';
    }
    else if (compare > 0){
        cout << '1' << '\n';
    }
    else{
        cout << "-1" << '\n';
    }


    return 0;
}

// Accepted Iagorr 05.02.2022
