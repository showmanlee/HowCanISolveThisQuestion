// 통계학
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cnt(8001);
    int mean = 0, mid = 0, most = 0, range = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mean += v[i];
        cnt[v[i] + 4000]++;
    }
    sort(v.begin(), v.end());
    mean = round((float)mean / n);
    mid = v[v.size() / 2];
    range = v[v.size() - 1] - v[0];
    bool flag = false;
    int maxx = -987654321;
    for (int i = 0; i < 8001; i++) {
        if (cnt[i] != 0) {
            if (cnt[i] == maxx) {
                if (flag) {
                    most = i - 4000;
                    flag = false;
                }
            }
            if (cnt[i] > maxx) {
                maxx = cnt[i];
                most = i - 4000;
                flag = true;
            }
        }
    }
    cout << mean << '\n' << mid << '\n' << most << '\n' << range << '\n';
}

// -4000~4000까지의 값이 주어지는 배열의 산술평균(정수), 중앙값, 최빈값(동률의 경우 두 번째로 작은 값), 범위 구하기

// 산술평균의 경우 전체 합을 배열 크기로 나누면 구할 수 있음
// 중앙값은 배열을 정렬하여 중앙 인덱스로 구할 수 있음 - 배열 크기는 홀수가 보장됨
// 범위 역시 배열을 정렬하여 끝 인덱스 - 처음 인덱스로 구할 수 있음
// 주어지는 값의 범위가 고정되어 있으므로, -4000을 인덱스 0으로 한 배열을 통해 배열 속 숫자를 세서 최빈값을 구할 수 있음
// 문제는 특이 조항 '같은 수가 나올 경우 *두 번째로 작은 값*을 출력하라'
// 그래서 작은 수부터 차례대로 카운트 배열을 돌면서 첫 번째 최빈값에 플래그를 세우고, 두 번째 최빈값을 발경한 경우 다시 갱신하면서 플래그를 내린다
