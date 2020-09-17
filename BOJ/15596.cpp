// 정수 N개의 합
// https://www.acmicpc.net/problem/15596

#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += a[i];
	return ans;
}

// 함수 구현 문제
