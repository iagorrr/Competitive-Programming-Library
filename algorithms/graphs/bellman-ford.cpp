bool bellman_ford(const vector<vector<pair<int, ll>>> &g, int s, vector<ll> &dist)
{
  int n = (int)g.size();
  dist.assign(n, LLONG_MAX);

  vector<int> count(n);
  vector<char> in_queue(n);
  queue<int> q;

  dist[s] = 0;
  q.push(s);
  in_queue[s] = true;

  while (not q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;

    for (auto [to, w] : g[cur])
    {
      if (dist[cur] + w < dist[to])
      {
        dist[to] = dist[cur] + w;
        if (not in_queue[to])
        {
          q.push(to);
          in_queue[to] = true;
          count[to]++;
          if (count[to] > n)
            return false;
        }
      }
    }
  }

  return true;
}
