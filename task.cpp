#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertBeginning()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Node inserted at beginning.\n";
}

void insertEnd()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Node inserted at end.\n";
}

void insertAfterValue()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int target, value;

    cout << "Enter value after which to insert: ";
    cin >> target;

    Node* temp = head;

    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found.\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> value;

    Node* newNode = createNode(value);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }

    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;

    cout << "Node deleted from beginning.\n";
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;

    cout << "Node deleted from end.\n";
}

void deleteByValue()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node* temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found.\n";
        return;
    }

    if (temp == head)
    {
        deleteBeginning();
        return;
    }

    if (temp == tail)
    {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    cout << "Node deleted successfully.\n";
}

void searchValue()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found at position "
                << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found.\n";
}

void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Forward: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void displayBackward()
{
    if (tail == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail;

    cout << "Backward: ";

    while (temp != NULL)
    {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

void freeList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "DOUBLY LINKED LIST MENU \n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Given Value\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Value\n";
        cout << "7. Search for a Value\n";
        cout << "8. Display the list from beginning to end\n";
        cout << "9. Display the list from end to beginning.\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertAfterValue();
            break;

        case 4:
            deleteBeginning();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            deleteByValue();
            break;

        case 7:
            searchValue();
            break;

        case 8:
            displayForward();
            break;

        case 9:
            displayBackward();
            break;

        case 10:
            freeList();
            cout << "Program exited successfully.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
