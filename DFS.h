#pragma once
#include "Graph.h"
#include <stack>
#include <list>


/**
 * @brief   Iterator Prehladavania do hlbky (Depth-First search)
 * @file    DFS.h
 * @author  Pavol Comorek
 */


class DFSIterator 
{
private:
	/**
* @brief Vector ktory prebera uz vytvorene hrany grafu */
	vector<int>* edge;

	/**
* @brief list ktor� je vyu��van� ako fronta , na spracovanie vrcholov */
	int Vertex_number;

	/**
* @brief list ktor� je vyu��van� ako zasobnik , na spracovanie vrcholov */
	list<int>stack;
	
	/**
* @brief hodnota ktor� je prim�rne nulov� ale pri z�pise vrcholu do fronty sa zmeni na 1 , sluzi teda na inicializaciu spracovania vrcholov ktor� s� prechodom aktu�lneho vrcholu */
	int* value;

	/**
* @brief minim�lna hodnota Vrcholov grafu */
	int min;

	/**
* @brief sl��i prim�rne na v�pis kedy evidujem vrcholy ktore u� s� vyp�san� , aby neboli vyp�san� znova */
	int* printed;


public:
	/**
* @brief Konstruktor iteratoru Prehladavania do hlbky (Depth-First search)
* @param a     Graf a jeho prislusne data @see Graph.h
*/
	DFSIterator(Graph& graph);

	/**
* @brief Metoda ulozi do zasobnika vrchol grafu s najnizsim cislom. iteracie zacina
tymto vrcholom
*/
	void Reset();

	/**
* @brief Metoda kotroluje ci je Iteracia ukoncena, ak je zasobnik prazdny a vsetky vrcholy boli ozna�en� ako spracovane
* @return True alebo False podla toho ci je Iteracia ukoncena ci nie
*/
	bool IsEnd();

	/**
*@brief Metoda funkcia posunie aktualny vrchol Iterator na nasledujuce vrchol. Metoda otestuje zasobnik, ci je prazdna
*@brief Pokial nie je prazdny, vyberie aktualne vrchol zo zasobnika a do zasobnika
ulozi vsetky neobjavene susedov prave vytiahnuteho vrchole. Ak takyto sused neexistuje, neuklada sa do zasobnika nic
*@brief Ak je zasobnik prazdny, pokusi sa najst pomocou evidencie vrcholov dalsie
nespracovany vrchol a ulozi ho na zasobnik. Iterator presiel do dalsej suvislej komponenty grafu. Ak takyto vrchol neexistuje, neuklada do zasobnikanic
*/
	void Next();

	/**
* @brief Metoda vracia aktualny vrchol
* @return Vracia hodnotu v aktualnom vrchole, cize vo vrchole, ktory je na vrchu zasobniku
*/
	int CurrentKey();


};
