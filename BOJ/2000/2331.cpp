// 반복수열
// https://www.acmicpc.net/problem/2331

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
;
	int a, p;
	cin >> a >> p;
	vector<int> shown(300000);
	int next = a;
	int ctr = 1;
	while (shown[next] == 0) {
		a = next;
		shown[a] = ctr++;
		next = 0;
		while (a != 0) {
			next += pow(a % 10, p);
			a /= 10;
		}
	}
	cout << (shown[next] - 1) << '\n';
}

// d[1] = a, d[n] = (d[n - 1]의 각 자릿수 c에 대해 c^p)인 수열이 있고 해당 수열은 반드시 반복수열이 됨이 보장될 때, 반복수열이 되기 이전에 등장하는 숫자의 수는?

// d[n]으로 나올 수 있는 수는 30만 이하임이 보장됨(9^5 * 4 = 236196) - 따라서 언제 처음으로 등장했는지 표시하는 배열의 크기를 30만 정도로 잡고 시작
// 이후 a부터 시작하여 언제 등장했는지 표시한 다음, 해당 수의 다음 수를 만들어낸다
// 그리고 만들어진 다음 수가 이미 등장한 경우 탐색을 중단하고, 해당 수가 등장한 시점을 이용해 답을 구한다