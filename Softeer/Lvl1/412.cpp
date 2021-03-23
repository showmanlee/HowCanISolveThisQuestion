// HMG는 왜 HMG일까?
// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=412

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char** argv)
{
        string s;
        cin >> s;
        string res = "";
        for (char c : s)
                if (isupper(c))
                        res += c;
        cout << res << '\n';
        return 0;
}

// 하이픈으로 붙은 단어들의 첫 대문자만 딴 약자 출력하기
// 하이픈 볼 필요 없이 단어 첫 자만 대문자임이 보장되므로 대문자만 가져오면 됨

// 현대차가 만든 SWEA 소프티어 시작!
// 현대차 개발 직종 코테 플랫폼으로도 쓰면서 별도로 온오프라인 인증평가도 하는 걸 보니 작정하고 만든 듯
// 물론 이 문제도 그렇고 그룹 개발직종 채용 공고도 붙어 있는 등 목적이 너무 티나긴 한다마는
// 그래도 신대륙에 깃발 꼽은 느낌