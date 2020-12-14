// Day 13: Abstract Classes
// https://www.hackerrank.com/challenges/30-abstract-classes/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

class MyBook : Book{
        int price;
    public:
        MyBook(string t, string a, int p) : Book(t, a){
            price = p;
        }
        virtual void display(){
            cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: " << price << '\n';
        }
};

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}

// 추상 클래스를 상속받은 클래스 생성 및 사용
// C++에서 추상 함수가 있는 클래스 상속 및 실체화