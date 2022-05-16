// 골뱅이 찍기 - 돌아간 ㅍ
// https://www.acmicpc.net/problem/23812

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		for (int j = 0; j < n * 5; j++) {
         if (j / n == 0 || j / n == 4 || i / n == 1 || i / n == 3) {
            cout << '@';
         } else {
            cout << ' ';
         }
		}
		cout << '\n';
	}
}

// 획 두께가 n인 5*n 크기의 ㅌ 그리기

// 필요한 줄만 골뱅이 찍기