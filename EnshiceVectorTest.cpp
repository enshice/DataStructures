#include "EnshiceVector.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "test EnshiceVector begin" << endl;

    enshice::Vector<int>* v = new enshice::Vector<int>();

    cout << "vector size: " << v->size() << endl;

    v->push_back(1);
    v->push_back(2);
    v->push_back(3);

    cout << "vector size: " << v->size() << endl;
    for(enshice::Vector<int>::iterator iter = v->begin(); iter != v->end(); ++iter)
    {
        cout << "vector element: " << *iter << endl;
    }

    enshice::Vector<int>* v_copy = new enshice::Vector<int>(*v);

    cout << "vector copy size: " << v_copy->size() << endl;

    v_copy->pop_back();
    v_copy->pop_back();
    cout << "vector size: " << v->size() << endl;
    cout << "vector copy size: " << v_copy->size() << endl;

    for(int i = 4; i <= 100; i++)
    {
        v->push_back(i);
    }

    cout << "vector size: " << v->size() << endl;

    cout << "vector capacity: " << v->capacity() << endl;

    cout << "vector index at 27: " << (*v)[27] << endl;

    cout << "test EnshiceVector end" << endl;
    
    delete v;
    delete v_copy;

    return 0;
}
