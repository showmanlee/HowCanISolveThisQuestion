// 직사각형을 만드는 방법
// https://www.acmicpc.net/problem/8320

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j <= 10000; j++) {
			if (i * j <= n)
				res++;
			else
				break;
		}
	}
	cout << res << '\n';
}

// 1*1 정사각형 n개로 만들 수 있는 직사각형의 개수는(회전할 수 있으면 같은 형태로 간주)?
// 이중 for에서 i * j의 값이 n 이하면 res++, 그렇지 않다면 내부 for 탈출 후 i 올리기
// 회전해도 같은 형태고 n이 최대 10000이니 외부 for는 100까지 돌려도 됨 - 내부는 10000까지