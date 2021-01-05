// 카드게임
// https://www.acmicpc.net/problem/10801

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v(10);
	int res = 0;
	for (int i = 0; i < 10; i++)
		cin >> v[i];
	for (int i = 0; i < 10; i++) {
		int p;
		cin >> p;
		if (v[i] > p)
			res++;
		else if (v[i] < p)
			res--;
	}
	cout << (res == 0 ? 'D' : (res > 0 ? 'A' : 'B')) << '\n';
}

// 10장으로 하는 숫자 비교 게임 결과 출력하기