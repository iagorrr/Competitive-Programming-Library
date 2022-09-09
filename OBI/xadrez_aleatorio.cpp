// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    
    int ans;
    if(t == 0){// o rei em cada uma das 2 posições.
        ans = n;
    }
    else if (t == 1){// indução
        ans = n*n - n;
    }
    else{
        /*
            baseado no seguinte racicínio :
            0 1 2 3 4 5 6 7 8 9 
            0                 9     1 8             Se o rei só pode ficar entre duas torres então
            0               8       2 15            verifica-se todas as posições que as torres
            0             7         3 21            podem assumir tais que exista um espaço entre elas
            0           6           4 26            isso pode ser verifado usando uma variação do
            0         5             5 30            two pointers.
            0       4               6 33            
            0     3                 7 35            Tendo que as posições das tuas torres é válida
            0   2                   8 36            basta saber que as as possíveis posições que o
            1               9     9 43              rei pode assumir é igual a distância entre as 
            1             8       10 49             duas torres, ou seja, cada uma das posições entre
            1           7         11 54             elas.
            1         6           12 58             
            1       5             13 61             
            1     4               14 63             
            1   3                 15 64
                2             9     16 70
                2           8       17 75
                2         7         18 79
                2       6           19 82
                2     5             20 84
                2   4               21 85
                3           9     22 90
                3         8       23 94
                3       7         24 97
                3     6           25 99
                3   5             26 100
                    4         9     27 104
                    4       8       28 107
                    4     7         29 109
                    4   6           30 110
                    5       9     31 113
                    5     8       32 115
                    5   7         33 116
                        6     9     34 118
                        6   8       35 119
                        7   9     36 120

        */
        ans = 0;
        for(int i = 0 ; i < n-1; ++i){
            for(int j = n-1; j > i+1; --j){
                ans += j-i-1;
            }
        }
    }
    cout << ans << endl;


    return 0;
}


// Aceito 100/100