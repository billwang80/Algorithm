#include "Graph.h"

using namespace std;

Graph::Graph()
{

}

Graph::Graph(string fileName)
{
    ifstream fin(fileName);
    int numNodes = 0;
    fin >> numNodes;

    for(int i = 0; i < numNodes; i++)
    {
        nameList.push_back(vector(numNodes,-1));
    }
}

Graph::~Graph()
{
    //dtor
}

Graph::print()
{

}
