// 집에선 안돼잉
// https://www.acmicpc.net/problem/29734

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	long long n, m, t, s;
	cin >> n >> m >> t >> s;
	long long zip = n + ((n - 1) / 8 * s);
	long long dok = t + m + ((m - 1) / 8 * (s + t * 2));
	cout << (zip < dok ? "Zip" : "Dok") << '\n' << (zip < dok ? zip : dok) << '\n';
}

// 자택/독서실에서의 과제 시간, 독서실까지의 편도 이동 시간, 취침 시간이 주어질 때, 하루 최대 8시간까지 과제를 하며 취침 및 이동을 할 때 가장 빨리 끝낼 수 있는 곳은?

// 과제 제출은 종료 즉시 가능하지만, 전날 8시간째에 딱 맞춰 끝내면 자고 일어나서 내야 함
// 이걸 감안하며 계산해봅시다
// 독서실에서는 처음에 집에서 출발하고, 제출도 독서실에서 해야 함에 유의