
/*22. �� ����� ���������� queue ���������� ����� ����� ����� �� ���������� �����.
�������� �������� ��������� �������� � �����,
��������� �������� � �����, ��������� ��� �������� ����� �� �����, ���������� ������� �������� �����.*/

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#include <Windows.h>
using namespace std;
int key = 0;
template<class T>
class Queue {
protected:
    queue<T> queue_main;
    queue<T> queue_temporary;
public:
    Queue()
    {
        ;
    }

    Queue(int data)
    {
        for (int i = 0; i < data; i++)
        {
            queue_main.push(i + 1);
        }
    }
    ~Queue()
    {
        cout << " destuctor " << endl;
    }

    void operator += (T element)
    {
        queue_main.push(element);
    }
    void operator -- (int)
    {
        queue_main.pop();
    }
    friend istream& operator >> (istream& in, Queue<T>& obj)
    {
        cout << " ������ ������� �������� ����� : ";
        cin >> key;
        if (key < 1)
        {
            cout << "����������� ������� �������";
            exit(0);
        }
        else
        {
            T elem;
            while (key > 0)
            {
                in >> elem;
                obj.queue_main.push(elem);
                key--;
                if (in.eof())
                {
                    break;
                }
            }
            return in;

        }
    }

    friend ostream& operator << (ostream& os, Queue<T>& obj)
    {
        int len = 0;
        obj.queue_temporary = obj.queue_main;
        while (!obj.queue_temporary.empty())
        {
            len++;
            cout << " ";
            os << obj.queue_temporary.front() << endl;
            obj.queue_temporary.pop();
        }
        return os;
    }
};


int main()
{
    system("chcp 1251");
    system("cls");
    string name1 = "Int.txt";
    string name2 = "String.txt";
    fstream int_file;
    fstream string_file;
    int_file.open(name1, fstream::in);
    string_file.open(name2, fstream::in);
    Queue <int> intQueue;
    Queue <string> stringQueue;
    int_file >> intQueue;
    string_file >> stringQueue;
    int_file.close();
    string_file.close();
    intQueue--;
    stringQueue--;
    cout << endl;
    int ilen = 0; int  slen = 0;
    cout << "����� ����� �����: " << endl;
    cout << intQueue;
    cout << "�����  ���������� �����: " << endl;
    cout << stringQueue;
    int_file.open(name1, fstream::out);
    string_file.open(name2, fstream::out);
    int_file << intQueue;
    string_file << stringQueue;
    int_file.close();
    string_file.close();
    cout << endl;
    return 0;
}
