#include <bits/stdc++.h>
using namespace std;

auto run() {
        int N, M;
        cin >> N >> M;


        vector<pair<int,int>> XS(M);
        vector<set<int>> marked(N+1);

        vector<int> cnt_col(N+1), cnt_row(N+1);
        for (auto &[a, b] : XS) {
                cin >> a >> b;
                marked[a].emplace(b);
                cnt_row[a]++;
                cnt_col[b]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> prio_row;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> prio_col;

        for (int i = 1; i <= N; i++) {
                prio_row.emplace(cnt_row[i], i);
                prio_col.emplace(cnt_col[i], i);
        }
        
        while (!prio_row.empty()) {
                auto [r_cnt, row_id] = prio_row.top();
                // cerr << "row id: " << row_id << '\n';
                prio_row.pop();

                vector<pair<int,int>> cant_use;
                int c_cnt, col_id;
                while (r_cnt < M) {
                        do {
                                assert(prio_col.size());
                                tie(c_cnt, col_id) = prio_col.top();
                                prio_col.pop();

                                if (marked[row_id].count(col_id)) {
                                        cant_use.emplace_back(c_cnt, col_id);
                                }
                        }while(marked[row_id].count(col_id));

                        marked[row_id].emplace(col_id);
                        // cerr << "       col_id: " << col_id << '\n';

                        r_cnt++;

                        cant_use.emplace_back(c_cnt+1, col_id);

                }

                // lembra de devolver os cant use pra prio_row
                for (auto &[c_cnt, col_id] : cant_use) {
                        if (c_cnt < M)
                                prio_col.emplace(c_cnt, col_id);
                }
        }

        vector<pair<int,int>> ans;
        for (int i = 1; i <= N; i++) {
                for (auto j : marked[i]) {
                        ans.emplace_back(i, j);
                }
        }

        cout << ans.size() << '\n';
        for (auto &[a, b] : ans) {
                cout << a << ' ' << b << '\n';
        }



}

int main()  {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        run();
}


/*
 * AC, greddy, constructive
 *
 * Grid N por N
 * Tem algumas posições que precisa ser 1
 * tem M dessas poisções nareal
 * O M é 10 no pior caso
 * i-sima linha soma M
 *
 * i-esima coluna soma M
 *
 * - guloso pelo maior ?
 *      - vai pra linha que tem mais
 *      e escolhe a coluna que tem mais tbm
 *              funfou pra : 1, 2
 *                      nao funfou pra terciera :(
 * */

