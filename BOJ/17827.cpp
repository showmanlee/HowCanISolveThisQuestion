// 달팽이 리스트
// https://www.acmicpc.net/problem/17827

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, v;
	cin >> n >> m >> v;
	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];
	v--;

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		if (k < v)
			cout << list[k] << '\n';
		else {
			int t = (k - v) % (n - v) + v;
			cout << list[t] << '\n';
		}
	}
}

// 마지막 노드가 첫 노드를 제외한 다른 노드를 가리켜 달팽이 모양을 가지는 연결 리스트에서 첫 노드에서 k칸 이동한 노드에 있는 값은?
// k가 10억이 나올 수 있기에 당연히 나머지 연산으로 진입
// k번 인덱스가 아니라 '1번 노드에서 k칸 이동한 결과'가 문제 - 계산을 쉽게 하기 위해 시작을 0번 노드로 두면 이를 'k번째 노드'로 치환 가능
// 이 경우 마지막 노드가 연결되는 위치를 가리키는 v를 하나 줄여야 함
// 이후 k를 입력받은 후 달팽이 영역에 들어오기 전(k < v)에서는 k번 노드를 출력한다
// 하지만 달팽이 영역에 들어온 상태라면 나머지 연산을 해야 하는데, 달팽이 영역의 크기는 n - v이다
// 여기에 나머지 연산을 위해 k에서 v를 빼주고, 나머지 연산을 한 결과를 인덱스로 만들기 위해 마지막에 + v를 해줘야 한다