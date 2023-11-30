// 콘서트
// https://www.acmicpc.net/problem/16466

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<float, float> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long idx = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (idx == v[i]) {
            idx = v[i] + 1;
        } else if (idx < v[i]) {
            break;
        }
    }
    cout << idx << '\n';
}

// 주어진 자연수를 제외하고 가장 작은 자연수 구하기

// 주어진 배열을 정렬한 뒤, 결과값을 1로 두고 작은 순으로 보면서 자신과 같은 수가 나왔다면 결과값 1 올려주기
// 이러다가 자신보다 더 높은 수가 나와 더 이상 갱신될 일이 없을 때 탈출하기