// 지도 자동 구축
// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=413

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
        int n;
        cin >> n;
        int p = 2, q = 1;
        for (int i = 0; i < n; i++){
                p += q;
                q *= 2;
        }
        cout << (p * p) << '\n';
        return 0;
}

// Diamond-Square-Algorithm을 돌릴 때 각 단계별로 생기는 점 수는?
// (2 + 2^n - 1)^2
// 참고로 DSA는 하이트맵을 만들기 위해 사용되는 알고리즘
// 정사각형 네 꼭지점에서 대각선으로 만나는 교차점에 점을 찍고, 그 교차점에서 정사격형의 변과 평행한 방향으로 선을 그어 변 위에 점을 찍는다 - 이를 반복