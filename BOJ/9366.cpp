// 삼각형 분류
// https://www.acmicpc.net/problem/9366

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		cout << "Case #" << i << ": ";
		if (v[2] >= v[0] + v[1])
			cout << "invalid!\n";
		else if (v[0] == v[1] && v[1] == v[2])
			cout << "equilateral\n";
		else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
			cout << "isosceles\n";
		else
			cout << "scalene\n";
	}
}

// 삼각형의 세 변의 길이를 보고 정삼각형/이등변삼각형/일반삼각형/삼각형 성립 불가 판정하기

// 세 변의 길이를 받고 정렬한 후 가장 긴 길이가 나머지 두 길이의 합보다 크거나 같으면 성립 불가
// 그 이후에는 같은 변의 길의 수로 판정