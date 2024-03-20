// Terms of Office
// https://www.acmicpc.net/problem/6888

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    while (n <= m) {
        cout << "All positions change in year " << n << '\n';
        n += 60;
    }
}

// 4명의 보직이 각각 4, 2, 3, 5년에 바뀔 때, 모든 보직이 동시에 바뀐 n년 이후 m년까지 모든 보직이 동시에 바뀌는 연도 출력하기

// 2, 3, 4, 5의 최소공배수는 60 - 따라서 n에서 60을 계속 더해주면 됩니다