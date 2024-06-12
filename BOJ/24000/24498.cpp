// blobnom
// https://www.acmicpc.net/problem/24498

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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, v[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        res = max(res, v[i] + min(v[i - 1], v[i + 1]));
    }
    cout << res << '\n';
}

// 높이가 다른 탑에서 양옆의 탑이 높이 1 이상일 때 한칸씩 빼서 자신의 높이를 1 높일 수 있을 때, 최대로 높일 수 있는 경우 구하기

// 한번 높이를 올리면 블롭 하나가 사라진다 - 따라서 여러 개를 움직이는 건 의미 없고, 최대로 올릴 수 있는 거 하나만 집중적으로 올려야 한다
// 그리고 그런 탑은 자신과 양옆 탑 중 작은 쪽의 합이 가장 큰 경우 - 하지만 10101 처럼 그러지 못하는 경우도 있을 수 있으니 전체적으로 최대 높이를 뽑아줘야 함