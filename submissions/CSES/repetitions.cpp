// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	cin >> s;
 
	char c = s[0];
	int ans = -1;
	int cc = 0;
	int i = 0;
	while(i < s.size())
	{
		while(i < s.size() and s[i] == c)
		{
			++i;
			++cc;
		}
 
		ans = max(ans, cc);
		c = s[i];
		cc = 0;
	}
 
	cout << ans << '\n';
}

// AC.
