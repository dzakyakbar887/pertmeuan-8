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

int main()
{
    linkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
            case '1':
            mhs.addNode();
            break;

            case '2':
            if (mhs.listEmpty())
            {
                cout << "\nlist kosong" << endl;
                break;
            }

            cout << "\nMasukkan no mahasiswa yang akan dihapus : ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
            cout << "\nData tidak ditemukan" << endl;
            else
            cout << "\nData dengan nomor mahasiswa " << nim << "berhasil dihapus\n";
            break;

            case '3':
            mhs.traverse();
            break;

            case '4':
            {
                if (mhs.listEmpty())
                {
                    cout << "\nList kosong\n";
                    break;
                }

                Node *previous, *current;
                cout << "\nMasukkan no mahasiswa yang dicari: ";
                cin >> nim;

                if (mhs.searc(nim, previous, current) == false)
                cout << "\nData tidak ditemukan\n";
                else
                {
                    cout << "\nData ditemukan\n";
                    cout << "Nim mahasiswa: " << current->noMhs << endl;
                }
                break;
            }

            case '5':
            break;

            default:
            cout << "\nPilihan salah!\n";
        }

    } while (ch != '5');

    return 0;
}