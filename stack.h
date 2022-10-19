#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>


// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : std::vector<T>
{

public:
    Stack(){
        
    }
    ~Stack(){
        data.clear();
    }
    bool empty() const
    {
        if (size() == 0){
            return true;
        }
        return false;
    }
    size_t size() const{
        return data.size();
    }
    void push(const T& item){
        data.push_back(item);
    }
    void pop()  // throws std::underflow_error if empty
    {
        if(empty()){
            throw std::underflow_error("Stack is empty");
        }

         data.pop_back();
        
        
    }
    const T& top() const // throws std::underflow_error if empty
    {
        if(empty()){
            throw std::underflow_error("Stack is empty");
        }
        return data.back();
       
    }
private:
    // Add other members only if necessary
    std::vector<T> data;
};


#endif