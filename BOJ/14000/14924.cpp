// 폰 노이만과 파리
// https://www.acmicpc.net/problem/14924

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int res = (c / (a * 2)) * b;
    cout << res << '\n';
}

// “c마일 길이의 철로의 양쪽 끝에 서 있는 두 대의 기차가 시속 a마일의 속도로 서로를 향해 출발했습니다. 이때부터 두 기차가 서로 충돌할 때까지 파리가 시속 b마일의 속도로 두 기차사이를 왔다 갔다 했습니다. 파리가 이동한 거리는 모두 몇 마일일까요?”

// 문제에 공식이 적혀있으므로 그대로 갖다붙이기