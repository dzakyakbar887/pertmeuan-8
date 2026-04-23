#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node* next;
};

class linkedList
{
    Node *start;

    public:
    linkedList()
    {
        start = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nMasukkan nomor mahasiswa: ";
        cin >> nim;

        Node *nodebaru = new Node;
        nodebaru->noMhs = nim;

        if (start == NULL || nim <= start->noMhs)
        {
            if (start != NULL && nim == start->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }

            nodebaru->next = start;
            start = nodebaru;
            return;
        }

            Node *previous = start;
            Node *current = start;

            while (current != NULL && nim >= current->noMhs)
            {
                if (nim == current->noMhs)
                {
                    cout << "\nDuplikasi noMhs tidak diijinkan\n";
                    return;

                }
                    previous = current;
                    current = current->next;
            }

            nodebaru->next = current;
            previous->next = nodebaru;
    }

    bool listEmpty()
    {
        return (start == NULL);
    }

    bool searc(int nim, Node *&previous, Node *&current)
    {
        previous = start;
        current = start;

        while (current != NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!searc(nim, previous, current))
        return false;

        if (current == start)
        start = start->next;
        else
        previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah: \n";
            Node *currentNode = start;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};