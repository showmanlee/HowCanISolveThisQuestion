// 주사위
// https://www.acmicpc.net/problem/1233

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> count(a + b + c + 1);
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				count[i + j + k]++;
	int res = 0, resc = 0;
	for (int i = 3; i <= a + b + c; i++) {
		if (count[i] > resc) {
			res = i;
			resc = count[i];
		}
	}
	cout << res << '\n';
}

// 3개의 주사위를 굴릴 때 많이 나오는 주사위의 합은?
// 주사위 눈 수가 적어 주사위들이 만드는 모든 경우의 수를 테스트할 수 있음
// 그리고 나올 수 있는 합의 범위는 3 ~ (a+b+c) - 배열로 카운팅 가능