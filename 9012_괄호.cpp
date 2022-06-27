#include <iostream>
#include <string>
#include <cstring>

int main()
{
    int T = 0; std::cin >> T;
    while(T--)
    {
        int count = 0;
        char buf[100]; std::cin>>buf;
        int size = strlen(buf);
        
        for(int i=0; i < size; ++i)
        {
            if(buf[i]=='(') ++count;
            else --count;
            
            if(count <0) break;
        }

        if(count == 0) std::cout << "YES\n";
        else std::cout << "NO\n";

        if(T==0) break;
    }
    return 0;
}
