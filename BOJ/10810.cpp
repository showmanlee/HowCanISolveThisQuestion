// 공 넣기
// https://www.acmicpc.net/problem/10810

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> box(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++)
            box[j] = c;
    }
    for (int i = 1; i <= n; i++)
        cout << box[i] << ' ';
    cout << '\n';
}

// 일렬로 놓인 상자에 번호가 적힌 공을 넣으려고 한다. a번부터 b번까지 c번 공을 넣되, 이미 공이 들어가 있으면 있던 공을 빼고 새로 넣는다고 할 때, 최종 결과는?
// 공을 빼고 넣는다 - 그냥 갱신한다
// 범위로 for를 넣어주고 갱신하면 됨