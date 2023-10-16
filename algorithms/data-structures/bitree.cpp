template<typename T>
struct BITree
{
    int N;
    vector<T> v;

    BITree(int n) : N(n), v(n+1, 0) {}

    void update(int i, const T& x)
    {
        if (i == 0) return;
        for (; i <= N; i += i & -i)
            v[i] += x;
    }

    T range_sum(int i, int j)
    {
        return range_sum(j) - range_sum(i - 1);
    }

    T range_sum(int i)
    {
        T sum = 0;
        for (; i > 0; i -= i & -i)
            sum += v[i];
        return sum;
    }
};
