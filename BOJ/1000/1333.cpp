// 부재중 전화
// https://www.acmicpc.net/problem/1333

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l, d;
    cin >> n >> l >> d;
    int r = 0;

    while (true) {
        if (r >= (l + 5) * n)
            break;
        if (r % (l + 5) >= l && r % (l + 5) < l + 5)
            break;
        r += d;
    }
    cout << r << '\n';
}

// l초의 곡이 n개 삽입된 앨범에 곡간 5초의 인터미션이 있을 때, d초에 한 번 1초간 울리는 전화벨 소리를 온전히 들을 수 있는 가장 빠른 시간은?
// 한 곡은 l + 5초의 사이클로 흐른다 - 만약 전화벨이 울린 시간이 % (l + 5)에서 l~l+4일 경우에는 조용하니 들을 수 있다
// 그렇지 않다면, (l + 5) * n초가 흘러 모든 노래가 끝나면 들을 수 있다