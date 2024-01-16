// 타일
// https://www.acmicpc.net/problem/5556

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (x > (n + 1) / 2) {
            x = n + 1 - x;
        }
        if (y > (n + 1) / 2) {
            y = n + 1 - y;
        }
        if (y < x) {
            swap(y, x);
        }
        cout << (x % 3 == 0 ? 3 : x % 3) << '\n';
    }
}

// 한 변의 길이가 n인 정사각형 보드에서 바깥쪽부터 1, 2, 3을 채워넣을 때, 주어진 좌표에 적힌 숫자 구하기

// 점대칭 형태라 점들을 좌측 상단에 대응하는 위치로 옮겨준다
// 색상의 경우 x, y 중 가장 바깥쪽 좌표 색을 따라가므로 여기를 확인해주면 됨