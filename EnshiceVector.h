#include <stdlib.h>

namespace enshice
{
template<typename Object>
class Vector
{
public:
    explicit Vector(int initSize = 0)
    : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
    {
        objects = new Object[theCapacity];
    }

    Vector(const Vector& rhs) : objects(NULL)
    {
        operator=(rhs);
    }

    ~Vector()
    {
        delete [] objects;
    }

    const Vector& operator= (const Vector& rhs)
    {
        if(this != &rhs)
        {
            delete [] objects;
            theSize = rhs.size();
            theCapacity = rhs.capacity();

            objects = new Object[capacity()];
            for(int i = 0; i < size(); ++i)
            {
                objects[i] = rhs.objects[i];
            }
        }
        return *this;
    }

    void resize(int newSize)
    {
        if(newSize > theCapacity)
        {
            reserve( newSize * 2 + 1);
        }
        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if(newCapacity < theSize)
        {
            return;
        }

        Object* oldObjects = objects;
        objects = new Object[newCapacity];
        for(int i = 0; i < size(); ++i)
        {
            objects[i] = oldObjects[i];
        }

        theCapacity = newCapacity;

        delete [] oldObjects;
    }

    Object& operator[](int index)
    {
        return objects[index];
    }

    const Object& operator[](int index) const
    {
        return objects[index];
    }

    bool empty()
    {
        return size() == 0;
    }

    int size() const
    {
        return theSize;
    }

    int capacity() const
    {
        return theCapacity;
    }

    void push_back(const Object& x)
    {
        if(theSize == theCapacity)
        {
            reserve(2*theCapacity);
        }
        objects[theSize++] = x;
    }

    void pop_back()
    {
        theSize--;
    }

    const Object& back() const
    {
        return objects[theSize - 1];
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
        return objects;
    }

    const_iterator begin() const
    {
        return objects;
    }

    iterator end()
    {
        return objects + theSize;
    }

    const_iterator end() const
    {
        return objects + theSize;
    }

    enum { SPARE_CAPACITY = 16 };

private:
    int theSize;
    int theCapacity;
    Object* objects;
};

}