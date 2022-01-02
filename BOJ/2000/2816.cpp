// 디지털 티비
// https://www.acmicpc.net/problem/2816

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> ch(n);
	int p1 = 0, p2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> ch[i];
		if (ch[i] == "KBS1")
			p1 = i;
		if (ch[i] == "KBS2")
			p2 = i;
	}
	int ex = p1 > p2;
	for (int i = 0; i < p1; i++)
		cout << 1;
	for (int i = 0; i < p1; i++)
		cout << 4;
	for (int i = 0; i < p2 + ex; i++)
		cout << 1;
	for (int i = 0; i < p2 + ex - 1; i++)
		cout << 4;
	cout << '\n';
}

// 채널 리스트가 주어질 때, 다음 네 가지 동작으로 KBS1을 첫 번째, KBS2를 두 번째로 만드는 방법을 아무 거나 출력하기
// 1. 화살표를 한 칸 아래로 내린다. (채널 i에서 i + 1로)
// 2. 화살표를 위로 한 칸 올린다. (채널 i에서 i - 1로)
// 3. 현재 선택한 채널을 한 칸 아래로 내린다. (채널 i와 i + 1의 위치를 바꾼다.화살표는 i + 1을 가리키고 있는다)
// 4. 현재 선택한 채널을 위로 한 칸 올린다. (채널 i와 i - 1의 위치를 바꾼다.화살표는 i - 1을 가리키고 있다)

// 꼭 최소 경로일 필요는 없음 - 길이 신경쓰지 않고 간단한 시나리오로 가도 됨
// KBS1을 찾아 내려갔다가 올라오고, KBS2를 찾아 내려갔다가 올라오기?
// 이 방법을 적용하면 KBS1을 찾고 올라오는 거리는 모두 같음 - KBS2를 찾고 올라오는 거리는 찾는 거리보다 하나 더 작음(두 번째로 만들어야 하므로)
// 하지만 KBS2가 KBS1보다 앞에 있었다면 KBS1을 끌고 올라오는 과정에서 KBS2가 한칸 아래로 내려오게 됨
// 이를 고려하여 1과 4를 적절히 출력하기