#include "DFS.h"




/**
 * @brief   Iterator Prehladavania do sirky (Breadth-First search)
 * @file    DFS.cpp
 * @author  Pavol Comorek
 */

DFSIterator::DFSIterator(Graph& graph)
{   
    this->edge = graph.Getvector();

    this->Vertex_number = graph.GetNumberOfVectors();
   
    this->value = new int[graph.GetNumberOfVectors()];

    this->min = graph.GetMin();
    
    this->printed = new int[graph.GetNumberOfVectors() ];

    
  
    
    
}
void DFSIterator::Reset()
{   
    stack.push_front(min);
    value[0] = 1;
    
    for (int i = 0; i < Vertex_number; i++)
    {
        value[i] = 0;
        printed[i] = 0;

    }

}

void DFSIterator::Next()
{
   
    

    if (!stack.empty())
    {
        auto s = stack.front();

        stack.pop_front();

        for (auto i = edge[s].begin(); i != edge[s].end(); ++i)
        {

            if (value[*i] != 1)
            {
                stack.push_front(*i);
                value[*i] = 1;
            }
        }

    }
    else
    {


        for (int i = 0; i < Vertex_number; i++)
        {

            if (value[i] != 1)
            {
                this->stack.push_front(i);
                this->value[i] = 1;
                break;
            }
        }


    }
}
bool DFSIterator::IsEnd()
{
    int s = 0;
    for (int i = 0; i <= Vertex_number ; i++)
    {
        if (value[i] == 1)
        {
            s++;
            
        } 
        if ((s == Vertex_number) && (stack.empty() == true))
        {
            return true;
        }

    }
    
   
    
    
    
    return false;
    
}
int DFSIterator::CurrentKey()
{
 
    if (!(this->stack.empty()))
    {
        if ((printed [stack.front()] != 1))
        {
            this->printed[this->stack.front()] = 1;
            return this->stack.front();
            
        }

    }
   
    return -1;
 
}






    
   


