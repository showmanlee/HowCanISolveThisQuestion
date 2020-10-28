// Java Currency Formatter
// https://www.hackerrank.com/challenges/java-currency-formatter/problem

public class Solution { 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();
        
        Locale LocaleINDIA = new Locale("en", "IN");
        String us = NumberFormat.getCurrencyInstance(Locale.US).format(payment);
        String india = NumberFormat.getCurrencyInstance(LocaleINDIA).format(payment);
        String china = NumberFormat.getCurrencyInstance(Locale.CHINA).format(payment);
        String france = NumberFormat.getCurrencyInstance(Locale.FRANCE).format(payment);
        
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);
    }
}

// 심지어 Java엔 통화 표시 기능도 있음!
// Locale을 지정해 준 후 실수값을 받아 해당 형태로 표기
// 지금 수준에서는 쓸 일이 많지는 않겠지