// 아이 러브 크로아티아
// https://www.acmicpc.net/problem/9517

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;
	int p = k - 1;
	vector<pr> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += v[i].first;
		if (t >= 210)
			break;
		if (v[i].second == "T")
			p = (p + 1) % 8;
	}
	p++;
	cout << p << '\n';
}

// 8명의 플레이어가 원으로 둘러 앉아 210초 뒤에 터지는 폭탄을 두고 게임을 한다
// k번 플레이어부터 문제를 풀어 통과(T)하면 다음 사람에게 폭탄을 전달할 때, 누구 손에서 폭탄이 터지는가?

// 입력을 받고, 시간을 계속 더해주고, T가 나왔다면 나머지 연산으로 폭탄을 다음 사람에게 전해준다
// 이를 반복하다 누적된 시간이 210 이상이 되는 순간 종료