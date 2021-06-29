// 30
// https://www.acmicpc.net/problem/10610

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;
	int sum = 0;
	bool zero = false;
	for (char c : n) {
		sum += c - '0';
		if (c == '0')
			zero = true;
	}
	if (zero && sum % 3 == 0)
		sort(n.begin(), n.end(), greater<char>());
	else
		n = "-1";
	cout << n << '\n';
}

// 주어진 수에 등장하는 숫자들을 적절히 섞어 가능한 큰 30의 배수를 만들 수 있는가?

// 주어지는 숫자는 최대 10만자리 - 따라서 모든 경우의 수를 셀 수는 없음
// 그렇다고 마냥 대책이 없는 문제는 아님 - 30의 배수를 만들 수 있는 조건이 있음
// 1. 0이 존재하는가 - 당연히 30의 배수니까 0이 있어야겠죠
// 2. 모든 자릿수의 합이 3의 배수인가
// 따라서 모든 자리를 순회하며 이러한 조건을 만족하는지 확인한 후, 만족한다면 해당 자릿수들을 역순으로 정렬한 결과를 출력하면 됨