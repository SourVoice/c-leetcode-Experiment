//ϣ�������ֵ���
#include <iostream>
#include <process.h>
using namespace std; //ʹ�������ռ�ʱ��Ҫ��ͷ�ļ��е�.hȥ��
#define N 50
void shell_sort(int a[], int len)
{
    int h, i, j, temp;
    for (h = len / 2; h > 0; h = h / 2) //��������
    {
        for (i = h; i < len; i++) //���forѭ������ǰ���ֱ�Ӳ�������
        {
            temp = a[i];
            for (j = i - h; (j >= 0 && temp < a[j]); j -= h) //ѭ����ӡ�����ÿ��Ԫ��
            {
                a[j + h] = a[j];
            }
            a[j + h] = temp;
        }
    }
}

void print_array(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << "";
    }
    cout << endl;
}

void main()
{
    int a[N];
    int b;
    int M;
    cout << "������Ҫ�������Ŀ" << endl;
    cin >> M;

    cout << "������Ҫ�������" << endl;
    for (int i = 0; i < M; i++)
    {
        cin >> b;
        a[i] = b;
    }
    cout << "beforeshellsort:";
    print_array(a, M);
    shell_sort(a, M); //����shell����
    cout << "aftershellsort:";
    print_array(a, M);
    // return0;
    system("pause");
}