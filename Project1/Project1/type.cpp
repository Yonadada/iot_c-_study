#include <stdio.h>

int main() {

    // ���� ����:
    // '0x7f' �� Ȭ����ǥ�� �θ� ���� ���ͷ�(char)�� ��޵Ǿ� ���� �߸���.
    // �� 0x7f�θ� ��� ���� ������ ��.
    // �Ʒ� �ڵ�� �߸��� �ڵ�ϱ� �����ؾ� ��!
    unsigned char uch = 0x7f;    // 16���� 0x7f = 127 (0b 0111 1111)
    char ch = 0x7f;              // signed char�ε� 127 (���)

    unsigned char uch1 = 0x9f;   // 16���� 0x9f = 159 (0b 1001 1111)
    char ch1 = 0x9f;             // signed char�� 0x9f ������ ���� ������ �ؼ���

    printf("uch: %#x, ch: %#x\n", uch, ch);
    // uch �� 0x7f �� 127 ���
    // ch �� 0x7f �� 127 ���

    printf("uch1: %#x, ch1: %#x\n", uch1, ch1);
    // uch1 �� 0x9f �� 159 ���
    // ch1 �� signed char�� ������ �ؼ���
    //      0x9f = 1001 1111 �� 2�� ���� ����: -97
    //      ��� �� ���� �°ݵǾ� 4����Ʈ�� ó���Ǹ� 0xffffff9f�� ���� �� ����

    unsigned char uch2 = 0x11f;
    char ch2 = 0x11f;

    // 0x11f = 0b 1_0001_1111 = 287
    // ������ unsigned char�� 1����Ʈ(8bit)�ۿ� �� ����.
    // ���� ���� ��Ʈ �߷��� ����:
    // 0x11f & 0xff �� 0x1f (0b 0001 1111) = 31

    // signed char�� ���������� �߷��� 0x1f �����.

    printf("uch2: %#x, ch2: %#x\n", uch2, ch2);
    // �� �� 0x1f ��� (31)

    uch = uch << 1;
    ch = ch << 1;
    printf("uch << 1: %#x\nch << 1: %#x\n", uch, ch);

	uch1 = uch1 >> 1;       //0b 1001 1111 -> 0b 0100 1111 = 0x4f (79)
	ch1 = ch1 >> 1;     // 0b 1001 1111 -> 0b 0100 1111 = 0x4f (79)
	                    // signed char�� ������ �ؼ��Ǹ� -97 >> 1 = -49
	                    // ��� �� ���� �°ݵǾ� 4����Ʈ�� ó���Ǹ� 0xffffff4f�� ���� �� ����  
	printf("uch1 >> 1: %#x\nch1 >> 1: %#x\n", uch1, ch1);
    return 0;
}