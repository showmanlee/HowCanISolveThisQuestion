// 바이러스
// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=407

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
        long long k, p, n;
        cin >> k >> p >> n;
        for (long long i = 0; i < n; i++){
                k *= p;
                k %= 1000000007;
        }
        cout << k << '\n';
        return 0;
}

// 처음에 K개 있는 바이러스가 N초 후 P배씩 늘어날 때, 개수는?
// 그저 곱하고 나머지 처리하면 됨