#ifndef OLISTTYPE_H
#define OLISTTYPE_H
#include "ListType.h"

template <class T>
class OListType: public ListType<T>
{
    public:
        OListType(size_t = 10);
        bool insert(const T&);
        bool erase(const T&);
        bool find(const T&) const;
};

template <class T>
OListType<T>::OListType(size_t n) : ListType<T>::ListType(n){}

template <class T>
bool OListType<T>::insert(const T& item)
{
    int i,j;
    if(this->full())
    {
        try
        {
            T* temp = new T[this->capacity*2];
            
            for(int i = 0; i < this->count; ++i)
                temp[i] = this->list[i];
            temp[this->count] = item;
            ++this->count;
            delete [] this->list;
            this->list=temp;
        }
        catch(std::bad_alloc)
        {
            return false;
        }
    }
    else
    {
        this->list[this->count] = item;
        this->count++;
    }
    
    for(i = 1; i < this->count - 1; ++i)
        {
            for(j = 0; j < this->count - i; ++j)
            {
                if(this->list[j] > this->list[j+1])
                    std::swap(this->list[j], this ->list[j+1]);
            }
        }
    
    return true;
}
template <class T>
bool OListType<T>::erase(const T& item)
{
    for(size_t i = 0; i < this->count;++i)
    {
        if(this->list[i] == item)
        {
            size_t a,b;
            if(i == this->count-1)
                --this->count;
            else
            {
                std::swap(this->list[i], this->list[this->count-1]);
                --this->count;
            }

            for(a = 1; a < this->count -1; ++a)
            {
                for(b = 0; b < this->count - a; ++b)
                {
                    if(this->list[b] > this->list[b+1])
                        std::swap(this->list[b], this->list[b+1]);
                }
            }

            return true;
        }
    }
    return false;
}
template <class T>
bool OListType<T>::find(const T& item) const
{
    for(size_t i = 0; i < this -> count; i++)
    {
        if(this -> list[i] == item)
            return true;
    }
    return false;
}
#endif
