#include <queue>
#include <list>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int s;
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        list<int> queue;
        queue.push_back(s);
        visited[s] = true;
        vector<int>::iterator i;

        while (!queue.empty())
        {
            s = queue.front();
            std::cout << s << " ";
            queue.pop_front();

            for (i = adj[s].begin(); i != adj[s].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        // Code here
    }
};