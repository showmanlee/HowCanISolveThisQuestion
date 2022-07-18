// Counting Sheep
// https://www.acmicpc.net/problem/7366

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s == "sheep") {
                cnt++;
            }
        }
        cout << "Case " << t << ": This list contains " << cnt << " sheep.\n\n";
    }
}

// 주어진 n개의 문자열 중 "sheep"의 개수 찾기

// 대소문자 구분해서 "sheep"이 나온 개수 세서 출력하기
// 각 출력 사이 줄바꿈이 2번 있어야 함에 주의