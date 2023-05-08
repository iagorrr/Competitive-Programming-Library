// iagorrr
#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long int lli;
typedef unsigned long long int ulli;

#define LOOP(I, S, E) for (lli I = S; I < E; I++)
#define LOOPIN(i, E, V)                                                        \
  for (lli i = 0; i < E; i++) {                                                \
    cin >> V[i];                                                               \
  }
#define LOOPOUT(i, E, V)                                                       \
  for (lli i = 0; i < E; i++) {                                                \
    cout << V[i] << endl;                                                      \
  }
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

ulli nop(ulli number);
ulli hibit(ulli x);
bool isPalindrome(string s);
lli sumdigits(lli x);
lli productScalar(pair<int, int> B, pair<int, int> A);
lli normSquareVector(pair<int, int>);
lli colinearThreePoints(pair<int, int> A, pair<int, int> B, pair<int, int> C);
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B);

void outputFormated(string S, int lineSize);
const string caeserAlphabet{" ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

pair <lli, lli> solve(lli H, lli M, lli aH, lli aM){
    pair <lli, lli> ans;


    if(H == aH){
        if(M == aM){
          ans.first = 0;
          ans.second = 0;
        }
        else if(M < aM){
          ans.first = 0;
          ans.second = aM - M;
        }
        else{
          ans.first = 23;
          ans.second = 60 - M + aM;
        }
    }
    else if(H < aH){
        if(M == aM){
          ans.first = aH - H;
          ans.second =  0;
        }
        else if(M < aM){
          ans.first = aH - H;
          ans.second = aM - M;
        }
        else{
          ans.first = aH - H -1;
          ans.second = 60 - M + aM;
        }
    }
    else{
        ans.first = 24 - H + aH;
        if(M == aM){
            ans.second = 0;
        }
        else if(M < aM){
          ans.second = aM - M;
        }
        else{
          ans.first--;
          ans.second = 60 - M + aM;
        }
    }

    return ans;
}
/*====================================================================================================*/
int main(void) {
    sws 
    lli T;
    cin >> T;

    while(T--){
        lli N, H, M;
        cin >> N >> H >> M;

        pair <lli, lli> ans;
        ans.first = 25;
        ans.second = 61;
        while(N--){
            lli aH, aM;
            cin >> aH >> aM;
            
            pair <lli, lli> tans;
            tans = solve(H, M, aH, aM);

            if(tans.first < ans.first){
              ans.first = tans.first;
              ans.second = tans.second;
            }
            else if(tans.first == ans.first && tans.second < ans.second) ans.second = tans.second; 
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0; 
}
/*====================================================================================================*/

// Function to return the ~X.
ulli nop(ulli number) { return (~number) ^ (ULLONG_MAX << (hibit(number))); }

// Function to return the highest bit position of a number.
ulli hibit(ulli x) { return (lli)log2(x) + 1; }

// Function to verify if a given string is a palindrome or not.
bool isPalindrome(string s) {
  int l = 0;
  int r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }

  return true;
}

// Function to return the sum of digits of a number.
lli sumdigits(lli x) {
  lli rest;
  lli result = 0;

  do {
    rest = x % 10;
    result += rest;
    x = x / 10;
  } while (x > 0);

  return result;
}

// to find the scalar product between two vectors.
lli productScalar(pair<int, int> A, pair<int, int> B) {
  return A.first * B.first + A.second * B.second;
}

// to find the square of the norm of a vector.
lli normSquareVector(pair<int, int> A) {
  return A.first * A.first + A.second * A.second;
}
void outputFormated(string S, int lineSize) {
  istringstream outputString(S);
  size_t lineLen = 0; // Better than an int or lli.
  string currentWord;

  while (outputString >> currentWord) {
    size_t wordLen = currentWord.size();
    if (lineLen == 0) {
      cout << currentWord;
      lineLen = currentWord.size();
      continue;
    } else {
      if (lineLen + wordLen + 1 > 60) {
        cout << endl;
        cout << currentWord;
        lineLen = wordLen;
      } else {
        cout << ' ' << currentWord;
        lineLen += wordLen + 1;
      }
    }
  }
}

// returns the value of the determinant given three points.
lli colinearThreePoints(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
  return (-1) * C.first * B.second + (-1) * C.second * A.first +
         (-1) * B.first * A.second + A.first * B.second + A.second * C.first +
         B.first * C.second;
}

// Returns the average point of two given points.
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B) {
  return {(A.first + B.first) / 2, (A.second + B.second) / 2};
}

// AC
