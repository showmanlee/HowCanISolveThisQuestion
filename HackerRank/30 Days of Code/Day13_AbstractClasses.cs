// Day 13: Abstract Classes
// https://www.hackerrank.com/challenges/30-abstract-classes/problem

using System;
using System.Collections.Generic;
using System.IO;
abstract class Book
{
    
    protected String title;
    protected  String author;
    
    public Book(String t,String a){
        title=t;
        author=a;
    }
    public abstract void display();


}

class MyBook : Book{
    int price;
    public MyBook(string t, string a, int p) : base(t, a){
        price = p;
    }
    public override void display(){
        Console.WriteLine("Title: {0}", title);
        Console.WriteLine("Author: {0}", author);
        Console.WriteLine("Price: {0}", price);
    }
}

class Solution {
    static void Main(String[] args) {
      String title=Console.ReadLine();
      String author=Console.ReadLine();
      int price=Int32.Parse(Console.ReadLine());
      Book new_novel=new MyBook(title,author,price);
      new_novel.display();
    }
}

// 추상 클래스를 상속받은 클래스 생성 및 사용
// C#에서 추상 메서드 생성 및 해당 클래스를 상속받아 실체화(override)