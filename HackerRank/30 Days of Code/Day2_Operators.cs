// Day 2: Operators
// https://www.hackerrank.com/challenges/30-operators/problem

using System;

class Solution {

    // Complete the solve function below.
    static void solve(double meal_cost, int tip_percent, int tax_percent) {
        double res = meal_cost + (tip_percent / 100.0 * meal_cost) + (tax_percent / 100.0 * meal_cost);
        Console.WriteLine(Math.Round(res));
    }

    static void Main(string[] args) {
        double meal_cost = Convert.ToDouble(Console.ReadLine());

        int tip_percent = Convert.ToInt32(Console.ReadLine());

        int tax_percent = Convert.ToInt32(Console.ReadLine());

        solve(meal_cost, tip_percent, tax_percent);
    }
}

// 고기 가격, 팁, 세금 비율이 주어졌을 때 최종 구매가를 반올림하여 출력하기
// 이 언어에서 round 함수를 쓰는 법을 아나요? - Math.Round 사용