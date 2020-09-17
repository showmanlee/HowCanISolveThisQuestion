// 그대로 출력하기
// https://www.acmicpc.net/problem/11718

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    while(true){
        getline(cin, s);
        if (s.length() == 0)
            break;
        cout << s << endl;
    }
}

// 날먹하고 싶다면 언어를 sed로 설정 후 빈칸으로 제출