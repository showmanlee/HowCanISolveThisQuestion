// Accessing Inherited Functions
// https://www.hackerrank.com/challenges/accessing-inherited-functions/problem

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, B, C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }

		 //Implement this function
		 void update_val(int new_val)
		 {
             int n = new_val;
             while (true){
                 if (val == new_val)
                    break;
                 if (n % 5 == 0){
                     n /= 5;
                     C::func(val);
                 }
                 else if (n % 3 == 0){
                     n /= 3;
                     B::func(val);
                 }
                 else if (n % 2 == 0){
                     n /= 2;
                     A::func(val);
                 }
             }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

// 다중 상속 활용하기
// 정확히는 2, 3, 5를 곱해 원하는 값 만들기를 상속과 참조 매개변수 함수들로 해결하는 것