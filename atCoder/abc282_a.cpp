#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
typedef vector<long long> vll;
typedef long long int ll;
typedef unsigned long long int ull;

#define LOOP(I, S, E) for (ll I = S; I < E; I++)
#define LOOPIN(i, E, V)                                                        \
  for (ll i = 0; i < E; i++) {                                                \
    cin >> V[i];                                                               \
  }
#define LOOPOUT(i, E, V)                                                       \
  for (ll i = 0; i < E; i++) {                                                \
    cout << V[i] << endl;                                                      \
  }
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

ull nop(ull number);
ull hibit(ull x);
bool isPalindrome(string s);
ll sumdigits(ll x);
ll productScalar(pair<int, int> B, pair<int, int> A);
ll normSquareVector(pair<int, int>);
ll colinearThreePoints(pair<int, int> A, pair<int, int> B, pair<int, int> C);
ll manhattanDistance(ll x1, ll y1, ll x2, ll y2);
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B);

void outputFormated(string S, int lineSize);
const string caeserAlphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
/*====================================================================================================*/
int main(void) { 
    sws 
    ll k;
    cin >> k;
    for(int i = 0; i < k; ++i)
        cout << caeserAlphabet[i];

    cout << '\n';
    return 0; 
}
/*====================================================================================================*/

// Function to return the ~X.
ull nop(ull number) { return (~number) ^ (ULLONG_MAX << (hibit(number))); }

// Function to return the highest bit position of a number.
ull hibit(ull x) { return (ll)log2(x) + 1; }

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
ll sumdigits(ll x) {
  ll rest;
  ll result = 0;

  do {
    rest = x % 10;
    result += rest;
    x = x / 10;
  } while (x > 0);

  return result;
}

// to find the scalar product between two vectors.
ll productScalar(pair<int, int> A, pair<int, int> B) {
  return A.first * B.first + A.second * B.second;
}

// to find the square of the norm of a vector.
ll normSquareVector(pair<int, int> A) {
  return A.first * A.first + A.second * A.second;
}
void outputFormated(string S, int lineSize) {
  istringstream outputString(S);
  size_t lineLen = 0; // Better than an int or ll.
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
ll colinearThreePoints(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
  return (-1) * C.first * B.second + (-1) * C.second * A.first +
         (-1) * B.first * A.second + A.first * B.second + A.second * C.first +
         B.first * C.second;
}

// Returns the average point of two given points.
pair<int, int> averagePoint(pair<int, int> A, pair<int, int> B) {
  return {(A.first + B.first) / 2, (A.second + B.second) / 2};
}
