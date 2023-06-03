// Zegarek
// https://www.acmicpc.net/problem/26752

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);


	int h, m, s;
	cin >> h >> m >> s;
	s++;
	if (s == 60) {
		s = 0;
		m++;
		if (m == 60) {
			m = 0;
			h++;
			if (h == 24) {
				h = 0;
			}
		}
	}
	cout.width(2);
	cout.fill('0');
	cout << h << ":";
	cout.width(2);
	cout.fill('0');
	cout << m << ":";
	cout.width(2);
	cout.fill('0');
	cout << s << '\n';
}

// 시각이 주어질 때, 1초 뒤 출력하기

// 1초를 더해주면 된다 - 문제는 hh:mm:ss 꼴로 출력하기
// 이를 위해 cout.width(2)를 쓰면 되는데 - 0으로 채우려면 cout.fill('0')으로다가
// 다만 이는 변수 하나마다 설정을 해줘야 함 - 이에 주의하면서 작성하기