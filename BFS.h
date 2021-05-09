#pragma once
#include "Graph.h"
#include <stack>
#include <list>
/**
 * @brief   Iterator Prehladavania do sirky (Breadth-First search)
 * @file    BFS.h
 * @author  Pavol Comorek
 */

class BFSIterator
{
private:

	
	/**
* @brief Vector ktory prebera uz vytvorene hrany grafu */
	vector<int>* edge; 

	/**
* @brief Pocet Vrcholov grafu */
	int Vertex_number;

	/**
* @brief list ktorý je využívaný ako fronta , na spracovanie vrcholov */
	list<int>queue; 

	/**
* @brief hodnota ktorá je primárne nulová ale pri zápise vrcholu do fronty sa zmeni na 1 , sluzi teda na inicializaciu spracovania vrcholov ktoré sú prechodom aktuálneho vrcholu */
int* value; 
	
/**
* @brief minimálna hodnota Vrcholov grafu */
	int min;

	/**
* @brief slúži primárne na výpis kedy evidujem vrcholy ktore už sú vypísané , aby neboli vypísané znova */
	int* printed; 

public:
	/**
 * @brief Konstruktor iteratoru Prehladavania do sirky (Breadth-First search)
 * @param a     Graf a jeho prislusne data @see Graph.h
 */
	BFSIterator(Graph& graph);

	/**
 * @brief Metoda  ulozi do fronty vrchol grafu s najnizsim cislom, Iteracie zacina timto vrcholom
 */
	void Reset(); 

	/**
 * @brief Metoda kotroluje ci je Iteracia ukoncena, ak je fronta prazdna a vsetky vrcholy boli oznaèené ako spracovane
 * @return True alebo False podla toho ci je Iteracia ukoncena ci nie
 */
	bool IsEnd(); 

	/**
*@brief Metoda funkcia posunie aktualny vrchol Iterator na nasledujuce vrchol. Metoda otestuje frontu, ci je prazdna
*@brief Pokial nie je prazdna, vyberie aktualne vrchol z frontu a do fronty ulozi vsetky
neobjavene susedov prave vytiahnuteho vrchole. Ak takyto sused neexistuje, neuklada sa do fronty nic
*@brief Ak je fronta prazdna, pokusi sa najst pomocou evidencie vrcholov dalsi nespracovany vrchol a ulozi ho do fronty. Iterator presiel do dalsej suvislej komponenty grafu. Ak takyto vrchol neexistuje, neuklada do fronty nic
*/
	void Next();

	/**
* @brief Metoda vracia aktualny vrchol
* @return Vracia hodnotu v aktualnom vrchole, cize vo vrchole, ktory je v hlave fronty
*/
	int CurrentKey(); 

	









};