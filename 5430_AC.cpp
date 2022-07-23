
#include <iostream>
#include <string>
#include <deque>

bool list_parser(const std::string& in, std::deque<std::string>& out)
{
	if(in.length() == 0)
		return false;
	
	int cur = 1;
	int idx = 0;
	for(int i = 1; i<in.length(); ++i)
    {
        if(in[i]==',' || in[i] ==']') 
        {
            std::string element(in.begin() + cur, in.begin() + i);
            if(element.length() == 0) return false;
			out.push_back(element);
			//std::cout << "[TEST] " <<  element << std::endl;
            cur = i+1;
        }
    }
    
    return true;
}

int main()
{
	int T = 0; std::cin >> T;
	while(T--)
	{
		std::string operation, x;
		std::deque<std::string> dp;
		int n;
		std::cin >> operation >> n >> x;

		list_parser(x, dp);
		
		bool reversed = false;
		bool error = false;
		
		for(const auto& op : operation)
		{
			if(op == 'R')
			{
				reversed = !reversed;
			}
			else if(op == 'D')
			{
				if(dp.empty())
				{		
					error = true;
					break;
				}
				
				if(reversed)
					dp.pop_back();
				else
					dp.pop_front();
			}
		}
		
		//output
		
		if(error)
			std::cout << "error\n";
		else
		{
			std::cout << "[";
			
			if(reversed)
			{
				for(auto i = dp.rbegin(); i!=dp.rend(); ++i)
				{
					if(i == dp.rend() - 1) std::cout <<*i;
                	else std::cout << *i + ',';
                }
			}
			else
			{
	            for(auto i = dp.begin(); i!=dp.end(); ++i)
	            {
	                if(i == dp.end() - 1) std::cout <<*i;
	                else std::cout << *i + ',';
	            }

			}
			std::cout << "]\n";
		}

	}
	
	
	return 0;
}
