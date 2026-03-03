#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 5;
	string eagle = "eagle";
	for (int i = 0; i <= s.length() - 5; i++) {
		string ss = s.substr(i, 5);
		int cnt = 5;
		for (int j = 0; j < 5; j++) {
			if (ss[j] == eagle[j]) {
				cnt--;
			}
		}
		res = min(res, cnt);
	}
	cout << res << '\n';
}