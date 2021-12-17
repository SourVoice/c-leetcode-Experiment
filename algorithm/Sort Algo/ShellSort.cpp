//希尔排序兄弟们
#include <iostream>
#include <process.h>
using namespace std; //使用命名空间时，要将头文件中的.h去掉
#define N 50
void shell_sort(int a[], int len)
{
    int h, i, j, temp;
    for (h = len / 2; h > 0; h = h / 2) //控制增量
    {
        for (i = h; i < len; i++) //这个for循环就是前面的直接插入排序
        {
            temp = a[i];
            for (j = i - h; (j >= 0 && temp < a[j]); j -= h) //循环打印数组的每个元素
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
    cout << "请输入要排序的数目" << endl;
    cin >> M;

    cout << "请输入要排序的数" << endl;
    for (int i = 0; i < M; i++)
    {
        cin >> b;
        a[i] = b;
    }
    cout << "beforeshellsort:";
    print_array(a, M);
    shell_sort(a, M); //进行shell排序
    cout << "aftershellsort:";
    print_array(a, M);
    // return0;
    system("pause");
}