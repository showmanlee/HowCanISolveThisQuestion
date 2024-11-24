// 정보섬의 대중교통
// https://www.acmicpc.net/problem/28113

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    int bb = (n > b ? 987654321 : b);
    cout << (a < bb ? "Bus" : (a > bb ? "Subway" : "Anything")) << '\n';
}

// 현 시점에서 남은 버스 막차 시간과 지하철 막차 시간, 그리고 버스정류장에서 지하철역까지 가는 시간이 주어질 때, 어떤 거를 타야 더 빨리 갈 수 있는지 구하기