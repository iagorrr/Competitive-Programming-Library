#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string fullInput;
    cin >> fullInput;

    map <char, map<string, bool>> jafoi;

    int totalC = 0;
    int totalE = 0;
    int totalU = 0;
    int totalP = 0;

    for(int i = 0; i < fullInput.size(); i += 3) {
        string numeroCartaChar;

        numeroCartaChar.push_back(fullInput[i]);
        numeroCartaChar.push_back(fullInput[i+1]);

        char naipe = fullInput[i+2];

        if(jafoi[naipe][numeroCartaChar]){
            switch(naipe){
                case('C'):
                    totalC=-9999;
                break;
                case('E'):
                    totalE=-9999;
                break;
                case('U'):
                    totalU=-9999;
                break;
                case('P'):
                    totalP=-9999;
                break;
            }
        }
        else{
            switch(naipe){
                case('C'):
                    totalC++;
                break;
                case('E'):
                    totalE++;
                break;
                case('U'):
                    totalU++;
                break;
                case('P'):
                    totalP++;
                break;
            }
            jafoi[naipe][numeroCartaChar] = true;
         }
    }

    if(totalC >= 0)cout <<13-totalC<< endl;
    else cout << "erro" << endl;

    if(totalE >= 0)cout <<13-totalE<< endl;
    else cout << "erro" << endl;

    if(totalU >= 0)cout <<13-totalU<< endl;
    else cout << "erro" << endl;

    if(totalP >= 0)cout <<13-totalP<< endl;
    else cout << "erro" << endl;
    return 0;
}

// 100/100
