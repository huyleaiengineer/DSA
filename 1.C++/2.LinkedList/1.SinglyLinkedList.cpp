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
bool isEmpty(ListNode *head);
void ListInsertHead(ListNode *&head, int val);
void ListRemoveHead(ListNode *&head);

/// Check list empty

bool isEmpty(ListNode *head)
{
    return head->next == nullptr;
}

/// ListSearch
ListNode *ListSearch(ListNode *head, int key)
{
    ListNode *x = new ListNode();
    for (x = head; !isEmpty(x); x = x->next)
        if (x->val == key)
            return x;
    return x;
}


/// Insert head
void ListInsertHead(ListNode *&head, int val)
{
    ListNode *tmp = new ListNode(val);
    tmp->next = head;
    head = tmp;
}

/// Remove head
void ListRemoveHead(ListNode *&head)
{
    if (!isEmpty(head))
        head = head->next;
    else
        cout << "Can not remove any more because of empty list!\n";
}

/// List Traverse
void ListTreverse( ListNode *L)
{
    for (ListNode *head = L; head->next != nullptr; head = head->next)
    {
        cout << head->val << ' ';
    }
    cout << '\n';
}

/// ListDelete or ListInsert at any position --> use ListSearch to identify what node to be inserted/deleted



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



    ListNode *x1 = ListSearch(L, 8);
    if (!isEmpty(x1))
        cout << "Existing node have key is " << x1->val << '\n';
    else
         cout << "Not Existing node have key \n";

    ListNode *x2 = ListSearch(L, 10);
     if (!isEmpty(x2))
        cout << "Existing node have key is " << x2->val << '\n';
    else
         cout << "Not Existing node have key \n";


    for (int i = 1; i <= 5; ++i)
    {
        ListRemoveHead(L);
        ListTreverse(L);
    }


    return 0;
}
