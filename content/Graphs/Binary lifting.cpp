/*8<
  @Title:

    Binary Lifting/Jumping

  @Description:

    Given a function/successor grpah answers
    queries of the form which is the node after
    $k$ moves starting from $u$.


  @Time:

    Build $O(N \cdot MAXLOG2)$, Query
$O(MAXLOG2)$. >8*/
const int MAXN(2e5), MAXLOG2(30);
int bl[MAXN][MAXLOG2 + 1];
int N;

int jump(int u, ll k) {
  for (int i = 0; i <= MAXLOG2; i++) {
    if (k & (1ll << i)) u = bl[u][i];
  }
  return u;
}
void build() {
  for (int i = 1; i <= MAXLOG2; i++) {
    for (int j = 0; j < N; j++) {
      bl[j][i] = bl[bl[j][i - 1]][i - 1];
    }
  }
}
