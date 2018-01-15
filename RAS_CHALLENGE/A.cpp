#include <iostream>

int fat(int num)
{
    if (num == 1) return 1;
    return num*fat(num-1);
}

int main()
{
    int x,fatorial;
    std::cin >> x;
    fatorial = fat(x); 
    std::cout << fatorial << std::endl; 
    return 0;
}