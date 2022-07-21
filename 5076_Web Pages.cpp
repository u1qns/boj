#include <iostream>
#include <string>
#include <stack>
int main()
{
    
    std::string text;
    while(1)
    {
        bool isLegal = true;
        std::stack<std::string> tags;
        std::getline(std::cin, text);
        if(text == "#") break;
        
        for(int i = 0; i<text.length(); ++i)
        {
            auto c = text[i];
            
            if(c == '<')
            {
                std::string tagname;
                for(int j = i+1; j<text.length(); ++j)
                {
                    if(text[j]=='>')
                    {
                        //</tag>
                        if((text.length() > i + 1) && text[i+1]=='/')
                        {
                            tagname = std::string(text.begin() + i+2, text.begin() + j);
                            
                            if((tags.empty() == false) && (tagname == tags.top()))
                                tags.pop();
                            else
                                isLegal = false;
                        }
                        else
                        {
                            
                            // not <br />
                            if(text[j-1] != '/')
                            {
                                //<a locat = ">
                                if((text.length() > i + 2 )&& text[i+2] == ' ')
                                    tagname = std::string(text.begin() + i+1, text.begin() + 2);
                                else
                                    tagname = std::string(text.begin() + i+1, text.begin() + j);
                                
                                tags.push(tagname);
                            }
                            
                        }
                        break;
                    }
                }
                
                if(isLegal == false)
                    break;
                
            }
            
        }
        // 스택에 tag가 남아있다면 짝이 맞지 않은 것이다.
        if(isLegal || tags.empty())
            std::cout << "legal\n";
        else
            std::cout <<"illegal\n";
        
    }//while
    return 0;
}
