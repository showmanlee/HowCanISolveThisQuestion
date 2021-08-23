// Olmypiad Pizza
// https://www.acmicpc.net/problem/15235

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	queue<pr> q;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		q.push({ p, i });
	}
	int time = 1;
	vector<int> res(n + 1);
	while (!q.empty()) {
		int remain = q.front().first;
		int idx = q.front().second;
		q.pop();
		remain--;
		if (remain == 0)
			res[idx] = time;
		else
			q.push({ remain, idx });
		time++;
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 줄을 서면 차례로 피자를 받을 수 있는 가판대에 선 사람들이 원하는 피자 개수가 주어졌을 때, 각 사람이 피자를 언제 모두 받게 되는지 출력하기

// 피자는 하나씩 받을 수 있고, 또 받으려면 맨 뒤로 가야 한다 - 큐를 이용해서 풀 수 있음
// 피자 수를 입력받을 때 해당 숫자를 큐에 넣는데, 이러면 누가 누구인지 알 수 없으므로 pair 형태로 피자 수 - 인덱스 형태로 저장
// 이후 큐가 빌 때까지 시간을 흘려주면서 맨 앞에 있는 원소를 pop하고 그 원소의 피자 수를 1 줄인다
// 이때 남은 피자 수가 0이 될 경우 결과 배열에 해당 인원의 결과 시간을 저장하고, 그렇지 않다면 다시 큐에 넣는다
// 이렇게 모든 연산이 마무리되면, 결과 배열을 출력한다