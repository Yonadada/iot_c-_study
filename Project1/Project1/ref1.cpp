#include <iostream>

void change_val(int* p) {
	*p = 20; // 포인터를 통해 num의 값을 변경
}

int main() {

	int num = 10; 
	std::cout << num << std::endl;

	//change_val(num);
	//num 데이터를 변경하고 싶은 경우
	change_val(&num);
	std::cout << num << std::endl;

	return 0;
}