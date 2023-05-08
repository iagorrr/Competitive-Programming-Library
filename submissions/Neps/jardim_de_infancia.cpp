#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long int lli;
typedef unsigned long long int ulli;


#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define PI 3.141593

ulli nop(ulli number);
ulli hibit(ulli x);
bool isPalindrome(string s);
bool validBracket(string b);
lli sumdigits(lli x);
bool hasXremovingInOrder(string S, string X);
lli productScalar(pair <int, int> B, pair <int, int> A);
lli normSquareVector(pair <int, int>);
lli colinearThreePoints(pair <int, int> A, pair<int, int> B, pair<int,int> C);
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B);

vector <pair<int, int>> points(7);
bool solve() {
    // O ângulo p1,p2,p3 é agudo em p1. basta verificar se os sinais são diferentes.
    pair <int, int> V1;
    V1.first = points[1].first - points[0].first;
    V1.second = points[1].second - points[0].second;
    pair <int, int> V2;
    V2.first = points[2].first - points[0].first;
    V2.second = points[2].second - points[0].second;
    lli cima = productScalar(V1, V2);
    lli baixo = (normSquareVector(V1)*normSquareVector(V2));
    if(cima < 0 && baixo > 0 || cima > 0 && baixo < 0)  return false;


    // os segmentos p1p2 e p1p3 tem o mesmo comprimento.
    if(normSquareVector(V1) != normSquareVector(V2)) return false;


    // Os pontos p2, p3, p4 e p5 são colineares.
    if(colinearThreePoints(points[1], points[2], points[3]) != 0 || colinearThreePoints(points[2], points[3], points[4]) != 0) return false;

    // Os pontos médios dos segmentos p2p3, e p4p5 são coincidentes.
    V1 = averagePoint(points[1], points[2]);
    V2 = averagePoint(points[3], points[4]);
    if(V1.first != V2.first || V1.second != V2.second) return false;

    // O segmento p2p3 tem comprimento maior que o p4p5.
    V1.first = points[2].first - points[1].first;
    V1.second = points[2].second - points[1].second;
    V2.first = points[4].first - points[3].first;
    V2.second = points[4].second - points[3].second;
    if(normSquareVector(V1) <= normSquareVector(V2)) return false;

    // Os segmentos p4p6 e p5p7 são perpendiculares ao segmento p2p3.
    V2.first = points[5].first - points[3].first;
    V2.second = points[5].second - points[3].second;
    if(productScalar(V1, V2) != 0) return false;
    V2.first = points[6].first - points[4].first;
    V2.second = points[6].second - points[4].second;
    if(productScalar(V1, V2) != 0) return false;

    // Os segmentos p4p6 e p5p7 tem o mesmo comprimento.
    V1.first = points[5].first - points[3].first;
    V1.second = points[5].second - points[3].second;
    if(normSquareVector(V1) != normSquareVector(V2)) return false;

    return true;
}
/*====================================================================================================*/
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 7; i++){
        cin >> points[i].first >> points[i].second;
    }

    auto ans = solve() ? "S" : "N";
    cout << ans << endl;
    return 0;
}
/*====================================================================================================*/

// Function to return the ~X.
ulli nop(ulli number){
    return (~number)^(ULLONG_MAX<<(hibit(number)));
    
} 

// Function to return the highest bit position of a number.
ulli hibit(ulli x){
    return (lli)log2(x)+1;
}

// Function to verify if a given string is a palindrome or not.
bool isPalindrome(string s){
    string aux = s;
    reverse(aux.begin(), aux.end());

    LOOP(i, 0, s.size()){
        if(aux[i] != s[i]){
            return false;
        }
    }

    return true;
}

// Function to verify if a string with brackets is valid or not.
bool validBracket(string b){
    stack <char> verify;

    LOOP(i, 0, b.size()){
        if(b[i] == ')' && verify.top() == '('){
            verify.pop();
        }
        else{
            verify.push(b[i]);
        }
    }

    if(!verify.empty()){
        return false;
    }
    else{
        return true;
    }
}

// Function to return the sum of digits of a number.
lli sumdigits(lli x){
    lli rest;
    lli result = 0;

    do{
        rest = x % 10;
        result += rest;
        x = x/10;
    }while(x > 0);

    return result;
}

// to find if there is an string X in S by removing in blocks.
bool hasXremovingInOrder(string S, string X){
    ulli maskRemove = S.size() - X.size();
    for(ulli l = 0; l < S.size(); l++){
        vector <bool> mark(S.size(), true);
        ulli r = 0;
        while(r+l < S.size() && r < maskRemove){
            mark[r+l] = false;
            r++;
        }   

        string aux;
        for(ulli i = 0; i < S.size(); i++){
            if(mark[i]) aux.push_back(S[i]);
        }
        // cout << aux << endl;
        if(aux == X) return true;
    }

    return false;
}

// to find the scalar product between two vectors.
lli productScalar(pair <int, int> A, pair <int, int> B){
    return A.first * B.first + A.second * B.second;
}

// to find the square of the norm of a vector.
lli normSquareVector(pair <int, int> A){
    return A.first*A.first + A.second*A.second;
}

// returns the value of the determinant given three points.
lli colinearThreePoints(pair <int, int> A, pair<int, int> B, pair<int,int> C){
    return (-1)*C.first*B.second + (-1)*C.second*A.first + (-1)*B.first*A.second + A.first*B.second + A.second*C.first + B.first*C.second;
}

// Returns the average point of two given points.
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B){
    return {(A.first+B.first)/2, (A.second+B.second)/2};
}

// WA.
