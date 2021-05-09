#include <iostream>
#include "Graph.h"
#include "DFS.h"
#include "BFS.h"

using namespace std;

/**
 * @brief   Obsahuje hlavnu funkciu, ktora nam spusta cely program , konstruktor pre graf ,prehladavania do hlbky a sirky tak isto cykly pre iteraciu
 * @file    c-main.cpp
 * @author  Pavol Comorek
 */


/**
  * @brief Hlavna funkcia programu
  * @param a     Konstruktor Grafu  "Graph g("Graph.txt");" s parametrom zvoleneho suboru ktory obsahuje hrany a pocet vrcholov 
  * @param b     Konstruktor Depth-First Search teda prehladavania do hlbky "DFSIterator kvp(g);" s parametrom Grafu z ktoreho prebera data
  * @param c     Konstruktor Breadth-First search teda prehladavania do sirky "BFSIterator rtk(g);" s parametrom Grafu z ktoreho prebera data
  * @param D	 Int v ktory sluzi pri vypise aktualne spracovaneho vrcholu
 */
int main(void)
{
	int v = 0;
	
	Graph g("Graf2.txt");
	DFSIterator IterDFS(g);
	BFSIterator IterBFS(g);
	
	cout << endl;
	cout << "Depth-First Search: " << endl;
	for (
		IterDFS.Reset();
		!IterDFS.IsEnd();
		IterDFS.Next())

	{ 
		
		v = IterDFS.CurrentKey();
		if (v != -1)
			cout << v << " ";
		
	}

	cout << endl;
	cout << endl;

	cout << "Breadth-First search: " << endl;

	for (
		IterBFS.Reset();
		!IterBFS.IsEnd();
		IterBFS.Next())
	{

		v = IterBFS.CurrentKey();
		if( v != -1 )
			cout << v << " ";
	}

}
