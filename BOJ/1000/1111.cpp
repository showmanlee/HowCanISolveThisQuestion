// IQ Test
// https://www.acmicpc.net/problem/1111

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1) {
		cout << "A\n";
	} else if (n == 2) {
		if (v[0] == v[1]) {
			cout << v[0] << '\n';
		} else {
			cout << "A\n";
		}
	} else {
		if (v[0] == v[1]) {
			bool b = true;
			for (int i = 2; i < n; i++) {
				if (v[i] != v[0]) {
					b = false;
					break;
				}
			}
			if (b) {
				cout << v[0] << '\n';
			} else {
				cout << "B\n";
			}
		} else {
			if ((v[2] - v[1]) % (v[1] - v[0]) != 0) {
				cout << "B\n";
			} else {
				int a = (v[2] - v[1]) / (v[1] - v[0]);
				int b = v[1] - (v[0] * a);
				bool fail = false;
				for (int i = 0; i < n - 1; i++) {
					if (v[i + 1] != v[i] * a + b) {
						fail = true;
						break;
					}
				}
				if (fail) {
					cout << "B\n";
				} else {
					cout << (v[n - 1] * a + b) << '\n';
				}
			}
		}
	}
}

// v[i + 1] = v[i] * a + b 꼴인 수열이 주어질 때, 다음 수 예상하기(경우가 많으면 A, 불가능하면 B)

// a와 b를 구하는 방법은 연속된 세 수를 연립방정식으로 풀어보는 것 - v[0] * a + b = v[1], v[1] * a + b = v[2]
// 하지만 이를 구하려면 3개 이상의 수가 필요하므로 1, 2개인 경우는 따로 빼서 생각해야 함
// 1개인 경우 규칙 자체가 명시되지 않으므로 A
// 2개인 경우 규칙 자체가 모호하므로 A, 다만 두 수가 같다면 이후에도 계속 같으므로(a = 1, b = 0) 같은 수 출력
// 3개 이상인 경우, 앞의 두 수가 같으면 뒤의 수들도 모두 같아야 한다 - 만약 진짜로 모두 같으면 같은 수, 아니면 불가능하므로 B
// 이 모든 상황이 아닌 경우, a와 b를 구해보기 시작한다 - a = (v[2] - v[1]) / (v[1] - v[0]), b = v[1] - (v[0] * a)
// 다만 a와 b는 정수여야 하므로 실수가 나온다면 B
// a와 b가 정수가 나왔다면 지금까지의 수를 모두 보면서 규칙에 맞는지 확인한다 - 맞으면 다음 수 출력, 아니면 B