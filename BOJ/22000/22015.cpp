// 金平糖 (Konpeito) 
// https://www.acmicpc.net/problem/22015

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << (v[2] - v[0] + v[2] - v[1]) << '\n';
}

// 세 수가 주어졌을 때, 세 수를 똑같이 만들기 위해 각 수에 더해야 하는 최솟값의 합 구하기

// 가장 큰 수에 맞추기 위해 나머지 두 수에 차만큼 더해준다 - 따라서 가장 큰 수와 나머지 두 수의 차의 합