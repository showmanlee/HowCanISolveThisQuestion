// Counting Antibodies
// https://www.acmicpc.net/problem/24860

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    long long res = a * b * e * f * g + c * d * e * f * g;
    cout << res << '\n';
}

// 다양한 항체 구성 성분의 수가 주어질 때, 만들어지는 항체 개수 구하기

// 문제를 잘 보고 수식을 만들어서 값을 넣고 출력하기 - 예제를 보고 유추해도 되고
// long long만 조심해주자