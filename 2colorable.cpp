/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h> 
using namespace std; 

  
void createedge(vector<int> near[], int u, int v) 
{ 
    near[u].push_back(v); 
    near[v].push_back(u); 
} 
  
bool isColorful(vector<int> near[], int v, vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : near[v])
    { 
        if (visited[u] == false)
        { 
              visited[u] = true; 
              color[u] = !color[v]; 
              
              if (!isColorful(near, u, visited, color))
              {
                return false;
              }
        } 
  
        else if (color[u] == color[v])
        {
            return false;
        }
    } 
    return true; 
} 
  
int main() 
{ 
    int nodes;
    int first, second;
    cout << "Enter the number of nodes you would like: ";
    cin >> nodes;
  
    vector<int> near[nodes + 1]; 
    vector<bool> visited(nodes + 1); 
    vector<int> color(nodes + 1); 
    
    cout << "Rules for typing in edges: First edge must be '1 2', second edge '2 3' and so on, with the last edge being 'x 1'" << endl;
    cout << "Now type in your edges (hit enter after typing in each set of digits):";
    for (int i = 0; i < nodes; i++)
    {
        cin >> first >> second;
        createedge(near, first, second);
    }
  
    visited[1] = true; 
    color[1] = 0; 
  
    
    if (isColorful(near, 1, visited, color))
    { 
        cout << "Graph is 2-colorable"; 
    } 
    else
    { 
        cout << "Graph is not 2-colorable"; 
    } 
  
    return 0; 
}
