// 막대기
// https://www.acmicpc.net/problem/17608

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 1, p = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > p) {
            res++;
            p = v[i];
        }
    }
    cout << res << '\n';
}

// 일렬로 놓인 막대기를 마지막에서 처음 방향에서 볼 때, 보이는 막대기 수는?
// 막대기 입력을 받은 후 다시 역으로 돌면서 '기준 막대기'보다 더 긴 막대기가 있는 경우 해당 막대기를 '기준 막대기'로 하고 결과++