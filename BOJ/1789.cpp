// 수들의 합
// https://www.acmicpc.net/problem/1789

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long s;
	cin >> s;
	long long res = 0, sum = 0, p = 1;
	while (true) {
		sum += p;
		res++;
		if (sum > s) {
			res--;
			break;
		}
		p++;
	}
	cout << res << '\n';
}

// 서로 다른 자연수의 합이 s일 때, s를 이루는 자연수의 최대 개수는?

// 자연수의 개수를 늘리려면 포함되는 자연수의 개수를 최대한 줄여야 함
// 따라서 더하는 자연수를 1부터 시작해서 차례대로 올리는게 가장 이득
// 이런 방식으로 1부터 차례대로 더해가면서 개수를 세다가, 더한 결과가 s를 넘는 경우 누적 개수에서 하나를 빼 출력
// 이런 상황의 경우 남은 수는 다른 자연수들에게 하나씩 넣어주면 됨 - 따라서 개수가 바뀌지 않음