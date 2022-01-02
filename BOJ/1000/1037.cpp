// 약수
// https://www.acmicpc.net/problem/1037

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<long long> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	sort(board.begin(), board.end());
	long long res = board[0] * board[n - 1];
	cout << res << '\n';
}

// 어떤 수의 1과 자신을 뺀 약수들이 주어졌을 떄, 원래 수 구하기

// 여기에는 어떤 규칙이 숨어있을 것 - 일려진 합성수의 사례를 보면 다음과 같다
// 4  -> 2
// 6  -> 2 3
// 8  -> 2 4
// 9  -> 3
// 10 -> 2 5
// 12 -> 2 3 4 6
// 14 -> 2 7
// 15 -> 3 5
// 16 -> 2 4 8 ...

// 즉, 약수들을 정렬한 후 첫 번째 약수와 마지막 약수를 곱한 것이 우리가 원하는 수가 되는 것
// 따라서 그런 방식으로 풀어준다 - 약수로 100만이 들어와 곱해질 수도 있으니 long long으로 처리