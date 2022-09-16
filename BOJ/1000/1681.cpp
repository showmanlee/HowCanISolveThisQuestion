// 줄 세우기
// https://www.acmicpc.net/problem/1681

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;
	int res = 0;
	for (int i = 0; i < n; i++) {
		res++;
		while (to_string(res).find('0' + l) != string::npos) {
			res++;
		}
	}
	cout << res << '\n';
}

// n명에게 숫자 l이 들어가지 않은 자연수 번호표를 나눠줄 때, 마지막 사람이 받는 번호표는?

// 문자열로 바꿔서 그 숫자가 들어가는지 확인한다 - find
// 최대 인원 수가 100만이므로, 이 정도는 확인할 수 있음