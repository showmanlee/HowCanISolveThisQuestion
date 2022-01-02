// 모형 결정
// https://www.acmicpc.net/problem/18127

#include <iostream>
#include <algorithm>
using namespace std;
 
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	long long res = 0;
	long long p = 1;
	for (int i = 0; i <= b; i++) {
		res += p;
		p += a - 2;
	}
	cout << res << '\n';
}

// 정A각형 결정이 0도에서 1도씩 낮아질 때마다 결정의 변 크기가 1씩 증가할 때, -B도에서 얻을 수 있는 결정의 개수는?

// 결정은 1도가 내려갈 때마다 (종전 추가 결정 수 + A-2)개씩 추가된다
// 따라서 이거를 B번 추가하면 됨 - long long으로...