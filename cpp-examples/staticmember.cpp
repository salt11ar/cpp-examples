#include <iostream>
#include <list>
#include <vector>
#include <numeric>
using namespace std;

class Parent
{
 public:
     int a;
};

class A : public Parent
{
public:
    A() { cout << "A's Constructor Called " << endl;  }
};

class B : public A
{
    static A a;
public:
    B() { cout << "B's Constructor Called " << endl; }
};

class C : public Parent
{
    static C c;

public:
    C() { cout << "C's Constructor Called" << endl; }

};

template<int N>
class PrintOneToN
{
public:
    static void print()
    {
        PrintOneToN<N-1>::print();  // Note that this is not recursion
        cout << N << endl;
    }
};

template<>
class PrintOneToN<1>
{
public:
    static void print()
    {
        cout << 1 << endl;
    }
};

int arraySum(vector<int> &v)
{
    int initial_sum  = 0;
    return accumulate(v.begin(), v.end(), initial_sum);
}


int main()
{
    const int N = 100;
    PrintOneToN<N>::print();


    string prueba = "Hola que tal";
    const char* chPrueba = prueba.c_str();

    cout << chPrueba << endl;

    list<int> lista;

    lista.insert(lista.begin(), 1);
    lista.insert(lista.end(), 2);
    lista.emplace_back(3);

    cout << "List after emplace_back operation is : ";
    for (int &x : lista) cout << x << " ";
    cout << endl;

    vector<int> v{5 , 10 , 15};
    cout << "suma de array" << arraySum(v);
    return 0;

    B b;
    return 0;
}
