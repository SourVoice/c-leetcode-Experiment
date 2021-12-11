#include <iostream>
using namespace std;
void move_exceute(int here, int there)
{
    cout << " from " << here << " to " << there << endl;
}

int hanoit(int n, int first, int middle, int third)
{
    if (n == 1)
    {
        move_exceute(first, third);
        return 1;
    }
    else
    {
        /*1.将n-1个当作整体, 移到中间*/
        hanoit(n - 1, first, third, middle); //expect bottom to the middle
        /*2.将最底下的移动到第三个*/
        move_exceute(first, third);
        /*3.将上面n-1个移动到c上(从第二个移动到第一个,递归到一时从第一个移到第三个)*/
        hanoit(n - 1, middle, first, third); //bottom to the third
    }
}

int main()
{
    hanoit(3, 1, 2, 3);
    return 0;
}
//unfinished
//update:finished