#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{ 
    int k; 
    int j;
       
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n'; 
        return 0;   
    }
    for(j = 1; argv[j]; j++)
    {
        for(k = 0; argv[j][k]; k++)
        {
            std::cout << (char)std::toupper(argv[j][k]);
        }
    }    
    std::cout << '\n';
    return 0;

} 