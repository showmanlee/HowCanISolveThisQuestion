// Day 21: Generics
// https://www.hackerrank.com/challenges/30-generics/problem
import java.util.*;

class Printer <T> {
    
    public void printArray(T[] arr){
        for (T t : arr)
            System.out.println(t);   
    }
}

public class Generics {
    
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] intArray = new Integer[n];
        for (int i = 0; i < n; i++) {
            intArray[i] = scanner.nextInt();
        }

        n = scanner.nextInt();
        String[] stringArray = new String[n];
        for (int i = 0; i < n; i++) {
            stringArray[i] = scanner.next();
        }
        
        Printer<Integer> intPrinter = new Printer<Integer>();
        Printer<String> stringPrinter = new Printer<String>();
        intPrinter.printArray( intArray  );
        stringPrinter.printArray( stringArray );
        if(Printer.class.getDeclaredMethods().length > 1){
            System.out.println("The Printer class should only have 1 method named printArray.");
        }
    } 
}

// 어떤 타입이든 받을 수 있는 제네릭 함수 만들기
// 저런 식으로 제네릭 클래스를 만들기 
// Python은 어차피 자료형을 명시받지 않으므로 제네릭 개념이 없음