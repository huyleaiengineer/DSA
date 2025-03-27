#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val; /// Data
    ListNode *next; /// Pointer to next node

    ListNode(): val(0), next(nullptr) {} /// Constructor for no data
    ListNode(int x): val(x), next(nullptr) {}  /// Constructor for data
    ListNode(int x, ListNode *next): val(x), next(next) {} /// Constructor for data and next pointer

};


/// List of functions


/// Check list empty

bool isEmpty(ListNode *head)
{
    return head->next == nullptr;
}

/// Insert head
void ListInsertHead(ListNode *&head, int val)
{
    ListNode *tmp = new ListNode(val);
    tmp->next = head;
    head = tmp;
}

/// Remove head
void ListInsertTail(ListNode *&head)
{
    if (!isEmpty(head))
        head = head->next;
    else
        cout << "Can not remove any more because of empty list!\n";
}


void ListTreverse( ListNode *L)
{
    for (ListNode *head = L; head->next != nullptr; head = head->next)
    {
        cout << head->val << ' ';
    }
    cout << '\n';
}

int main()
{
    ListNode *L = new ListNode();

    int arr[] = {10, 20, 30, 40, 50};

    for (int i : arr)
    {
       ListInsertHead(L, i);
    }

    if (!isEmpty(L))
        ListTreverse (L);
    else
        cout << "Empty List\n";

    ListInsertTail(L);
    ListTreverse (L);
    ListInsertTail(L);
    ListTreverse (L);
    ListInsertTail(L);
    ListTreverse (L);
    ListInsertTail(L);
    ListTreverse (L);
    ListInsertTail(L);
    ListTreverse (L);
    ListInsertTail(L);
    ListTreverse (L);


    return 0;
}
