// AC
// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string comm, arr;
        int n;
        cin >> comm >> n >> arr;
        arr = arr.substr(1, arr.length() - 2);
        stringstream ss(arr);
        string s;
        deque<int> q;
        bool side = true;
        for (int i = 0; i < n; i++) {
            getline(ss, s, ',');
            q.push_back(stoi(s));
        }
        bool error = false;
        for (char c : comm) {
            if (c == 'R') {
                side = !side;
            } else if (c == 'D') {
                if (q.empty()) {
                    error = true;
                } else {
                    if (side) {
                        q.pop_front();
                    } else {
                        q.pop_back();
                    }
                }
            }
        }
        if (error) {
            cout << "error";
        } else {
            cout << '[';
            while (!q.empty()) {
                if (side) {
                    cout << q.front();
                    q.pop_front();
                } else {
                    cout << q.back();
                    q.pop_back();
                }
                if (!q.empty()) {
                    cout << ',';
                }
            }
            cout << ']';
        }
        cout << '\n';
    }
}

// 주어진 배열을 뒤집거나 맨 앞 원소를 빼는 연산이 주어질 때, 결과 출력하기

// 분명히 배열이나 vector로 하면 오버헤드가 심하게 날 테니 deque를 써보자 - 아니면 배열 반전을 그냥 변수로 두는 식으로 해도 되고
// 어쨌든 원소가 더 늘어나는 건 아니기 때문에 편한 방식대로 하면 됨