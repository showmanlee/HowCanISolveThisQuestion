// 최소공배수
// https://www.acmicpc.net/problem/1934

#include <iostream>
#include <algorithm>
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

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
	    int a, b;
	    cin >> a >> b;
	    cout << lcm(a, b) << "\n";
    }
}

// 최소공배수 구하기
// LCM = A * B / GCD