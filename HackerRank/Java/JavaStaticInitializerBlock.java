// Java Static Initializer Block
// https://www.hackerrank.com/challenges/java-static-initializer-block/problem

public class Solution {

static int B;
static int H;
static boolean flag;

static{
    Scanner scanner = new Scanner(System.in);
    B = scanner.nextInt();
    H = scanner.nextInt();
    if (B > 0 && H > 0)
        flag = true;
    else{
        flag = false;
        System.out.println("java.lang.Exception: Breadth and height must be positive");
    }
}

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class

// 클래스/정적 초기화 블록
// 각종 static 변수들을 초기화할 때 사용하는 블록, 클래스 자체를 로딩하는 한번 실행됨.
// 여기 안에서 초기화된 static 변수들은 인스턴스 변수나 메소드에 영향을 주지 못함