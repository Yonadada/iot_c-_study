#include <stdio.h>

// 함수 선언 (Prototype)
// 함수 선언은 함수의 이름, 매개변수, 반환형을 정의하는 부분
void func();
void func1(char arg);
int func2(int);

int main(int arg, char** argv)
{
    char ch = 'a';  // 문자 하나 저장
    int num = 10;   // 정수 저장

    func();          // 함수 호출. ()가 붙으면 함수 호출 의미. 안 붙으면 함수 포인터.
    func1(ch);       // 함수 호출. char 타입의 인자를 전달. 매개변수로 문자 전달

    int res = func2(num);
    // func2의 반환값은 임시값이므로 이름이 없는 임시 객체처럼 쓰인다.

    res += 1;

    return 0;
}

// 함수 정의. 반환형 void, 매개변수 없음
void func()
{
    printf("Hello, World!\n");
}

// 함수 정의. 매개변수 char, 반환형 void
void func1(char arg)
{
    printf("%c Hello\n", arg);
}

// 함수 정의. 매개변수 int, 반환형 int
int func2(int n)
{
    return 0;
}