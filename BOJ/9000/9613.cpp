// GCD 합
// https://www.acmicpc.net/problem/9613

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int n = a % b;
		if (n == 0)
			return b;
		else {
			a = b;
			b = n;
		}
	}
	return 1;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector<int> p(m);
        for (int j = 0; j < m; j++)
            cin >> p[j];
        long long res = 0;
        for (int j = 0; j < m - 1; j++)
            for (int k = j + 1; k < m; k++)
                res += gcd(p[j], p[k]);
        cout << res << '\n';
    }
}

// 여러 개의 정수가 주어질 때, 가능한 모든 쌍의 최대공약수의 합 구하기
// GCD - a % b(a > b) 한 후, n이 0이 나오면 b가 최대공약수, 그렇지 않으면 a = b, b = n으로 두고 b가 0이 될 때까지 반복, 반복이 끝나면 1 반환