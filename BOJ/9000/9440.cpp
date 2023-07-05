// 숫자 더하기
// https://www.acmicpc.net/problem/9440

#include <iostream>
#include <vector>
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
		vector<int> v(n);
		int zero = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] == 0) {
				zero++;
			}
		}
		sort(v.begin(), v.end());
		if (zero == 1) {
			swap(v[0], v[2]);
		} else if (zero >= 2) {
			swap(v[0], v[zero]);
			swap(v[1], v[zero + 1]);
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2) {
				a *= 10;
				a += v[i];
			} else {
				b *= 10;
				b += v[i];
			}
		}
		int res = a + b;
		cout << res << '\n';
	}
}

// 주어진 숫자들도 2개의 수를 만들 때, 합이 가장 작은 경우는?

// 만들어진 수에 0이 맨 앞에 올 수 없음 - 즉 00123을 만들지 못한다는 말
// 일반적으로는 숫자들을 정렬한 후, 두 수의 앞에서부터 하나씩 붙여가며 만들어주면 됨 - 다만 0 처리가 필요함
// 0이 하나일 경우 2번째 숫자랑(0이 아닌 숫자가 2개 이상 들어옴이 보장됨), 2개 이상일 경우 0이 아닌 가장 작은 숫자 2개와 위치를 바꿔서 수를 만들어준단