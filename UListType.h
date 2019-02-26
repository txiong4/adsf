#ifndef ULISTTYPE_H
#define ULISTTYPE_H
#include "ListType.h"

template<class T>
class UListType : public ListType<T>
{
    public:
        UListType(size_t = 10);
        virtual bool insert(const T&); 
        virtual bool erase(const T&); 
        virtual bool find(const T&) const;
};

template<class T>
UListType::UListType<T>(size_t n) : ListType<T>::ListType(n) { }

// insert an "item" at the end of the list. The list is unorder.
//check if the list is full
//copy it onto another list
//delete 
//return false if not inserted
template <class T>
bool UListType<T>::insert(const T& item)
{

    if(this->full())
    {
        try
        {
            T* temp = new T[capacity*2];
            
            for(int i = 0; i < this->count; ++i)
            {
                temp[i] = this->list[i] 
            }
            temp[this->count] = item;
            ++this->count;
            delete [] list;
            list = temp;
        }
        catch(std::bad_alloc)
        {
            return false;
        }
    }
    else
    {
        this->list[count] = item;
        this->count++;
    }
    return true;
}

template <class T>
bool UListType<T>::erase(const T& item)
{
    for(size_t i = 0; i < this->count; i++)
    {
        if(this->list[i] == item)
        {
            if(i == this->count-1)
                --this->count;
            else
            {
                std::swap(list[i], list[count-1]);
                --this->count;
            }
            return true
        }
    }
    return false;
}

template <class T>
bool UListType<T>::find(const T& item) const
{
    for(size_t i = 0; i < this->count; i++)
    {
        if(this->list[i] == item)
            return true;
    }
    return false;
}

#endif