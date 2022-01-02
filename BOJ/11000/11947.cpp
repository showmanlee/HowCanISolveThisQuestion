// 이런 반전이
// https://www.acmicpc.net/problem/11947

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		long long p = 5;
		long long nn = n;
		while (nn / 10 > 0) {
			p *= 10;
			nn /= 10;
		}
		long long res = 0;
		if (n < p) {
			string s = to_string(n);
			for (char& c : s)
				c = ('9' - c) + '0';
			res = n * stoll(s);
		}
		else {
			res = p * (p - 1);
		}
		cout << res << '\n';
	}
}

// 자연수 n의 반전이 각 자리의 숫자를 (9 - p)로 바꾼 것이라고 할 때, 주어진 수 이하인 수 중 자신과 반전의 곱이 가장 큰 값은?
// 반전과의 곱은 그래프로 보면 5000에서 피크를 찍고 그 이후로는 내려온다 - 대칭된다는 것
// 따라서 주어진 수가 500... 을 넘으면 그 이후로는 볼 필요가 없음 - 어차피 모두 작음이 보장되니
// 수가 주어지면, 해당 수와 길이가 같은 500...을 만든 후 주어진 수가 500...보다 작으면 반전을 구하고(string 활용), 그렇지 않으면 500... * 499... 출력하기

// int와 int를 한계까지 곱해야 하므로 결과는 long long으로 출력