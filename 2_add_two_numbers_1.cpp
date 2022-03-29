#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    /* data */
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *answer = nullptr;
    ListNode **curr = &answer; //指向指针的指针,一种间接寻址方式
                               //将answer的地址赋给curr,（64位）
    ListNode *addr1 = l1;
    ListNode *addr2 = l2;
    int carry = 0;
    int sum = 0;

    while (addr1 != nullptr || addr2 != nullptr ||carry>0) //do not use for()
    {
        if (addr1!=nullptr)
        {
            sum+=addr1->val;
            addr1=addr1->next;
        }
        if (addr2!=nullptr)
        {
            sum+=addr2->val;
            addr2=addr2->next;
        }
        sum+=carry;
        carry = sum / 10;
        (*curr) = new ListNode(sum % 10); //每次新建一个node,不用取名
        //*curr 取得是curr地址中的64位内容，**curr 就要取两次地址中的内容
        //这是变量，这是把新建node的地址赋给answer,填满64位
        //https://www.runoob.com/cplusplus/cpp-pointer-to-pointer.html
        curr = &((*curr)->next); //把next本身的地址赋给curr
        //-> 相当于 *，跳转 取内容
        //next本身也是一个指针，赋值可以生成链表
        sum=0;
    }
    return answer;
}