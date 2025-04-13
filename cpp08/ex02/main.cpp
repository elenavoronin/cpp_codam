#include "MutantStack.hpp"


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    std::cout << "added 5 to the stack" << std::endl;
    mstack.push(17);
    std::cout << "added 17 to the stack" << std::endl;
    std::cout << "top of stack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "removed first from the top" << std::endl;
    std::cout << "the entire stack: " << std::endl;
    mstack.printStack();
    std::cout << "stack size is: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "added 3 to the stack" << std::endl;
    std::cout << "added 5 to the stack" << std::endl;
    std::cout << "added 737 to the stack" << std::endl;
    std::cout << "added 0 to the stack" << std::endl;


    std::cout << "the entire stack: " << std::endl;
    mstack.printStack();

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "it: " << *it << std::endl;
    std::cout << "ite: " << *(ite) << std::endl;


    ++it;
    --ite;


    std::cout << "it: " << *it << std::endl;
    std::cout << "ite: " << *(ite) << std::endl;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "it: " << *it << std::endl;
    std::cout << "ite: " << *(ite) << std::endl;


    std::stack<int, MutantStack<int>> s(mstack);
    
    return 0;
}