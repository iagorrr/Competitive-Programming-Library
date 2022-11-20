#include <bits/stdc++.h>

using namespace std;

int main(){
    int M;
    int A;
    int B;
    int C;

    cin >> M >> A >> B;

    C = M - A -B;

    A = max(A,B);
    A = max(A, C);

    cout << A << endl;

    return 0;
}

// Não corrigido ainda