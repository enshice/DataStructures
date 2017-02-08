#include <stdlib.h>

namespace enshice
{
template<typename Object>
class List
{

private: 
    struct Node
    {
        Object data;
        Node* prev;
        Node* next;

        Node(const Object& d = Object(), Node* p = NULL, Node* n = NULL)
        : data(d), prev(p), next(n) {}
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current(NULL) {}

        const Object& operator*() const
        {
            return retrieve();
        }

        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            return current != rhs.current;
        }

    protected:
        Node* current;

        Object& retrieve() const
        {
            return current->data;
        }

        const_iterator(Node *p): current(p) {}
        
        friend class List<Object>;
    };

    /*
    class iterator : public const_iterator
    {
    public:
        iterator(){}

        Object& operator*()
        {
            return retrieve();
        }

        const Object& operator*() const
        {
            return const_iterator::operator*();
        }

        iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node* p) : const_iterator(p) {}

        friend class List<Object>;
    };
    */

public:
    List() {}

    List(const List& rhs) {}

    ~List() {}

    const List& operator=(const List& rhs) {}

private:
    int theSize;
    Node* head;
    Node* tail;
};
}