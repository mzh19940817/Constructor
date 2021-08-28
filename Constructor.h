#ifndef CONSTRUCTOR_H_
#define CONSTRUCTOR_H_

template<typename T>
struct AutoPtr4
{
    AutoPtr4(T* ptr = nullptr)
        : ptr(ptr)
    {
    }

    ~AutoPtr4()
    {
        if(this->ptr != nullptr)
        {
            delete this->ptr;
            this->ptr = nullptr;
        }
    }

    AutoPtr4(const AutoPtr4& ptr4) // copy constructor
    {
        this->ptr = new T;
        *this->ptr = *ptr4.ptr;
    }

    AutoPtr4(AutoPtr4&& ptr4) noexcept // move constructor
        : ptr(ptr4)
    {
        ptr4.ptr = nullptr;
    }

    AutoPtr4& operator=(const AutoPtr4& ptr4) // copy assignment
    {
        if(this == &ptr4)
        {
            return *this;
        }

        delete this->ptr;
        this->ptr = new T;
        *this->ptr = *ptr4.ptr;
        return *this;
    }

    AutoPtr4& operator=(AutoPtr4&& ptr4) // move assignment
    {
        if(this == &ptr4)
        {
            return *this;
        }

        delete this->ptr;
        this->ptr = ptr4.ptr;
        ptr4.ptr = nullptr;
        return *this;
    }

    T& operator*() const
    {
        return *this->ptr;
    }

    T* operator->() const
    {
        return this->ptr;
    }

    bool isNull() const
    {
        return this->ptr == nullptr;
    }

private:
    T* ptr;
};

#endif /* CONSTRUCTOR_H_ */
