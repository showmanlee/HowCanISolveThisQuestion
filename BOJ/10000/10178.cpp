// 할로윈의 사탕
// https://www.acmicpc.net/problem/10178

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		cout << "You get " << (a / b) << " piece(s) and your dad gets " << (a % b) << " piece(s).\n";
	}
}

// 아버지가 a개의 사탕을 b명의 자식들에게 나눠준 뒤 남은 사탕을 가질 때, 자식들에게 돌아가는 사탕과 아버지가 가지는 사탕 개수 구하기

// 자식들은 a/b개, 아버지는 a%b개의 사탕 획득