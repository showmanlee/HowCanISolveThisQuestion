// 회전 초밥
// https://www.acmicpc.net/problem/2531

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> count(d + 1), board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int ctr = 0;
    for (int i = 0; i < k; i++) {
        count[board[i]]++;
        if (count[board[i]] == 1) {
            ctr++;
        }
    }
    count[c]++;
    if (count[c] == 1) {
        ctr++;
    }
    int res = ctr;
    for (int i = 0; i < n; i++) {
        count[board[i]]--;
        if (count[board[i]] == 0) {
            ctr--;
        }
        count[board[(i + k) % n]]++;
        if (count[board[(i + k) % n]] == 1) {
            ctr++;
        }
        res = max(res, ctr);
    }
    cout << res << '\n';
}

// d가지 초밥이 중복 포함 있을 수 있는 길이 n의 회전초밥 레일에서 연속해서 k개를 먹는 경우 초밥 c를 추가로 먹을 수 있을 떄, 최대로 먹을 수 있는 초밥 가짓수는?

// n^2로 가짓수 판정하기에는 충분히 길기 때문에 포인터 이동하면서 현재 인덱스 뺴고 k 앞의 인덱스 넣으면서 진행
// '넣는' 방법은 각 종류별로 개수 카운팅하는 배열로 처리 - 만약 카운팅한 개수가 1이라면 총 종류수에 누적, 0이 되면 제거
// 레일은 원형이기 때문에 'k 앞 인덱스'는 나머지로 구한다 - 이렇게 한 바퀴 돌리며 종류수 최대 확인