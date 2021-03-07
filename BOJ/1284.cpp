// 집 주소
// https://www.acmicpc.net/problem/1284

#include <iostream>
#include <string>
using namespace std;
int len[10] = {4, 2, 3, 3, 3, 3, 3, 3, 3, 3};

int main(void){
    while (true){
        string s;
        cin >> s;
        if (s == "0")
            break;
        int res = 1 + s.length();
        for (char c : s)
            res += len[c - '0'];
        cout << res << '\n';
    }
}

// 번호판을 만들 때 앞/뒤/숫자 사이에 1cm의 간격을 둬야 하고 각 숫자는 1은 2cm, 0은 4cm, 그 외의 숫자는 3cm를 차지한다
// 주어진 호수에 따른 번호판의 길이는?
// 입력을 string으로 받으면 될 일