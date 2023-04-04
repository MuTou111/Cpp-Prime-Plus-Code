#include <iostream>
#include <new>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;
};

static chaff *buffer = new chaff[3];

using namespace std;

int main()
{
    chaff *arr = new (buffer) chaff[2];
    for (int i = 0; i < 2; i++)
    {
        strcpy(arr[i].dross, "A");
        arr[i].slag = 1;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << endl
             << &buffer[i] << endl;
        cout << "Dross: " << buffer[i].dross << endl;
        cout << "Slag: " << buffer[i].slag << endl;
    }
    arr = new (buffer + 1) chaff[2];
    for (int i = 0; i < 2; i++)
    {
        strcpy(arr[i].dross, "B");
        arr[i].slag = 2;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << endl
             << &buffer[i] << endl;
        cout << "Dross: " << buffer[i].dross << endl;
        cout << "Slag: " << buffer[i].slag << endl;
    }
    delete[] buffer;
    return 0;
}