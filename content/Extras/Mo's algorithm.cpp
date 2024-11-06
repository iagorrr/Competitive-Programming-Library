template <typename T, typename Tans>
struct Mo {
    struct Query {
        int l, r, idx, block;

        Query(int _l, int _r, int _idx, int _block)
            : l(_l), r(_r), idx(_idx), block(_block) {}

        bool operator<(const Query &q) const {
            if (block != q.block) return block < q.block;
            return (block & 1 ? (r < q.r) : (r > q.r));
        }
    };

    vector<T> vs;
    vector<Query> qs;
    const int block_size;

    Mo(const vector<T> &a) : vs(a), block_size((int)ceil(sqrt(a.size()))) {}

    void add_query(int l, int r) {
        qs.emplace_back(l, r, qs.size(), l / block_size);
    }

    auto solve() {
        // get answer return type
        vector<Tans> answers(qs.size());
        sort(all(qs));

        int cur_l = 0, cur_r = -1;
        for (auto q : qs) {
            while (cur_l > q.l) add(--cur_l);
            while (cur_r < q.r) add(++cur_r);
            while (cur_l < q.l) remove(cur_l++);
            while (cur_r > q.r) remove(cur_r--);
            answers[q.idx] = get_answer();
        }

        return answers;
    }

   private:
    // add value at idx from data structure
    inline void add(int idx) {}

    // remove value at idx from data structure
    inline void remove(int idx) {}

    // extract current answer of the data structure
    inline Tans get_answer() {}
};
