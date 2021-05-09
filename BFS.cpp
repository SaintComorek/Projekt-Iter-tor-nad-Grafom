#include "BFS.h"

/**
 * @brief   Iterator Prehladavania do sirky (Breadth-First search)
 * @file    BFS.cpp
 * @author  Pavol Comorek
 */


BFSIterator::BFSIterator(Graph& graph)
{
    this->edge = graph.Getvector();

    this->Vertex_number = graph.GetNumberOfVectors();
  
    this->value = new int[graph.GetNumberOfVectors()];

    this->min = graph.GetMin();

    this->printed = new int[graph.GetNumberOfVectors() ];

    //this->adj = graph.Getlist();

}
void BFSIterator::Reset()
{
    queue.push_back(min);
    value[0] = 1;

    for (int i = 0; i < Vertex_number; i++)
    {
        value[i] = 0;
        printed[i] = 0;
    }
}

void BFSIterator::Next()
{
    


    if (!queue.empty())
    {
        auto s = queue.front();

        queue.pop_front();


        


        for (auto i = edge[s].begin(); i != edge[s].end(); ++i)
        {

            if (value[*i] != 1)
            {
                value[*i] = 1;
                queue.push_back(*i);
            }
        }



    }
    else
    {


        for (int i = 0; i < Vertex_number; i++)
        {

            if (value[i] != 1)
            {
                this->queue.push_back(i);
                this->value[i] = 1;
                break;
            }
           
        }


    }
}
bool BFSIterator::IsEnd()
{
    int s = 0;
    for (int i = 0; i < Vertex_number ; i++)
    {
        if (value[i] == 1)
        {
            s++;
           

        }
        if ((s == Vertex_number) && (queue.empty() == true))
        {
            return true;
        }
    }


    return false;

}
int BFSIterator::CurrentKey()
{

    if (!(queue.empty()))
    {
       
        if (printed[queue.front()] == 0)
        {
            printed[queue.front()] = 1;
            return queue.front();

        }

    }
   
    return -1;
}




