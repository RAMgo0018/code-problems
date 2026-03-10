/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1; // mark node as visited
        pathVisited[node] = 1; // mark node in current DFS path

        for(auto it : adj[node]) // traverse neighbours
        {
            if(!visited[it]) // if neighbour not visited
            {
                if(dfs(it, adj, visited, pathVisited)) // DFS call
                    return true; // cycle found
            }
            else if(pathVisited[it]) // if neighbour already in current path
            {
                return true; // cycle detected
            }
        }

        pathVisited[node] = 0; // remove node from current DFS path
        return false; // no cycle found
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses); // adjacency list

        for(auto it : prerequisites) // build graph
        {
            adj[it[1]].push_back(it[0]); // edge from prerequisite to course
        }

        vector<int> visited(numCourses,0); // visited array
        vector<int> pathVisited(numCourses,0); // path visited array

        for(int i = 0; i < numCourses; i++) // check every node
        {
            if(!visited[i]) // if node not visited
            {
                if(dfs(i, adj, visited, pathVisited)) // run DFS
                    return false; // cycle detected so cannot finish courses
            }
        }

        return true; // no cycle so courses can be finished
    }
};

int main()
{
    int numCourses, p;
    cout << "Enter number of courses: ";
    cin >> numCourses; // input number of courses

    cout << "Enter number of prerequisite pairs: ";
    cin >> p; // input number of pairs

    vector<vector<int>> prerequisites(p, vector<int>(2)); // prerequisite list

    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for(int i = 0; i < p; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1]; // input pairs
    }

    Solution obj; // create object
    bool result = obj.canFinish(numCourses, prerequisites); // call function

    if(result)
        cout << "All courses can be finished\n"; // print result
    else
        cout << "Courses cannot be finished (cycle exists)\n"; // print result

    return 0; // end program
}