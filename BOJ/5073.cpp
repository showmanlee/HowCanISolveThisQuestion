// 삼각형과 세 변
// https://www.acmicpc.net/problem/5073

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			break;
		sort(v.begin(), v.end());
		if (v[2] >= v[0] + v[1])
			cout << "Invalid\n";
		else if (v[0] == v[1] && v[1] == v[2])
			cout << "Equilateral\n";
		else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
}

// 삼각형의 세 변의 길이를 보고 정삼각형/이등변삼각형/일반삼각형/삼각형 성립 불가 판정하기

// 세 변의 길이를 받고 정렬한 후 가장 긴 길이가 나머지 두 길이의 합보다 크거나 같으면 성립 불가
// 그 이후에는 같은 변의 길의 수로 판정