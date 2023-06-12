#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

bool isIsomorphic(const std::vector<int>& degrees1, const std::vector<int>& degrees2)
{
    // Check if the number of vertices are the same
    if (degrees1.size() != degrees2.size())
        return false;

    // Calculate the number of edges for each graph
    int edges1 = 0, edges2 = 0;
    for (int i = 0; i < degrees1.size(); i++)
    {
        edges1 += degrees1[i];
        edges2 += degrees2[i];
    }

    // Check if the number of edges are the same
    if (edges1 != edges2)
        return false;

    // Create maps to store the frequency of degrees
    std::map<int, int> freq1, freq2;
    for (int i = 0; i < degrees1.size(); i++)
    {
        freq1[degrees1[i]]++;
        freq2[degrees2[i]]++;
    }

    // Check if the degree sequences are the same
    if (freq1 != freq2)
        return false;

    return true;
}

int main()
{
    // Example graphs represented by degree sequences
    std::vector<int> graph1 = { 3, 3, 2, 2, 2 };
    std::vector<int> graph2 = { 2, 2, 3, 3, 2 };
    std::vector<int> graph3 = { 2, 3, 2, 2, 2 };

    // Check if graph1 and graph2 are isomorphic
    if (isIsomorphic(graph1, graph2))
        std::cout << "Graph1 and Graph2 are isomorphic." << std::endl;
    else
        std::cout << "Graph1 and Graph2 are not isomorphic." << std::endl;

    // Check if graph1 and graph3 are isomorphic
    if (isIsomorphic(graph1, graph3))
        std::cout << "Graph1 and Graph3 are isomorphic." << std::endl;
    else
        std::cout << "Graph1 and Graph3 are not isomorphic." << std::endl;

    return 0;
}
