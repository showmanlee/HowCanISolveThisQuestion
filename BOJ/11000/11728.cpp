// 배열 합치기
// https://www.acmicpc.net/problem/11728

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& i : a)
		cin >> i;
	for (int& j : b)
		cin >> j;
	int ap = 0, bp = 0;
	while (ap != n && bp != m) {
		if (a[ap] < b[bp]) {
			cout << a[ap] << ' ';
			ap++;
		}
		else {
			cout << b[bp] << ' ';
			bp++;
		}
	}
	while (ap != n) {
		cout << a[ap] << ' ';
		ap++;
	}
	while (bp != m) {
		cout << b[bp] << ' ';
		bp++;
	}
	cout << '\n';
}

// 정렬되어 있는 두 배열이 주어질 때, 두 배열을 합쳐서 정렬한 것을 출력하기
// 당연히 두 배열을 물리적으로 합쳐서 sort를 돌리라는 말은 아님 - 애초에 합친 배열을 만들 필요도 없음
// 두 배열을 따로 받아서 각 배열의 원소를 가리키는 포인터를 배치, 두 포인터가 가리키는 원소를 비교해 작은 쪽을 출력한 후, 출력한 쪽의 포인터를 ++한다
// 이후 둘 중 하나의 포인터가 최대치를 벗어나면 나머지 배열의 포인터를 끝까지 움직이며 원소 출력