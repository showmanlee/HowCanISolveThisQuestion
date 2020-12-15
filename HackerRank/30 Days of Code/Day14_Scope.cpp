// Day 14: Scope
// https://www.hackerrank.com/challenges/30-scope/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
      
    Difference(vector<int> a){
        elements = a;
        maximumDifference = 0;
    }
    
    void computeDifference(){
        sort(elements.begin(), elements.end());
        for (int i = 0; i < elements.size() - 1; i++){
            for (int j = i + 1; j < elements.size(); j++){
                if (elements[j] - elements[i] > maximumDifference)
                    maximumDifference = elements[j] - elements[i];
            }
        }
    }
}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}

// 배열과 배열 내 수의 차의 최댓값을 계산하는 함수를 가진 클래스 사용하기