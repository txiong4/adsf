#ifndef LISTTYPE_H
#define LISTTYPE_H
#include <cstddef>
#include <ostream>
#include <string>

template<class T>
class ListType
{
    public:
        ListType(size_t = 10);
        ListType(const ListType<T>&);
        virtual ~ListType();
        const ListType<T>& operator = (const ListType<T>&);
        virtual bool insert(const T&) = 0; 
        virtual void eraseAll();
        virtual bool erase(const T&) = 0; 
        virtual bool find(const T&) const = 0;
        size_t size() const;
        bool empty() const;
        bool full() const;
        template<class U>
        friend std::ostream& operator << (std::ostream&, const ListType<U>&);


    protected:
        size_t count = 0 , capacity;
        T* list;

    private:
        void copy(const ListType<T>&); 
};

//overload "=" and copy an array from source
template <class T>
const ListType<T>& ListType<T>::operator=(const ListType<T>& source)
{
    copy(source);
    return this;
}

//deallocate memmory occupied by the arrays.
template <class T>
ListType<T>::~ListType()
{
    delete [] list;
}

template <class T>
ListType<T>::ListType(size_t n)
{
    capacity = n;
    this->list = new T[capacity];
}

//copy array to another array
template <class T>
void ListType<T>::copy(const ListType<T>& source)
{
    this->capacity = source.capacity;
    this->count = source.count;
    this->list = new T[capacity];
    for(size_t i = 0; i < source.count; ++i)
        this->list[i] = source.list[i];
}

// this is a constructor that copies array.
template <class T>
ListType<T>::ListType(const ListType<T>& source)
{
    copy(source);
}

template <class T>
void ListType<T>::eraseAll()
{
    capacity = 0;
}

template <class T>
bool ListType<T>::full() const
{
    if(this->count == this->capacity)
        return true;
    else
        return false;
}

template <class T>
bool ListType<T>::empty() const
{
    return (this->count == 0);
}

template <class T>
size_t ListType<T>::size() const
{
    return this->count;
}

// overload operator "<<" and prints the array
template<class U>
std::ostream& operator << (std::ostream& out, const ListType<U>& source)
{
    if(!source.empty())
    {
        out << source.list[0];
        for(int i = 1; i < source.count; ++i)
            out << "," << source.list[i];
    }
    else
        out << "Empty" << std::endl;
    return out;
}

#endif
