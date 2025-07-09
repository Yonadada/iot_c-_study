//======= ref1.cpp========
//#include <iostream>
//
//void change_val(int* p) {
//	*p = 20; // 포인터를 통해 num의 값을 변경
//}
//
//int main() {
//
//	int num = 10;
//	std::cout << num << std::endl;
//
//	//change_val(num);
//	//num 데이터를 변경하고 싶은 경우
//	change_val(&num);
//	std::cout << num << std::endl;
//
//	return 0;
//}
//======= ref1.cpp========

#include <iostream>

//              (int&& p) -> change_val(10); 상수도 참조변수 가능 / c++에만 있음
void change_val(int& p) {
	p = 20;
}

int main() {

	int num = 10;
	std::cout << num << std::endl;

	change_val(num);
    //change_val(10); //상수도 참조변수 할 수 있다
	std::cout << num << std::endl;
	return 0;
}
/*
    - int n;
      → 일반 int 변수 선언

    - int* pn;
      → int형 데이터를 가리킬 수 있는 포인터 변수 선언
         (메모리 주소를 저장함)

    - int& rn;
      → int형 변수에 대한 레퍼런스(참조자) 선언
         (다른 변수의 별명 역할을 함)

   (lvalue: 변수)int n = 10(rvalue: 리터럴, 변수);
    n = n2;
    10 = n2;// 오류 발생~!
	

*/