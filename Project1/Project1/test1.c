#include <stdio.h>

// �Լ� ���� (Prototype)
// �Լ� ������ �Լ��� �̸�, �Ű�����, ��ȯ���� �����ϴ� �κ�
void func();
void func1(char arg);
int func2(int);

int main(int arg, char** argv)
{
    char ch = 'a';  // ���� �ϳ� ����
    int num = 10;   // ���� ����

    func();          // �Լ� ȣ��. ()�� ������ �Լ� ȣ�� �ǹ�. �� ������ �Լ� ������.
    func1(ch);       // �Լ� ȣ��. char Ÿ���� ���ڸ� ����. �Ű������� ���� ����

    int res = func2(num);
    // func2�� ��ȯ���� �ӽð��̹Ƿ� �̸��� ���� �ӽ� ��üó�� ���δ�.

    res += 1;

    return 0;
}

// �Լ� ����. ��ȯ�� void, �Ű����� ����
void func()
{
    printf("Hello, World!\n");
}

// �Լ� ����. �Ű����� char, ��ȯ�� void
void func1(char arg)
{
    printf("%c Hello\n", arg);
}

// �Լ� ����. �Ű����� int, ��ȯ�� int
int func2(int n)
{
    return 0;
}