// 별 찍기 - 21
// https://www.acmicpc.net/problem/10996

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n == 1)
		cout << '*' << '\n';
	else {
		for (int i = 0; i < n * 2; i++) {
			for (int j = 0; j < n; j++) 
				cout << (i % 2 == j % 2 ? '*' : ' ');
			cout << '\n';
		}
	}
}

// n*n 배열로 별을 찍되, 짝수 줄에는 한칸 아래에 찍기
// 1일 경우에는 한줄에 찍고, 그렇지 않으면 2n*n으로 반복문을 돌리며 i와 j가 %2가 같다면 그 위치에 별 찍기