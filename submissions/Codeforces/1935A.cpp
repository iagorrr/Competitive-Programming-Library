#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		std::string s;
		std::cin >> s;

		std::string rs(s);
		std::reverse(rs.begin(), rs.end());

		if (rs < s) {
			swap(rs, s);
			n--;
		}
		
		std::cout << s;
		if (n&1) std::cout << rs;
		std::cout << '\n';

		
	}

}
 
// AC, constructive algorithms, strings
