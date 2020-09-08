#include <iostream>

using namespace std;

template <class T> class shared_ptr{
    public:
        shared_ptr(T* t);
        shared_ptr(const shared_ptr&);
        shared_ptr& operator= (const shared_ptr &p)
        {
            cout << "Before assign: " << *p << "to" << *t << endl;
            T(p).swap(*this); //copy-and-swap idiom
            cout << "after assign: " << *p << " , " << *t << endl;
        };
        ~shared_ptr();

        T& operator*();
        T* operator->();
        size_t count ();
};

void main()
{
    shared_ptr<string> sp(new string("Hello world"));

    if(sp)
        cout << "SP Contains" << *sp << endl;
}