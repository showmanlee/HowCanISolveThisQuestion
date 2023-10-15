// 옥상 정원 꾸미기
// https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

	stack<int> st;
    long long res = 0;
	for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            if (st.top() <= board[i]) {
                st.pop();
            } else {
                break;
            }
        }
		st.push(board[i]);
        res += st.size() - 1;
	}
	cout << res << '\n';
}

// 일렬로 세워진 건물 옥상에서 오른쪽에 있는 낮은 건물들의 옥상을 볼 수 있을 때, 모든 건물에서 볼 수 있는 다른 건물 옥상 개수 구하기

// 스택을 이용해 O(n)으로 구해봅시다
// 현재 높이를 스택에 넣기 전, top에 있는 높이가 나보다 낮으면 뺀다
// 이후 나를 스택에 넣은 뒤, 스택 길이 - 1을 결과에 더한다