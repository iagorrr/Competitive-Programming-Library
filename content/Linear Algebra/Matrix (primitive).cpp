#include "../Contest/template.cpp"
template <typename T>
struct Matrix {
    int n, m;
    valarray<valarray<T>> v;

    Matrix(int _n, int _m, int id = 0) : n(_n), m(_m), v(valarray<T>(m), n) {
        if (id) {
            for (int i = 0; i < n; i++) v[i][i] = 1;
        }
    }

    valarray<T>& operator[](int x) { return v[x]; }

    Matrix transpose() {
        Matrix newv(m, n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) newv[j][i] = (*this)[i][j];

        return newv;
    }

    Matrix operator+(Matrix& b) {
        Matrix ret(*this);
        return ret.v += b.v;
    }

    Matrix& operator+=(Matrix& b) { return v += b.v; }

    Matrix operator*(Matrix b) {
        Matrix ret(n, b.m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < b.m; k++) ret[i][k] += v[i][j] * b.v[j][k];

        return ret;
    }

    Matrix& operator*=(Matrix b) { return *this = *this * b; }

    Matrix power(ll exp) {
        Matrix in = *this;
        Matrix ret(n, n, 1);

        while (exp) {
            if (exp & 1) ret *= in;
            in *= in;
            exp >>= 1;
        }
        return ret;
    }

    /*
    Alters current matrix.

    Does gaussian elimination and puts matrix in
    upper echelon form (possibly reduced).

    Returns the determinant of the square matrix
    with side equal to the number of rows of the
    original matrix.
    */

    T gaussjordanize(int reduced = 0) {
        T det = T(1);

        int line = 0;
        for (int col = 0; col < m; col++) {
            int pivot = line;
            while (pivot < n && v[pivot][col] == T(0)) pivot++;

            if (pivot >= n) continue;

            swap(v[line], v[pivot]);

            if (line != pivot) det *= T(-1);

            det *= v[line][line];

            v[line] /= T(v[line][col]);

            if (reduced)
                for (int i = 0; i < line; i++) {
                    v[i] -= T(v[i][col]) * v[line];
                }

            for (int i = line + 1; i < n; i++) {
                v[i] -= T(v[i][col]) * v[line];
            }

            line++;
        }

        return det * (line == n);
    }

    /*
    Needs to be called in a square matrix that
    represents a system of linear equations. Returns
    {possible solution, number of solutions (2 if
    infinite solutions)}
    */
    pair<vector<T>, int> solve_system(vector<T> results) {
        Matrix aux(n, m + 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) aux[i][j] = v[i][j];
            aux[i][m] = results[i];
        }

        T det = aux.gaussjordanize(1);
        int ret = 1 + (det == T(0));

        int n = results.size();

        for (int i = n - 1; i >= 0; i--) {
            int pivot = 0;
            while (pivot < n && aux[i][pivot] == T(0)) pivot++;

            if (pivot == n) {
                if (aux[i][m] != T(0)) ret = 0;
            } else
                swap(aux[i], aux[pivot]);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) aux[i][m] -= aux[i][j] * aux[j][m];
        }

        for (int i = 0; i < n; i++) results[i] = aux[i][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) v[i][j] = aux[i][j];
        }

        return {results, ret};
    }

    /*
   Does not alter current matrix.
   Returns {inverse matrix, is curent matrix
   invertable}
   */
    pair<Matrix<T>, bool> find_inverse() {
        int n = v.size();
        Matrix<T> aug(n, 2 * n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) aug[i][j] = v[i][j];

        for (int i = 0; i < n; i++) aug[i][n + i] = 1;

        T det = aug.gaussjordanize(1);

        Matrix<T> ret(n, n);
        for (int i = 0; i < n; i++) {
            ret[i] = valarray<T>(aug[i][slice(n, n, 1)]);
        }

        return {ret, det != T(0)};
    }

    // Returns rank of matrix. Does not alter it.
    int get_rank() const {
        if (m == 0) return 0;

        Matrix<T> aux(*this);

        aux.gaussjordanize();

        int resp = 0;

        for (int i = 0; i < n; i++) resp += (aux[i] != valarray<T>(m)).sum();

        return resp;
    }
};
