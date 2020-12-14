// Day 13: Abstract Classes
// https://www.hackerrank.com/challenges/30-abstract-classes/problem

import java.util.*;

abstract class Book {
    String title;
    String author;
    
    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }
    
    abstract void display();
}

class MyBook extends Book{
    int price;
    
    MyBook(String t, String a, int p){
        super(t, a);
        this.price = p;
    }
    
    @Override
    public void display(){
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
    }
}

public class Solution {
   
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        String author = scanner.nextLine();
        int price = scanner.nextInt();
        scanner.close();

        Book book = new MyBook(title, author, price);
        book.display();
    }
}

// 추상 클래스를 상속받은 클래스 생성 및 사용
// Java에서 추상 메서드 생성 및 해당 클래스를 상속받아 실체화(@Override)