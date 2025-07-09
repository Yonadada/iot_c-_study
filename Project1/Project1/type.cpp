#include <stdio.h>

int main() {

    // 문법 오류:
    // '0x7f' ← 홑따옴표로 싸면 문자 리터럴(char)로 취급되어 값이 잘못됨.
    // → 0x7f로만 써야 숫자 값으로 들어감.
    // 아래 코드는 잘못된 코드니까 수정해야 해!
    unsigned char uch = 0x7f;    // 16진수 0x7f = 127 (0b 0111 1111)
    char ch = 0x7f;              // signed char로도 127 (양수)

    unsigned char uch1 = 0x9f;   // 16진수 0x9f = 159 (0b 1001 1111)
    char ch1 = 0x9f;             // signed char에 0x9f 넣으면 음수 값으로 해석됨

    printf("uch: %#x, ch: %#x\n", uch, ch);
    // uch → 0x7f → 127 출력
    // ch → 0x7f → 127 출력

    printf("uch1: %#x, ch1: %#x\n", uch1, ch1);
    // uch1 → 0x9f → 159 출력
    // ch1 → signed char로 음수로 해석됨
    //      0x9f = 1001 1111 → 2의 보수 음수: -97
    //      출력 시 정수 승격되어 4바이트로 처리되며 0xffffff9f로 찍힐 수 있음

    unsigned char uch2 = 0x11f;
    char ch2 = 0x11f;

    // 0x11f = 0b 1_0001_1111 = 287
    // 하지만 unsigned char는 1바이트(8bit)밖에 못 담음.
    // 따라서 상위 비트 잘려서 값은:
    // 0x11f & 0xff → 0x1f (0b 0001 1111) = 31

    // signed char도 마찬가지로 잘려서 0x1f 저장됨.

    printf("uch2: %#x, ch2: %#x\n", uch2, ch2);
    // 둘 다 0x1f 출력 (31)

    uch = uch << 1;
    ch = ch << 1;
    printf("uch << 1: %#x\nch << 1: %#x\n", uch, ch);

	uch1 = uch1 >> 1;       //0b 1001 1111 -> 0b 0100 1111 = 0x4f (79)
	ch1 = ch1 >> 1;     // 0b 1001 1111 -> 0b 0100 1111 = 0x4f (79)
	                    // signed char로 음수로 해석되면 -97 >> 1 = -49
	                    // 출력 시 정수 승격되어 4바이트로 처리되며 0xffffff4f로 찍힐 수 있음  
	printf("uch1 >> 1: %#x\nch1 >> 1: %#x\n", uch1, ch1);
    return 0;
}