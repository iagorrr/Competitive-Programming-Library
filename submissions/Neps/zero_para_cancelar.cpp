#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>> N;

    vector <int> valores;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        valores.push_back(temp);
    }

    list <int> valoresSomar;
    for(int i = 0; i < N; i++){
        if(valores[i] != 0){
            valoresSomar.push_front(valores[i]);
        }
        else{
            valoresSomar.pop_front();
        }
    }

    int answer =0;
    while(!valoresSomar.empty()){
        answer += valoresSomar.front();
        valoresSomar.pop_front();
    }

    cout << answer << endl;
}

// 100/100
