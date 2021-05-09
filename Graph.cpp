#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
/**
 * @brief   Vytvorenie grafu
 * @file    Graph.cpp
 * @author  Pavol Comorek
 */

using namespace std;

Graph::Graph(string file)
{
    this->NumberOfLines = NumberOfLines;
   
    std::ifstream File(file);
    if (File.is_open())
    {
        std::string line;

        while (!File.eof())
        {

            getline(File, line);
            cout << line << endl;
            NumberOfLines++;


        }
        File.clear(); // clear bad state after eof
        File.seekg(0); // vynulovanie kurzoru

        ifstream is(file);
        istream_iterator<int> start(is), end;
        vector<int> numbers(start, end);
        cout << "Zaznamenanych " << numbers.size() - 1 << " hodnot\n\n";
 
        numbers.erase(numbers.begin() + 0);

        cout << "Zaznamenane hodnoty:\n";
        copy(numbers.begin(), numbers.end(),
            ostream_iterator<int>(cout, " "));

        cout << endl;

        auto MINelement = min_element(numbers.begin(), numbers.end());
        min = *MINelement;

        auto MAXelement = max_element(numbers.begin(), numbers.end());
        NumberOfVertex += *MAXelement - *MINelement;

        this->array = new int[numbers.size()];
        copy(numbers.begin(), numbers.end(), array);

        edgeList = new vector<int>[NumberOfLines * 2];

    }
    else
        cout << "Subor nie je mozne otvorit " << endl;

    File.close();

    for (int u = 0; u < NumberOfLines * 2 ; ++u)
    {

        edgeList[array[u]].push_back(array[u + 1]);
        edgeList[array[u + 1]].push_back(array[u]);
        u++;


    }

    cout << endl;
    for (int v = 0; v < NumberOfVertex; v++)
    {
        cout << "Vertex " << v << " ";
        for (auto x : edgeList[v])
            cout << "-> " << x;
        cout << endl;
    }
    cout << endl;

 }

int Graph::GetNumberOfVectors()
{  
    return this->NumberOfVertex;
}


int Graph::GetMin()
{
    return min;
}




