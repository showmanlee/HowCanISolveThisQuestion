// Router
// https://www.acmicpc.net/problem/15828

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    queue<int> q;
    while (true) {
        int p;
        cin >> p;
        if (p == -1) {
            break;
        }
        if (p == 0) {
            if (!q.empty()) {
                q.pop();
            }
        } else {
            if (q.size() < n) {
                q.push(p);
            }
        }
    }
    if (q.empty()) {
        cout << "empty";
    } else {
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }
    cout << '\n';
}

// 크기가 n인 버퍼에 데이터 입력과 출력 명령이 차례로 주어질 때, 모든 명령을 마친 후 버퍼에 남은 명령 출력하기

// queue로 크기에 맞춰 차례로 넣고 빼기