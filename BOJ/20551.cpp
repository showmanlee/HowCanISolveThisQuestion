// Sort 마스터 배지훈의 후계자
// https://www.acmicpc.net/problem/20551

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end() - 1);
    v[n] = 987654321;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int res = lower_bound(v.begin(), v.end() - 1, p) - v.begin();
        cout << (v[res] == p ? res : -1) << '\n';
    }
}

// 주어진 배열을 오름차순으로 정렬했을 때 숫자가 나오는 위치는?
// 배열 정렬 후 이진 탐색으로 위치를 찾아라 - lower_bound
// lower_bound는 제값이 안 나오면 그 다음 위치를 결과로 뱉는다 - 마지막 위치에서 튕기는 것을 막기 위해 배열을 한 칸 더 만들어 놓고, 그 전까지만 정렬하기
// 이때 마지막 자리가 0인 경우 틀릴 수 있기에 마지막 자리는 불가능한 수로 채워주고 lower_bound를 마지막 칸 전까지 돌려서 위치 확인하기