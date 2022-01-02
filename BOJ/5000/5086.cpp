// 배수와 약수
// https://www.acmicpc.net/problem/5086

#include <iostream>
using namespace std;

int main(void){
    while(true){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (a < b){
            if (b % a == 0)
                cout << "factor\n";
            else
                cout << "neither\n";
        }
        else{
            if (a % b == 0)
                cout << "multiple\n";
            else
                cout << "neither\n";            
        }
    }
}

// 두 수가 배수 관계인지 약수 관계인지 둘 다 아닌지 판정하기
// 배수든 약수든 원리는 같지만, a < b라면 약수, a > b라면 배수로 판정