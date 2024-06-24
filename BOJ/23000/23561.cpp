// Young한 에너지는 부족하다
// https://www.acmicpc.net/problem/23561

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n * 3);
    for (int i = 0; i < n * 3; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = v[n + n - 1] - v[n];
    cout << res << '\n';
}

// 나이가 다른 3n명의 사람들을 3명씩 나눴을 때, 각 조 나이의 중간값의 최대/최소의 차가 최소가 되는 경우 구하기

// 나이를 모두 정렬하여 적은 순서대로 3등분한 뒤, 각 풀에서 1명씩 인원을 뽑는 게 가장 이득
// 따라서 중간 풀에서 최대 - 최소를 구해준다