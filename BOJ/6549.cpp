// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
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
}

// 주어진 히스토그램에서 찾을 수 있는 가장 큰 직사각형의 크기는?

// n^2 기반으로 푸는 것이 가장 직관적 - 물론 이 문제는 그러라고 낸 문제는 절대 아님
// 세그먼트 트리 기반으로 nLogn으로 풀 수도 있지만, 스택 기반으로 n으로 풀 수도 있음
// 히스토그램을 만든 후, 히스토그램의 맨 앞부터 스택에 넣어가며 넓이 계산하고 결과값 갱신하기

// 스택이 비어있으면 별도의 연산 없이 스택에 삽입
// 스택이 안 비어있고 스택 top의 높이가 현재 높이보다 큰 경우 그러지 않을 때까지 그 top 높이를 기준으로 하는 사각형의 크기를 계산한다
// height = 현재 스택의 top, 이후 스택 pop
// width = 스택이 비어있으면 현재 위치 인덱스(원점에서 현재 위치까지의 실제 길이), 그렇지 않다면 현재 위치 인덱스 - 스택 top - 1(다음으로 작은 부분 사이)
// 스택은 인덱스 순서대로 채워지는 것이 보장됨 - 따라서 스택이 빠질수록 width 또한 길어짐(현재 위치 인덱스 - 스택 top의 차가 커짐)
// 히스토그램을 스택에 모두 채우면 '현재 위치 인덱스'는 n이 되고, 해당 위치의 높이는 0이 됨 - 따라서 스택이 빌 때까지 위의 연산에 n을 넣어서 반복

// 이렇게 갱신한 결과값을 출력하기