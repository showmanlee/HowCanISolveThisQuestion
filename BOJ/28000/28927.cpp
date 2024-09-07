// Киноманы
// https://www.acmicpc.net/problem/28927

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int aa, ab, ac, ba, bb, bc;
    cin >> aa >> ab >> ac >> ba >> bb >> bc;
    int ra = aa * 3 + ab * 20 + ac * 120;
    int rb = ba * 3 + bb * 20 + bc * 120;
    cout << (ra == rb ? "Draw" : (ra > rb ? "Max" : "Mel")) << '\n';
}

// 3분짜리 트레일러, 20분짜리 TV쇼, 2시간짜리 영화를 본 기록이 있을 때 누가 가장 영상물을 오래 봤는지 판정하기