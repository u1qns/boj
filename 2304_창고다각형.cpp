#include <iostream>

int main()
{
    int N =0, L =0, H=0, area =0;
    int pillars[10001];
    int left =10001, right =0, max = 0; // position

    std::cin >> N;
    for(int i =0; i<N; ++i)
    {
        std::cin >> L >> H;
        pillars[L] = H;
        if(pillars[L] > pillars[max]) max = L;
        if(left > L) left = L;
        if(right < L) right = L;
    }

   // -> max
    int height = pillars[left], pos = left;
    for(int i = left+1; i <= max; ++i)
    {
        if(pillars[i] >= height)
        {
            area +=(i-pos)*height;
            pos = i;bheight = pillars[i];
        }
    }
    
	// max <-
    height = pillars[right]; pos = right;
    for(int i = right-1; i >= max; --i)
    {
        if(pillars[i] >= height)
        {
            area +=(pos-i)*height;
            pos = i; height = pillars[i];
        }
    }
    std::cout << area + pillars[max];
    return 0;
}
