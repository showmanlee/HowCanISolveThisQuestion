// Lunacy
// https://www.acmicpc.net/problem/4714

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(2);
    while (true) {
        float f;
        cin >> f;
        if (f < 0) {
            break;
        }
        float ff = f * 0.167;
        cout << "Objects weighing " << f << " on Earth will weigh " << ff << " on the moon.\n";
    }
}

// 주어진 소수에 0.167을 곱해서 소수 둘째자리까지 출력하기

// 그렇게 출력해주면 됩니다
// 참고로 cout << fixed를 안 해주고 precision만 해주면 지수 표기법으로 출력되니 참고...