// 커트라인
// https://www.acmicpc.net/problem/25305

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[m - 1] << '\n';
}

// 응시자의 성적과 합격자 수가 주어질 때, 커트라인 구하기

// 성적들을 정렬한 후 (합격자 수)등의 점수 출력하기