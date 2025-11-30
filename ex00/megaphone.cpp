#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{ 
    int k; 
    int j;
       
    if(argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n'; 
        return 0;   
    }
    for(j = 1; argv[j]; j++)
    {
        for(k = 0; argv[j][k]; k++)
        {
            cout << (char)std::toupper(argv[j][k]);
        }
    }    
    cout << '\n';
    return 0;

} 