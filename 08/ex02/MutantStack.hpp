#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack const &mutantstack) : std::stack<T>(mutantstack) {}
    MutantStack &operator=(MutantStack const &mutantstack) {
        if (this != &mutantstack)
            std::stack<T>::operator=(mutantstack);
        return *this;
    }
    ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

private:

};