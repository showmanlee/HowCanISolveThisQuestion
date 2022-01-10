// 숫자 재배치
// https://www.acmicpc.net/problem/16943

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	int b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	int res = -1;
	do {
		if (a[0] == '0') {
			continue;
		}
		if (stoi(a) < b) {
			res = stoi(a);
		}
		else {
			break;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << res << '\n';
}

// a의 숫자들을 섞어서 0으로 시작하지 않으면서 b보다 작은 가장 큰 수 만들기(못 만들면 -1)

// a는 string으로, b는 int로 받기
// a의 문자들을 정렬한 후 next_permutation으로 모든 경우의 수를 찾아본다
// 여기서 a가 0으로 시작하면 continue, a < b이면 값 갱신, 그렇지 않으면 break
// 이렇게 해서 최종적으로 갱신된 결과값이 답 - 초기는 -1