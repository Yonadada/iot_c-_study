//======= ref1.cpp========
//#include <iostream>
//
//void change_val(int* p) {
//	*p = 20; // �����͸� ���� num�� ���� ����
//}
//
//int main() {
//
//	int num = 10;
//	std::cout << num << std::endl;
//
//	//change_val(num);
//	//num �����͸� �����ϰ� ���� ���
//	change_val(&num);
//	std::cout << num << std::endl;
//
//	return 0;
//}
//======= ref1.cpp========

#include <iostream>

//              (int&& p) -> change_val(10); ����� �������� ���� / c++���� ����
void change_val(int& p) {
	p = 20;
}

int main() {

	int num = 10;
	std::cout << num << std::endl;

	change_val(num);
    //change_val(10); //����� �������� �� �� �ִ�
	std::cout << num << std::endl;
	return 0;
}
/*
    - int n;
      �� �Ϲ� int ���� ����

    - int* pn;
      �� int�� �����͸� ����ų �� �ִ� ������ ���� ����
         (�޸� �ּҸ� ������)

    - int& rn;
      �� int�� ������ ���� ���۷���(������) ����
         (�ٸ� ������ ���� ������ ��)

   (lvalue: ����)int n = 10(rvalue: ���ͷ�, ����);
    n = n2;
    10 = n2;// ���� �߻�~!
	

*/