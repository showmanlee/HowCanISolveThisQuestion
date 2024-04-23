// 파스칼
// https://www.acmicpc.net/problem/2986

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = n - 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = n - (n / i);
			break;
		}
	}
    cout << res << '\n';
}

// 주어진 파스칼 코드의 출력값 구하기

// n이 아닌 n의 가장 큰 약수가 뒤에서 몇 번째로 나오냐는 묻는 질문 - 물론 범위 때문에 저 코드를 그대로 갖다 넣으면 시간초과
// 그런 데 가장 큰 약수는 sqrt(n)까지만 봐도 계산할 수 있음 - 그렇게 가장 큰 약수를 구한 뒤, 그걸 n에서 뺴서 결과 구하기