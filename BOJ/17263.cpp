// Sort 마스터 배지훈
// https://www.acmicpc.net/problem/17263

#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (res < p)
            res = p;
    }
    cout << res << '\n';
}

// 주어진 배열을 오름차순으로 정렬했을 때 맨 마지막으로 오는 원소는?
// 그러니까 주어진 수열에서 가장 큰 값은?
// 그건 배열도 만들 필요가 없죠