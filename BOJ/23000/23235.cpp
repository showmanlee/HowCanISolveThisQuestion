// The Fastest Sorting Algorithm In The World 
// https://www.acmicpc.net/problem/23235

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int idx = 1;
	while(true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
		}
		cout << "Case " << idx << ": Sorting... done!\n";
		idx++;
	}
}

// 배열을 받아 정렬이 완료되었다는 알림 출력하기

// 정렬 완료만 알려주면 되기 때문에 실제로 정렬을 할 필요는 없음
// 다만 주어지는 배열 크기에 따라 입력 받는 횟수를 조절할 필요는 있음ㄴ