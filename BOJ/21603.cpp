// K 2K 게임
// https://www.acmicpc.net/problem/21603

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (i % 10 == k % 10 || i % 10 == (k * 2) % 10)
			continue;
		res.push_back(i);
	}
	cout << res.size() << '\n';
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

// 1부터 n까지의 자연수 중 일의 자리 숫자가 k의 것과 2k의 것이 아닌 수들 출력하기

// 1부터 n까지 돌려보면서, 해당 수의 1의 자리(% 10)이 k나 2k의 일의 자리가 아니면 결과 배열에 삽입
// 그리고 이렇게 만든 결과 배열의 크기를 출력한 뒤, 수들 출력하기