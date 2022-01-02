// 방 배정
// https://www.acmicpc.net/problem/13304

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int n, p;
	cin >> n >> p;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (int t = 0; t < n; t++) {
		int x, y;
		cin >> x >> y;
		if (y == 1 || y == 2)
			a++;
		else if (y == 3 || y == 4) {
			if (x == 0)
				b++;
			else
				c++;
		}
		else {
			if (x == 0)
				d++;
			else
				e++;
		}
	}
	int res = ceil(double(a) / p) + ceil(double(b) / p) + ceil(double(c) / p) + ceil(double(d) / p) + ceil(double(e) / p);
	cout << res << '\n';
}

// 초등학교 수학여행에서 조건에 맞게 배정할 수 있는 방의 최솟값은?
// 1~2학년은 성별 구분 없이 X명까지, 3~4/5~6학년은 성별 구분해서 X명까지