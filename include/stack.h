#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

namespace lnfData {

/**
 * \brief Stack class
 */
template <typename T>
class Stack {
   private:
    size_t size_;     //<! Number of elements sotored in the stack
    uint32_t index_;  //<! Top of the stack
    T *storage;       //<! Base storage array
    size_t capacity_;  //<! Storage capacity allocated

   public:
    /**
     * \brief Default constructor
     */
    Stack() : size_(0), index_(0), capacity_(100)
    {
        storage = new T[capacity_];
    }

    /**
     * \brief Default destructor
     */
    ~Stack()
    {
        delete[] storage;
    }

    /**
     * \brief Check if stack is empty
     * \returns true if stack is empty
     */
    bool empty()
    {
        return size_ == 0;
    }

    /**
     * \brief Get stack size
     * \returns The number of elements in the stack
     */
    size_t size()
    {
        return size_;
    }

    /**
     * \brief Push a new element to the top of the stack
     * \param value New value to be added to the stack
     */
    void push(T value)
    {
        if (size_ == capacity_) {
            T *tmp = new T[capacity_ + 100];
            std::copy(storage, storage+size_-1, tmp);
            delete[] storage;
            storage = tmp;
            capacity_ += 100;
        }
        storage[index_++] = value;
        ++size_;
    }

    /**
     * \brief Pop the top element of the stack
     * \returns The top element of the stack.
     *  Will throw std::out_of_range if the stack is empty.
     */
    T pop()
    {
        if (size_ != 0) {
            --size_;
            return storage[--index_];
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }

    /**
     * \brief Get the top element of the stack, without removing it
     * \returns The top element of the stack.
     *  Will throw std::out_of_range if the stack is empty.
     */
    T peek()
    {
        if (size_ != 0) {
            return storage[index_ - 1];
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }
};
}  // namespace lnfData