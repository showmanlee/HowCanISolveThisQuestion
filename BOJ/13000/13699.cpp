// 점화식
// https://www.acmicpc.net/problem/13699

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int n;
	cin >> n;
    vector<long long> v(36);
	v[0] = v[1] = 1;
	v[2] = 2;
	
	for (int i = 3; i <= 35; i++) {
		for (int j = 0; j < i; j++) {
			v[i] += (v[j] * v[i - 1 - j]);
		}
	}
	cout << v[n] << '\n';
}

// 문제에 주어진 식 대로 점화식이 주어질 때, n에 대응하는 값 구하기

// 점화식은 dp로 매 칸마다 기억해서 넣으면 되는데, long long으로 해야 하니 참고