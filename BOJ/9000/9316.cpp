// Hello Judge
// https://www.acmicpc.net/problem/9316

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << "Hello World, Judge " << i << "!" << '\n';
}

// n줄에 걸쳐 "Hello World, Judge i!" 출력하기
// 
// 줄 번호가 1부터 시작한다는 것만 체크하고 그대로 출력하기