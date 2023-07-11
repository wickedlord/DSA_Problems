#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int x;
    int y;
    Node *next;

    Node(int x, int y, Node *next)
    {
        this->x = x;
        this->y = y;
        this->next = next;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->x << "x"
             << "^" << head->y << " ";
        head = head->next;
    }
    cout << endl;
}

void insertNode(Node *head, int x, int y)
{
    Node *newNode = new Node(x, y, nullptr);
    while (head->next != nullptr)
    {
        head = head->next;
    }

    head->next = newNode;
}

void add(Node *first, Node *second)
{

    Node *result = nullptr;

    while (first && second)
    {

        int x, y;

        if (first->y == second->y)
        {
            x = first->x + second->x;
            y = first->y;
            first = first->next;
            second = second->next;
        }

        else if (first->y > second->y)
        {
            x = first->x;
            y = first->y;
            first = first->next;
        }

        else
        {
            x = second->x;
            y = second->y;
            second = second->next;
        }

        if (result == nullptr)
            result = new Node(x, y, nullptr);
        else
            insertNode(result, x, y);
    }

    while (first)
    {
        if (result == nullptr)
            result = new Node(first->x, first->y, nullptr);
        else
            insertNode(result, first->x, first->y);
        first = first->next;
    }

    while (second)
    {
        if (result == nullptr)
            result = new Node(second->x, second->y, nullptr);
        else
            insertNode(result, second->x, second->y);
        second = second->next;
    }

    printList(result);
}

int main()
{

    Node *head = new Node(5, 2, nullptr);
    insertNode(head, 4, 1);

    Node *head2 = new Node(5, 2, nullptr);
    insertNode(head2, 2, 1);

    add(head, head2);

    return 0;
}