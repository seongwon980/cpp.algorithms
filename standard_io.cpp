#include <iostream>

int main(void)
{
    int val1;
    std::cout<<"Enter the first number: ";
    std::cin>>val1;

    int val2;
    std::cout<<"Enter the second number: ";
    std::cin>>val2;
    
    int result = val1 + val2;
    std::cout<<"Add result: "<<result<<std::endl;
    return 0;
}
