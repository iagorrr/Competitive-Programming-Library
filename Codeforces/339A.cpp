#include <bits/stdc++.h>

using namespace std;


// Macros/templates
#define LOOP(I, S, E) for(int I = S; I < E; I++)
#define SWAP(A, B) A ^= B ^= A ^= B

template<typename... T>
void readInput(T&... args){
	((cin >> args), ...);
}



int main(void){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

    // Declare.
    string sum;

    // Receive.
    cin >> sum;
    
    // remove all '+'
    sum.erase(remove(sum.begin(), sum.end(), '+'), sum.end());

    // sort the numbers.
    sort(sum.begin(), sum.end());

    // show each number with a '+' between.
    cout << sum[0];
    LOOP(i, 1, sum.length()){
        cout << '+' << sum[i];
    }
    cout << '\n';
    
    return 0;
}

// Accepted Iagorrr 05.02.2022
