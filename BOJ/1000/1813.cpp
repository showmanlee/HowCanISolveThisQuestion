// 논리학 교수
// https://www.acmicpc.net/problem/1813

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

	vector<int> cnt(51);
    for (int i = 0; i < n; i++) {
		int p;
        cin >> p;
		cnt[p]++;
	}

	int res = -1;
    for (int i = 50; i >= 0; i--) {
        if (cnt[i] == i){
			res = i;
			break;
        }
	}
    cout << res << '\n';
}

// 정확히 p개의 말이 참이라는 명제가 n개 주어질 때, 참인 명제의 최대 개수 구하기

// 정확히 p개의 말이 참이라는 명제가 p번 등장하면 참이 됨 - 이를 만족하는 p의 최댓값을 찾는다
// 모순이 있을 경우(0개의 말이 참이라는 명제가 1개 이상 나온 경우) -1 출력하기