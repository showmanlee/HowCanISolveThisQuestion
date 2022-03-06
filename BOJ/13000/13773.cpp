// Olympic Games
// https://www.acmicpc.net/problem/13773

#include <iostream> 
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << n << ' ';
		if (n % 4 == 0 && n >= 1896) {
			if (n > 2020) {
				cout << "No city yet chosen";
			}
			else if ((n >= 1914 && n <= 1918) || (n >= 1939 && n <= 1945)) {
				cout << "Games cancelled";
			}
			else {
				cout << "Summer Olympics";
			}
		}
		else {
			cout << "No summer games";
		}
		cout << '\n';
	}
}

// 연도가 주어졌을 때, 하계 올림픽 개최 여부 출력하기

// 하계 올림픽은 1896년부터 시작되어 매 4년마다 개최되었지만, 1914~1918, 1939~1945년의 세계대전기에는 열리지 않았다
// 추가로 문제가 만들어질 시점 개최지는 2020 도쿄까지만 확정되었고, 그 이후는 아직 결정되지 않았다
// 이를 감안해 올림픽 개최, 개최지 미선정, 올림픽 취소, 열리지 않음을 판정하자