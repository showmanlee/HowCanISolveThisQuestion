// 소가 길을 건너간 이유 1
// https://www.acmicpc.net/problem/14467

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cur(11, -1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        if (cur[p] != -1 && cur[p] != d) {
            res++;
        }
        cur[p] = d;
    }
    cout << res << '\n';
}

// 시간별 소의 번호와 발견 위치가 주어질 때, 소가 길은 건넌 횟수 구하기

// 그러니까 같은 번호의 소가 한 위치에 등장한 후 다음에 다른 위치에 등장하는 횟수가 얼만지 세주면 되는데
// 각 소의 마지막 발견 위치를 기억해두고 다른 위치에서 나오면 ++
// 다만 첫 등장은 이동으로 치지 않음에 주의