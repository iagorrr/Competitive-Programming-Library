
// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)        \
  for (auto &xxx : xxxx) \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out()
{
  cerr << endl;
}
template <typename H, typename... T>
void dbg_out(H h, T... t)
{
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                 \
  {                              \
    cerr << #__VA_ARGS__ << ':'; \
    dbg_out(__VA_ARGS__);        \
  }

/*
  The best solution is always before some birthday.
*/
vector<int> days_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<int, 366> year;

pii daytodate(int x)
{
  int curday = 0;
  for (int i = 1; i <= 13; ++i)
  {
    for (int j = 1; j <= days_month[i]; ++j)
    {
      if (curday + j == x)
      {
        return make_pair(i, j);
      }
    }
    curday += days_month[i];
  }
}
int datetoday(pii x)
{
  // converts a day-month to the day in the year.
  int day = 0;
  for (int i = 1; i <= x.fst - 1; ++i)
  {
    day += days_month[i];
  }
  day += x.snd;
  return day;
}

int calcdist(int x, int y)
{
  // today is x, how much time passed since y
  if(x > y) {
    return x - y;
  }
  else {
    return 365-y+x;
  }
}
int calcclose(int x)
{
  int original = datetoday(make_pair(10, 27));
  if (original > x)
  {
    return 365 - original + x;
  }
  else
  {
    return x - original;
  }
}
void run()
{
  int n;
  scanf("%d", &n);
  
  vi yearday(n);

  for (int i = 0; i < n; ++i)
  {
    char foo[30];
    scanf("%s", foo);
    int day, month;
    scanf("%d-%d", &month, &day);

    int dayinyear = datetoday({month, day});
    yearday[i] = dayinyear;
    year[dayinyear] = 1;
  }
  sort(all(yearday));

  int ansdist = -1;
  int ans = -1;
  for(int i = 0; i < n; ++i) {
    int curday = yearday[i];
    int prevday = curday == 1 ? 365 : curday-1;

    if(year[prevday]) continue;

    int mindist = 366;
    int minzao = 0;
    for(int j = 0; j < n; ++j) {
      if(yearday[j] == prevday) continue;

      if(calcdist(prevday, yearday[j]) < mindist){
        mindist =  calcdist(prevday, yearday[j]);
        minzao = j;
      }
    }

    // printf("d:%d-%d (%d) p: %d-%d (%d) mindist: %d para %d-%d (%d)\n",  daytodate(curday).first, 
    //                                                                   daytodate(curday).second,
    //                                                                   curday,
    //                                                                   daytodate(prevday).first,
    //                                                                   daytodate(prevday).second,
    //                                                                   prevday,
    //                                                                   mindist,
    //                                                                   daytodate(yearday[minzao]).first,
    //                                                                   daytodate(yearday[minzao]).second,
    //                                                                   yearday[minzao]
    //                                                                   );
    if(ans == -1 or ansdist < mindist) {
      ans = prevday;
      ansdist = mindist;
    }
    if(ansdist == mindist and prevday != datetoday({10, 27})) {
      if(ans == datetoday({10, 27}) or calcclose(ans) > calcclose(prevday)){
        ans = prevday;
        ansdist = mindist;
      }
    }
  }
  auto [month, day] = daytodate(ans);
  printf("%d%d-%d%d\n", month/10, month%10, day/10, day%10);
}
int32_t main(void)
{
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, A FUCKING IMPLEMENTATION.
