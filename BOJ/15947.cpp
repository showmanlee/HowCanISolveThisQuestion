// 아기 석환 뚜루루 뚜루
// https://www.acmicpc.net/problem/15947

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n--;
	switch (n % 14) {
		case 0:
		case 12:
			cout << "baby\n";
			break;
		case 1:
		case 13:
			cout << "sukhwan\n";
			break;
		case 4:
			cout << "very\n";
			break;
		case 5:
			cout << "cute\n";
			break;
		case 8:
			cout << "in\n";
			break;
		case 9:
			cout << "bed\n";
			break;
		case 2:
		case 6:
		case 10:
			if (n / 14 == 0)
				cout << "tururu\n";
			else if (n / 14 == 1)
				cout << "turururu\n";
			else if (n / 14 == 2)
				cout << "tururururu\n";
			else
				cout << "tu+ru*" << (n / 14 + 2) << '\n';
			break;
		case 3:
		case 7:
		case 11:
			if (n / 14 == 0)
				cout << "turu\n";
			else if (n / 14 == 1)
				cout << "tururu\n";
			else if (n / 14 == 2)
				cout << "turururu\n";
			else if (n / 14 == 3)
				cout << "tururururu\n";
			else
				cout << "tu+ru*" << (n / 14 + 1) << '\n';
			break;
	}
}

// 아기 상어 노래를 개사한 아기 석환 노래에서 n번째 대사는?
// baby sukhwan tururu turu very cute tururu turu in bed tururu turu baby sukhwan
// 위 가사를 반복하는데, 매 절마다 'tururu', 'turu' 뒤에 'ru'를 하나씩 붙여야 한다
// 만약 'ru'가 5번 이상 반복되면 'tu+ru*k' 꼴로 표시해야 함

// 대놓고 규칙적임 - 3,7,11번째의 tururu, 4,8,12번째의 turu만 처리하면 나머지는 무한반복
// 따라서 들어온 n에 나머지 연산을 적용할 수 있음 - 편한 나머지 연산을 위해 n에 1을 빼고 돌입
// 단어 판정의 경우 n % 14, ru 반복의 경우 n / 14의 값을 보고 결정 - tururu는 3(4-1)절 이후, turu는 4(5-1)절 이후 축약해야 함