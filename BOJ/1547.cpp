// 공
// https://www.acmicpc.net/problem/1547

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<bool> cup(4);
	cup[1] = true;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(cup[a], cup[b]);
	}
	for (int i = 1; i <= 3; i++)
		if (cup[i])
			cout << i << '\n';
}

// 야바위 게임에서 1번 컵에 공을 넣고 주어진 대로 섞었을 때, 공은 어디에 있는가?
// swap을 반복하다가 있는 곳을 찾아내면 됨
// -1이 나올 리는 없다는 것에 주의