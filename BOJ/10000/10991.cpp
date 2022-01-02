// 별 찍기 - 16
// https://www.acmicpc.net/problem/10991

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--)
			cout << ' ';
		for (int j = 0; j < i; j++)
			cout << "* ";
		cout << '\n';
	}
}

// 정삼각형 피라미드 모양으로 별 찍기

// *    *      *        *
//     * *    * *      * *
//           * * *    * * *
//                   * * * * ....