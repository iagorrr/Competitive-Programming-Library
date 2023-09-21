#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()
int n;

struct job {
	int deadline;
	int time;
	int id;
  bool operator < (job &i){
    return i.deadline != deadline ? deadline < i.deadline : id < i.id;
  }
};

int main() { fastio;
	cin >> n;
	vector<job> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].time;
		cin >> a[i].deadline;
		a[i].id = i;
	}
	// foo solution that should be possible.
	sort(all(a));
	ll curtime = 0;
	for(int i = 0; i < n; ++i) {
		if(curtime + a[i].time > a[i].deadline){ // not possible to complete at deadline.
			cout << "*\n";
			return 0;
		}
		curtime += a[i].time;
	}

	curtime = 0;
	while(!a.empty()){
		int choosen = -1;
		ll mintime = 1e9 + 1;
		ll temptime = curtime;
		for(int i = 0; i < (int)a.size(); ++i) {
			if(mintime >= a[i].time and (choosen == -1 || a[i].id < a[choosen].id)){
				choosen = i;	
			}
			temptime += a[i].time;
			mintime = min(mintime, a[i].deadline-temptime);
		}
		curtime += a[choosen].time;
		cout << a[choosen].id+1 << ' ';
		if(a.size() == 1) cout << '\n';
		a.erase(a.begin()+choosen);
	}
}

// AC, implementation.

