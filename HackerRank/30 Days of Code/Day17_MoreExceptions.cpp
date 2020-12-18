// Day 17: More Exceptions
// https://www.hackerrank.com/challenges/30-more-exceptions/problem

#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here

class Calculator{
    public:
    int power(int n, int p){
        if (n < 0 || p < 0)
             throw runtime_error("n and p should be non-negative");
        return pow(n, p);
    }  
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}

// 예외 자체 생성 및 메시지 달기 - 주어진 코드에 예외 처리 코드가 있음에 주의
// #include <exception>, #include <stdexcept>, throw runtime_error("...")