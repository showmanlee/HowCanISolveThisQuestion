// Scholarship
// https://www.acmicpc.net/problem/31394

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool miss = false, perfect = true;
	float avg = 0.f;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 3) {
			miss = true;
		}
		if (p != 5) {
			perfect = false;
		}
		avg += p;
 	}
	avg /= n;
	string res;
	if (miss) {
		res = "None";
	} else if (perfect) {
		res = "Named";
	} else if (avg >= 4.5f) {
		res = "High";
	} else {
		res = "Common";
	}
	cout << res << '\n';
}

// 주어지는 성적에 맞는 장학금 출력하기