/*8<
  @Title: Gauss XOR elimination / XOR-SAT
  @Description:
    Execute gaussian elimination with xor over the
    system $Ax = b$ in. The add method must
    receive a bitset indicating which variables
    are present in the equation, and the solution
    of the equation.
  @Time: $O(\frac{nm^{2}}{64})$
>8*/

const int MAXXI = 2009;
using Equation = bitset<MAXXI>;
struct GaussXor {
  vector<char> B;
  vector<Equation> A;

  void add(const Equation &ai, bool bi) {
    A.push_back(ai);
    B.push_back(bi);
  }

  pair<bool, Equation> solution() {
    int cnt = 0, n = A.size();
    Equation vis;
    vis.set();
    Equation x;
    for (int j = MAXXI - 1, i; j >= 0; j--) {
      for (i = cnt; i < n; i++) {
        if (A[i][j]) break;
      }
      if (i == n) continue;
      swap(A[i], A[cnt]), swap(B[i], B[cnt]);
      i = cnt++;
      vis[j] = 0;
      for (int k = 0; k < n; k++) {
        if (i == k || !A[k][j]) continue;
        A[k] ^= A[i];
        B[k] ^= B[i];
      }
    }
    x = vis;
    for (int i = 0; i < n; i++) {
      int acum = 0;
      for (int j = 0; j < MAXXI; j++) {
        if (!A[i][j]) continue;
        if (!vis[j]) {
          vis[j] = 1;
          x[j] = acum ^ B[i];
        }
        acum ^= x[j];
      }
      if (acum != B[i])
        return {false, Equation()};
    }
    return {true, x};
  }
};
