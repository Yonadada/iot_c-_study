#include <stdio.h>

// ���� ���� �� Data Segment�� �����
int a;
const int global_c = 100;
// const ���������� Data Segment�� ����� (�б� �������� ��ġ�� �� ����)

// �Լ� �� Code Segment�� �����
void func() {
    printf("function: %p\n", func);
    // �Լ� �̸��� �Լ� �ڵ尡 ����� �޸��� ���� �ּҸ� �ǹ���
    // �迭 �̸��� �迭�� ����� �޸��� ���� �ּҸ� �ǹ���
}

int func2() {
    return 1;
}

int main()
{
    /*** [���� ����� �ڷ���] ***/
    int b = 100;
    // int�� ������ ������ �� �ִ� �ڷ���(������ Ÿ��)
    // b�� main �Լ� �ȿ��� ����� ���� ���� �� Stack�� �����

    /*** [static ����] ***/
    static int c;
    // static�� ���̸� ���� c�� ���α׷��� ���� ������ ���� ������
    // (�Լ��� ���� �� ����ŵ� c�� ���� ������)
    // static�� ��������ó�� Data Segment�� ���������,
    // ���� static ������ �ش� �Լ� �ȿ����� ���� ����

    /*** [const ���] ***/
    const int d = 10;
    // const�� ���̸� d�� ���� �ٲ� �� ���� ����� ��
    // ������ �� �ݵ�� �ʱⰪ�� �־�� ��
    // ���� const ������ Stack�� �����

    // d = 11; 
    // �� ���� �߻�!
    // �� const�� ������ ������ ���� �ٲ� �� ���ٴ� ��

    /*** [�����Ϳ� const] ***/

    // const int* pb;
    // �� pb�� int�� ���� ����Ű�� ������
    // �� pb�� ����Ű�� ���� �ٲ� �� ���� (�б� ����)
    // pb = &b; 
    // �� pb�� b�� �ּҸ� ���� ����

    // int c = 200;
    // const int* const ppb = &b;
    // �� ppb�� b�� �ּҸ� �����ϴ� ������
    // �� ppb�� ����Ű�� ���� �ٲ� �� ����,
    //    �ٸ� �ּҸ� ����Ű���� ������ ���� ����

    // int* const ppb = &b;
    // �� ppb�� b�� �ּҸ� �����ϴ� ������
    // �� ppb�� �ٸ� �ּҸ� ����Ű���� �ٲ� ���� ������,
    //    ����Ű�� ���� �ٲ� �� ����

    // *ppb = 1000;
    // �� �����͸� ���� b�� ���� 1000���� �ٲ� (����)

    // ppb = &c;
    // �� ���� �߻� (ppb�� �ٸ� ���� ����Ű���� �� �� ����)

    /*** [�迭] ***/
    char arr[20] = "Hello";
    // char�� ���� �ϳ��� ������ �� �ִ� �ڷ���
    // char arr[20]�� ���� 20���� ������ �� �ִ� �迭
    // "Hello"��� ���ڿ��� arr�� ������
    // �迭 �̸�(arr)�� �迭�� ����� �޸��� ���� �ּҸ� �ǹ���

    func();
    printf("local b: %p\n", &b);
    // ���� ���� b �� Stack �ּ�

    printf("static c: %p\n", &c);
    // static ���� ���� c �� Data Segment �ּ�

    printf("const d: %p\n", &d);
    // const ���� ���� d �� Stack �ּ�

    printf("array p: %p\n", arr);
    // �迭 �̸��� �迭�� ���� �ּ� �� Stack �ּ�

    printf("global a: %p\n", &a);
    // ���� ���� a �� Data Segment �ּ�

    printf("global c: %p\n", &global_c);
    // const ���� ���� global_c �� Data Segment �ּ� (�б� �������� ��ġ�� �� ����)

    printf("func2(): %p\n", func2);
    // �Լ� �̸� �� Code Segment �ּ�

    /*
        [Memory Segment Summary]

        �� Code Segment
            - �Լ����� ����� (main, func, func2 ��)
            - �б� �������� �����Ǿ� ������ ��ȭ��

        �� Data Segment
            - ���� ����, static ���� ����
            - �ʱⰪ �ִ� ���� �� Initialized Data Segment
            - �ʱⰪ ���� ���� �� BSS Segment

        �� Heap
            - malloc ������ �������� �Ҵ�
            - ���α׷� ���� �� ũ�Ⱑ ����

        �� Stack
            - ���� ����, �Ű����� ����
            - �Լ� ȣ�� �� �׿��ٰ� �Լ� ���� �� �ڵ� ����
    */
    return 0;
}
