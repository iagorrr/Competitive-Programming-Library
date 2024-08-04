using ll = long long;

template <typename T>
struct WaveletTree {
        struct Node {
                T lo, hi;
                int left_child, right_child;
                vector<int> pcnt;
                vector<ll> psum;

                Node(int lo_, int hi_)
                    : lo(lo_),
                      hi(hi_),
                      left_child(0),
                      right_child(0),
                      pcnt(),
                      psum() {}
        };

        vector<Node> nodes;
        WaveletTree(vector<T> v) {
                nodes.reserve(2 * v.size());
                auto [mn, mx] =
                    minmax_element(v.begin(), v.end());
                auto build = [&](auto &&self, Node &node,
                                 auto from, auto to) {
                        if (node.lo == node.hi or
                            from >= to)
                                return;
                        auto mid =
                            midpoint(node.lo, node.hi);
                        auto f = [&mid](T x) {
                                return x <= mid;
                        };
                        node.pcnt.reserve(to - from + 1);
                        node.pcnt.push_back(0);
                        node.psum.reserve(to - from + 1);
                        node.psum.push_back(0);
                        T left_upper = node.lo,
                          right_lower = node.hi;
                        for (auto it = from; it != to;
                             it++) {
                                auto value = f(*it);
                                node.pcnt.push_back(
                                    node.pcnt.back() +
                                    value);
                                node.psum.push_back(
                                    node.psum.back() + *it);
                                if (value)
                                        left_upper =
                                            max(left_upper,
                                                *it);
                                else
                                        right_lower =
                                            min(right_lower,
                                                *it);
                        }

                        auto pivot =
                            stable_partition(from, to, f);
                        node.left_child =
                            make_node(node.lo, left_upper);
                        self(self, nodes[node.left_child],
                             from, pivot);
                        node.right_child =
                            make_node(right_lower, node.hi);
                        self(self, nodes[node.right_child],
                             pivot, to);
                };
                build(build, nodes[make_node(*mn, *mx)],
                      v.begin(), v.end());
        }

        T kth_element(int L, int R, int K) const {
                auto f = [&](auto &&self, const Node &node,
                             int l, int r, int k) -> T {
                        if (l > r) return 0;
                        if (node.lo == node.hi)
                                return node.lo;
                        int lb = node.pcnt[l],
                            rb = node.pcnt[r + 1],
                            left_size = rb - lb;
                        return (
                            left_size > k
                                ? self(
                                      self,
                                      nodes
                                          [node.left_child],
                                      lb, rb - 1, k)
                                : self(
                                      self,
                                      nodes
                                          [node.right_child],
                                      l - lb, r - rb,
                                      k - left_size));
                };
                return f(f, nodes[0], L, R, K);
        }

        pair<int, ll> count_and_sum_in_range(int L, int R,
                                             T a,
                                             T b) const {
                auto f = [&](auto &&self, const Node &node,
                             int l,
                             int r) -> pair<int, ll> {
                        if (l > r or node.lo > b or
                            node.hi < a)
                                return {0, 0};
                        if (a <= node.lo and node.hi <= b)
                                return {
                                    r - l + 1,
                                    (node.lo == node.hi
                                         ? (r - l + 1ll) *
                                               node.lo
                                         : node.psum[r +
                                                     1] -
                                               node.psum
                                                   [l])};
                        int lb = node.pcnt[l],
                            rb = node.pcnt[r + 1];
                        auto [left_cnt, left_sum] = self(
                            self, nodes[node.left_child],
                            lb, rb - 1);
                        auto [right_cnt, right_sum] = self(
                            self, nodes[node.right_child],
                            l - lb, r - rb);
                        return {left_cnt + right_cnt,
                                left_sum + right_sum};
                };
                return f(f, nodes[0], L, R);
        }

        inline int count_in_range(int L, int R, T a,
                                  T b) const {
                return count_and_sum_in_range(L, R, a, b)
                    .first;
        }

        inline ll sum_in_range(int L, int R, T a,
                               T b) const {
                return count_and_sum_in_range(L, R, a, b)
                    .second;
        }

       private:
        int make_node(T lo, T hi) {
                int id = (int)nodes.size();
                nodes.emplace_back(lo, hi);
                return id;
        }
};
