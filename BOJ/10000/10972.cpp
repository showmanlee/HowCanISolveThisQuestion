// 다음 순열
// https://www.acmicpc.net/problem/10972

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
    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < n; i++)
            cout << v[i] << ' ';
    }
    else
        cout << -1;
    cout << '\n';
}

// 주어진 순열의 다음 순열 출력하기(없으면 -1 출력하기)
// next_permutation을 사용해보세요 - 다음 순열이 있다면 true를 뱉으며 배열을 다음 순열로 바꿔주고, 그렇지 않으면 false를 뱉는답니다