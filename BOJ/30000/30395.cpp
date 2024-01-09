// 내 스트릭을 돌려내!
// https://www.acmicpc.net/problem/30395

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int freeze = 0;
    int streak = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        freeze++;
        int p;
        cin >> p;
        if (streak == 0 && p == 0) {
            continue;
        }
        streak++;
        if (p == 0 && freeze > 0) {
            freeze = -1;
            streak--;
        } else if (p == 0) {
            streak = 0;
        }
        res = max(res, streak);
    }
    cout << res << '\n';
}

// 스트릭 프리즈가 사용될 때 2일 후 스트릭 프리즈를 보충하는 사람이 있을 때, 그 사람의 solved.ac 문제풀이 기록을 보고 최장 스트릭 판정하기

// 스트릭 쿨타임 보면서 스트릭 계산 - 스트릭 프리즈 사용 시 늘어나지 않고, 사용한 다음 날 못 풀면 스트릭 초기화