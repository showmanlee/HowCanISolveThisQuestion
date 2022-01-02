// 트럭
// https://www.acmicpc.net/problem/13335

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n, w, l;
	cin >> n >> w >> l;
	vector<int> trucks(n);
	for (int& i : trucks)
		cin >> i;
    int res = 0;
    int i = 0, t = 1, current = 0;
    queue<pr> bridge;
    while (i < n) {
        if (!bridge.empty() && bridge.front().second <= t) {
            current -= bridge.front().first;
            bridge.pop();
        }
        if (current + trucks[i] <= l) {
            bridge.push({ trucks[i], t + w });
            current += trucks[i];
            i++;
        }
        t++;
    }
    while (!bridge.empty()) {
        res = bridge.front().second;
        bridge.pop();
    }
    cout << res << '\n';
}

// 길이가 w이고 최대 l까지의 무게를 버틸 수 있는 다리를 길이가 1인 n대의 트럭이 건너려고 할 때, 다리가 무너지지 않도록 모든 트럭이 지나갈 수 있는 최소 시간은?
// 프로그래머스에서도 봤던 문제
// 다리는 큐(무게와 탈출 시간 저장)로 구현, 다리 위에 있는 트럭의 무게와 시간은 별도의 변수로 두기
// 만약 다리가 트럭을 받아들일 준비가 되었다면 다리(큐)에 태우고, 나갈 때가 되었다면 다리(큐)에서 빼기
// 이렇게 모든 트럭을 다리에 태운 후 트럭을 모두 빼면서 마지막 트럭의 탈출 시간을 결과값으로 출력