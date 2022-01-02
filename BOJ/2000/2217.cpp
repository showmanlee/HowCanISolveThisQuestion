// 로프
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, v[i] * (i + 1));
    cout << res << '\n';
}

// 서로 다른 중량을 버틸 수 있는 로프를 여러 개 사용하면 각 로프에 고르게 중량이 분산된다고 할 때, 주어진 로프들(의 일부)을 사용하여 들 수 있는 최대 중량은?
// 임의의 로프 더미를 가지고 들 수 있는 최대 중량은 가장 약한 로프 * 로프 수
// 로프들을 받고, 내림차순으로 정렬한 후, 로프를 차례로 추가하면서 (마지막으로 추가한 로프 * 로프 수)의 최댓값을 찾으면 된다
// 결국은 그리디로 볼 수도 있음