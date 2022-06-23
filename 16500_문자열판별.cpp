#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string S;
std::vector<std::string> A;
int N = 0;
bool idx_check[101];

void combination(int idx)
{
    if(idx_check[idx] == true)
    {
        return;
    }
    
    for(int i=0; i<N; ++i)
    {
        if(S.substr(idx, A.at(i).size()) == A.at(i))
        {
            idx_check[idx] = true;
            if(S.size() == (A.at(i).size() + idx))
            {
                std::cout << "1";
                exit(0);
                return;
            }
            combination(idx+ A.at(i).size());;
        }
    }
    return;
}

int main() {

    //input
    std::cin >> S >> N;
    A.resize(N);
    for(int i=0; i<N; ++i)
    {
        std::cin >> A[i];
    }
    
    //solve & output
    combination(0);

    //false일 경우
    std::cout <<"0";


    return 0;
}
