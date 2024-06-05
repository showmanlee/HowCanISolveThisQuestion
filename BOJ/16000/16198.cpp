// 에너지 모으기
// https://www.acmicpc.net/problem/16198

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int res;

void func(vector<int>& v, int sum) {
    if (v.size() <= 2) {
        res = max(res, sum);
        return;
    }
    for (int i = 1; i < v.size() - 1; i++) {
        vector<int> vv = v;
        vv.erase(vv.begin() + i);
        func(vv, sum + v[i - 1] * v[i + 1]);
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    res = 0;
    func(v, 0);
    cout << res << '\n';
}

// 정수 배열에서 원소 하나를 지우며 양옆의 원소값의 곱을 점수로 얻을 수 있을 때, 얻을 수 있는 최대 점수 출력하기

// 재귀로 알아봅시다 - 원소 비워주는 동작이 어려우니 참조 vector를 만들어서 테스트해봅시다