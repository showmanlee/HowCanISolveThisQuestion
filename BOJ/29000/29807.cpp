// 학번을 찾아줘!
// https://www.acmicpc.net/problem/29807

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(5);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int a = (v[0] > v[2] ? (v[0] - v[2]) * 508 : (v[2] - v[0]) * 108);
    int b = (v[1] > v[3] ? (v[1] - v[3]) * 212 : (v[3] - v[1]) * 305);
    int c = v[4] * 707;
    int res = (a + b + c) * 4763;
    cout << res << '\n';
}

// 수능 과목 점수에 따른 학번 생성 공식이 주어질 때, 공식에 따라 학번 생성하기

// 만들어봅시다 