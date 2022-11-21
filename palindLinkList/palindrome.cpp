#include <iostream>
#include <math.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *n)
{

    while (n != NULL)
    {
        printf(" %d ", n->val);
        n = n->next;
    }
}

bool checkPalindrome(struct ListNode *n)
{

    int length = 0;
    int toStore1 = 0;
    int toStore2 = 0;
    while (n != NULL)
    {
        toStore1 = toStore1 * 10 + n->val;
        toStore2 = (n->val) * pow(10, length) + toStore2;
        n = n->next;
        length++;
    }
    if (toStore1 == toStore2)
    {
        return true;
    }
    return false;
}

int main()
{

    ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *one = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *two = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *three = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *four = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 1;
    one->val = 2;
    two->val = 3;
    three->val = 2;
    four->val = 1;

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    if (checkPalindrome(head))
        cout << "PALINDROM,TATAAA";

    return 0;
}