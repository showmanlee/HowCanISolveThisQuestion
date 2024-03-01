// 점심시간 레이스
// https://www.acmicpc.net/problem/28236

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    int minn = 987654321;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        int dist = (x - 1) + (m + 1 - y);
        if (dist < minn) {
            minn = dist;
            res = i;
        }
    }
    cout << res << '\n';
}

// 건물 양 끝에 계단이 있는 n층 m열 구조의 건물에서 1층 오른쪽(1, m) 출구로 나가는 거리가 가장 짧은 반 구하기

// 단순 좌표 맨해튼 거리 계산 - 좌표 위치에 주의