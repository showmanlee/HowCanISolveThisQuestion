// 제리와 톰 2
// https://www.acmicpc.net/problem/17504

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		long long t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	long long a = 1, b = v[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		a += b * v[i];
		swap(a, b);
	}
	a = b - a;
	a /= gcd(a, b);
	b /= gcd(a, b);
	cout << a << ' ' << b << '\n';
}

// 1kg의 치즈 중 (1 / (a1 + 1 / (a2 + 1 / (a3 .....))))kg가 사라졌을 때, 남은 치즈의 양을 기약분수로 나타내기
// 수열을 입력받은 후, 분자를 1, 분모를 마지막칸으로 초기화
// 이후 n-2부터 역순으로 올라가며 분자에 수열 원소 * 분모를 더한 후 위치 바꾸기를 반복
// 여기까지의 결과가 훔쳐간 치즈의 양이므로, 분자를 반전시킨 후 최대공약수로 분모/분자를 나눠 기약분수로 만들어 출력
// 최대공약수 공식 잊은 건 아니겠지