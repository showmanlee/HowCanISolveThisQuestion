// 숫자의 개수 2
// https://www.acmicpc.net/problem/21567

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b, c;
	cin >> a >> b >> c;
	string s = to_string(a * b * c);
	vector<int> res(10);
	for (char c : s)
		res[c - '0']++;
	for (int i = 0; i <= 9; i++)
		cout << res[i] << '\n';
}

// 세 수를 곱한 값에서 등장하는 각 숫자의 개수 출력하기

// 각 수의 범위는 최대 100만 - 세 개를 곱해도 long long 범위 안에 들어감
// 따라서 계산하고 string으로 바꾼 뒤 세주면 됩니다