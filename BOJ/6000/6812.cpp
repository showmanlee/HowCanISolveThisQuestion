// Good times
// https://www.acmicpc.net/problem/6812

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a = n;
	int b = (n + 2100) % 2400;
	int c = (n + 2200) % 2400;
	int d = (n + 2300) % 2400;
	int e = n;
	int f = (n + 100) % 2400;
	int g = (n + 130) % 2400;
	if (g % 100 >= 60) {
		g = (g + 40) % 2400;
	}
	cout << a << " in Ottawa\n";
	cout << b << " in Victoria\n";
	cout << c << " in Edmonton\n";
	cout << d << " in Winnipeg\n";
	cout << e << " in Toronto\n";
	cout << f << " in Halifax\n";
	cout << g << " in St. John's\n";
}

// 캐나다 오타와 시각이 주어졌을 때, 나머지 지역 시각 출력하기

// 각각 -3:00, -2:00, -1:00, 0:00, +1:00, +1:30
// 시각이 정수 형태로 주어짐에 주의 - 0시의 경우에도 앞에 0을 붙이지 않음
// 따라서 나머지 연산을 이용해 시각을 변환할 수 있음 - +30분의 경우 30을 더한 뒤, 뒤 두 자리가 60 이상이 되면 여기에 40을 더 더한다