// 707. �������
#include <string>
#include <stack>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ʹ����������
class MyLinkedList
{
public:
    MyLinkedList()
    {
    }

    int get(int index)
    {
        return arr.size() > index ? arr[index] : -1;
    }

    void addAtHead(int val)
    {
        arr.insert(arr.begin(), val);
    }

    void addAtTail(int val)
    {
        arr.push_back(val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
            addAtHead(val);
        else if (index == arr.size())
            addAtTail(val);
        else if (index > arr.size())
            return;
        else
            arr.insert(arr.begin() + index, val);
    }

    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < arr.size())
            arr.erase(arr.begin() + index);
    }

private:
    vector<int> arr;
};
// TODO: ʹ������ʵ��

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */