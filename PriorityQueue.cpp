#include <iostream>
#include <queue>
int main()
{  
    std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(10);
    pq.push(4);
    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
    return 0;
}