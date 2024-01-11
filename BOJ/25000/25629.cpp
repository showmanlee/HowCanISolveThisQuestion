// 홀짝 수열
// https://www.acmicpc.net/problem/25629

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p % 2 == 0) {
            even.push_back(p);
        } else {
            odd.push_back(p);
        }
    }
    int res = 0;
    if ((n % 2 == 1 && even.size() + 1 == odd.size()) ||(n % 2 == 0 && even.size() == odd.size())) {
        res = 1;
    }
    cout << res << '\n';
}

// 주어진 수열의 원소 순서를 바꾸어 홀수/짝수 번째 칸의 원소가 모두 홀수/짝수이고, 홀수/짝수 번째 칸들의 원소가 비내림차순으로 정렬될 수 있는지 확인하기

// 수열 내 홀수/짝수 개수를 구한 다음, 정확히 홀짝홀짝홀... 순으로 배치될 수 있으면 OK - 홀/짝간 정렬은 무조건 가능하니까