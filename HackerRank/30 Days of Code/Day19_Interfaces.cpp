// Day 19. Interfaces
// https://www.hackerrank.com/challenges/30-interfaces/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};
class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                res += i;
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}

// 인터페이스 상속하여 실체화하기
// 순수 virtual 함수(=0)만 있는 클래스가 인터페이스 클래스. 이를 상속한 클래스에서 해당 함수들을 모두 선언해야 한다. 
