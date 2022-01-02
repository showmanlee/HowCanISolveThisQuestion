// 한국이 그리울 땐 서버에 접속하지
// https://www.acmicpc.net/problem/9996

using System;

class Program {
	static void Main(string[] args) {
		int n = int.Parse(Console.ReadLine());
		string p = Console.ReadLine();
		for (int i = 0; i < n; i++) {
			string s = Console.ReadLine();
			if (s.Length < p.Length - 1)
				Console.WriteLine("NE");
			else if (s.Substring(0, p.Split('*')[0].Length) == p.Split('*')[0] && s.Substring(s.Length - p.Split('*')[1].Length, p.Split('*')[1].Length) == p.Split('*')[1])
				Console.WriteLine("DA");
			else
				Console.WriteLine("NE");
		}
	}
}

// *은 단 하나, 주어지는 문장의 길이는 패턴 - 1 이상이어야 함(* 앞뒤의 문자는 겹쳐질 수 없음)
// 기분 꿀꿀할 땐 C#으로 풀어버리기~
// 그나저나 이게 브루트포스라고