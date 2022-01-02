// 전북대학교
// https://www.acmicpc.net/problem/14624

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "I LOVE CBNU\n";
	else {
		for (int i = 0; i < n; i++)
			cout << '*';
		cout << '\n';
		for (int i = n / 2; i >= 0; i--) {
			for (int j = 0; j < i; j++)
				cout << ' ';
			cout << '*';
			if (i != n / 2) {
				for (int j = 0; j < n - (i * 2) - 2; j++)
					cout << ' ';
				cout << '*';
			}
			cout << '\n';
		}
	}
}

// 폭이 n(n % 2 == 1)인 전북대학교 심볼(ㅈ 모양) 출력하기 

// 첫 줄에는 길이가 n인 * 출력
// 그 다음줄부터 첫 줄은 가운데, 그 다음줄은 양옆의 1칸... 이런 식으로 * 출력