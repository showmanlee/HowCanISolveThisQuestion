// 그대로 출력하기 2
// https://www.acmicpc.net/problem/11719

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string p;
    for(int i = 0; i < 100; i++){
        getline(cin, p);
        cout << p << endl;
    }
}

// 빈 줄("")이 주어질 수도 있기에 임의의 브레이커를 주면 안 됨