// 히스토그램
// https://www.acmicpc.net/problem/1725

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> hist(n);
	for (int i = 0; i < n; i++)
		cin >> hist[i];
	stack<long long> st;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int left = i;
		while (!st.empty() && hist[st.top()] > hist[i]) {
			long long height = hist[st.top()];
			st.pop();
			long long width = i;
			if (!st.empty())
				width = i - st.top() - 1;
			res = max(res, width * height);
		}
		st.push(i);
	}
	while (!st.empty()) {
		long long height = hist[st.top()];
		st.pop();
		int width = n;
		if (!st.empty())
			width = n - st.top() - 1;
		res = max(res, width * height);
	}
	cout << res << '\n';
}

// 주어진 히스토그램에서 찾을 수 있는 가장 큰 직사각형의 크기는?

// 6549에서 단일 테케만 가지는 문제 - 따라서 해결 방법도 동일
// 그래도 다시 한 번 스택 기반으로 이 문제를 풀 수 있는 방법을 정리해보자

// 히스토그램을 받은 뒤, 히스토그램을 차례대로 스택에 넣는다 - 따라서 구조적으로 스택에는 인덱스 순서대로 값이 차오른다
// 만약 스택에 넣기 전 현재 스택 top에 있는 히스토그램의 높이가 현재 위치보다 높은 경우, 스택에 넣기 전 낮아지거나 빌 때까지 다음 연산을 수행하며 높이를 계산한다
// 높이 = 현재 스택 top의 높이 -> 높이를 구한 뒤 스택 pop
// 너비 = 스택이 비어있다면 현재 인덱스(원점 ~ 현재 인덱스 왼쪽 히스토그램까지의 실제 길이)
//      = 그렇지 않다면 현재 인덱스 - 스택 top - 1(스택 top 오른쪽 히스토그램 ~ 현재 인덱스 왼쪽 히스토그램까지의 실제 길이)
// 이렇게 얻은 값을 곱해 넓이로 만든 후, 결과값에 갱신하기
// 모든 히스토그램을 스택에 넣은 후에는 스택이 빌 때까지 '현재 인덱스'를 'n'으로 치환하여 위의 연산 반복 - 맨 끝 지점을 기준 삼아 넓이 측정하기