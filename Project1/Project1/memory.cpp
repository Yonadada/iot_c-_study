#include <stdio.h>

// 전역 변수 → Data Segment에 저장됨
int a;
const int global_c = 100;
// const 전역변수도 Data Segment에 저장됨 (읽기 전용으로 배치될 수 있음)

// 함수 → Code Segment에 저장됨
void func() {
    printf("function: %p\n", func);
    // 함수 이름은 함수 코드가 저장된 메모리의 시작 주소를 의미함
    // 배열 이름도 배열이 저장된 메모리의 시작 주소를 의미함
}

int func2() {
    return 1;
}

int main()
{
    /*** [변수 선언과 자료형] ***/
    int b = 100;
    // int는 정수를 저장할 수 있는 자료형(데이터 타입)
    // b는 main 함수 안에서 선언된 지역 변수 → Stack에 저장됨

    /*** [static 변수] ***/
    static int c;
    // static을 붙이면 변수 c는 프로그램이 끝날 때까지 값을 유지함
    // (함수가 여러 번 실행돼도 c의 값이 유지됨)
    // static은 전역변수처럼 Data Segment에 저장되지만,
    // 지역 static 변수는 해당 함수 안에서만 접근 가능

    /*** [const 상수] ***/
    const int d = 10;
    // const를 붙이면 d는 값을 바꿀 수 없는 상수가 됨
    // 선언할 때 반드시 초기값을 넣어야 함
    // 지역 const 변수는 Stack에 저장됨

    // d = 11; 
    // → 오류 발생!
    // → const로 선언한 변수의 값은 바꿀 수 없다는 뜻

    /*** [포인터와 const] ***/

    // const int* pb;
    // → pb는 int형 값을 가리키는 포인터
    // → pb가 가리키는 값은 바꿀 수 없음 (읽기 전용)
    // pb = &b; 
    // → pb에 b의 주소를 저장 가능

    // int c = 200;
    // const int* const ppb = &b;
    // → ppb는 b의 주소를 저장하는 포인터
    // → ppb가 가리키는 값도 바꿀 수 없고,
    //    다른 주소를 가리키도록 변경할 수도 없음

    // int* const ppb = &b;
    // → ppb는 b의 주소를 저장하는 포인터
    // → ppb가 다른 주소를 가리키도록 바꿀 수는 없지만,
    //    가리키는 값은 바꿀 수 있음

    // *ppb = 1000;
    // → 포인터를 통해 b의 값을 1000으로 바꿈 (가능)

    // ppb = &c;
    // → 오류 발생 (ppb가 다른 곳을 가리키도록 할 수 없음)

    /*** [배열] ***/
    char arr[20] = "Hello";
    // char은 문자 하나를 저장할 수 있는 자료형
    // char arr[20]은 문자 20개를 저장할 수 있는 배열
    // "Hello"라는 문자열을 arr에 저장함
    // 배열 이름(arr)은 배열이 저장된 메모리의 시작 주소를 의미함

    func();
    printf("local b: %p\n", &b);
    // 지역 변수 b → Stack 주소

    printf("static c: %p\n", &c);
    // static 지역 변수 c → Data Segment 주소

    printf("const d: %p\n", &d);
    // const 지역 변수 d → Stack 주소

    printf("array p: %p\n", arr);
    // 배열 이름은 배열의 시작 주소 → Stack 주소

    printf("global a: %p\n", &a);
    // 전역 변수 a → Data Segment 주소

    printf("global c: %p\n", &global_c);
    // const 전역 변수 global_c → Data Segment 주소 (읽기 전용으로 배치될 수 있음)

    printf("func2(): %p\n", func2);
    // 함수 이름 → Code Segment 주소

    /*
        [Memory Segment Summary]

        ▷ Code Segment
            - 함수들이 저장됨 (main, func, func2 등)
            - 읽기 전용으로 설정되어 보안을 강화함

        ▷ Data Segment
            - 전역 변수, static 변수 저장
            - 초기값 있는 변수 → Initialized Data Segment
            - 초기값 없는 변수 → BSS Segment

        ▷ Heap
            - malloc 등으로 동적으로 할당
            - 프로그램 실행 중 크기가 변함

        ▷ Stack
            - 지역 변수, 매개변수 저장
            - 함수 호출 시 쌓였다가 함수 종료 시 자동 해제
    */
    return 0;
}
