// Day 21: Generics
// https://www.hackerrank.com/challenges/30-generics/problem

#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <typename T>

void printArray(vector<T> arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\n';   
}

int main() {
	int n;
	
	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}
	
	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}

	printArray<int>(int_vector);
	printArray<string>(string_vector);

	return 0;
}

// 어떤 타입이든 받을 수 있는 제네릭 함수 만들기
// template <typename T> 후 함수에서 T 활용
// Python은 어차피 자료형을 명시받지 않으므로 제네릭 개념이 없음