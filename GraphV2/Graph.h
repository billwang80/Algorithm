#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <vector>

using namespace std;

class Graph
{
    public:
        Graph();
        Graph(string);
        print();
        ~Graph();

    protected:

    private:
        vector<string> nameList;
        vector<vector<int> > affinity;
};

#endif // GRAPH_H
