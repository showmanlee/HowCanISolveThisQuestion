// 카드놀이
// https://www.acmicpc.net/problem/2511

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> a(10), b(10);
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];
	int aa = 0, bb = 0;
	char lastwin = 'D';
	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			aa += 3;
			lastwin = 'A';
		}
		else if (a[i] < b[i]) {
			bb += 3;
			lastwin = 'B';
		}
		else {
			aa += 1;
			bb += 1;
		}
	}
	cout << aa << ' ' << bb << '\n';
	if (aa != bb)
		cout << (aa > bb ? 'A' : 'B') << '\n';
	else
		cout << lastwin << '\n';
}

// 숫자 카드를 내서 이기면 3점, 비기면 1점씩 얻는 게임을 10번 할 때, 두 사람이 얻은 점수와 승자 출력하기

// 두 사람의 점수가 같은 경우 승부가 갈린 마지막 게임의 승자가 승자가 되고, 열 게임 모두 무승부면 최종 무승부 판정
// 따라서 승패를 판별할 때 마지막 승자를 나타내는 변수도 갱신한다 - 초기값은 D
// 만약 최종 점ㅅ무가 다를 경우 많은 쪽이 승자가 되고, 그렇지 않을 경우 마지막 승자에 찍한 것이 결과가 된다