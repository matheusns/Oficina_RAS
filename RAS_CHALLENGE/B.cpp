#include <iostream>
#include <string>
#include <vector>
#include <set>

int main()
{   
    int notas, soma, M,m;
    int times;
    float pound;

    std::cin >> times;
    std::string name;
    std::vector<std::string> vet_name;  
    while (times--)
    {   
        std::cin.ignore();
        std::getline(std::cin,name);
        std::cout << name << std::endl;
        std::cin >> pound; 
        std::vector<float> grades; 
        std::set<float> setNums;
        for (int i = 0; i < 7; i++)
        {
            float x;
            std::cin >> x;
            grades.push_back(x);
            setNums.insert(x);
        }
        int sum = 0;
        for (std::vector<float>::iterator it = grades.begin() ; it != grades.end(); ++it)
        {
            if ( *it != *setNums.begin() && *it != *setNums.end() )
            {
                sum+=(*it);
            }
        }
        std::cout << sum << std::endl;
    }
}