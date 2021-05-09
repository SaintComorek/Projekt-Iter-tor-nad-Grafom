#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

/**
 * @brief   Obsahuje Premenne a funkcie pre vytvorenie grafu
 * @file    Graph.h
 * @author  Pavol Comorek
 */

class Graph
{
private:
	/**
 * @brief Pocet riadkov suboru ktory vyuzivame aj ako pocet vrcholov preto zaciname od -1 */
	int NumberOfLines = -1;

	/**
* @brief Hodnota ktoru pouzivame na zapis najmensej hodnoty v grafe od ktorej nasledne zaciname prehladavanie */
	int min;

	/**
* @brief Pole do ktoreho kopirujeme hrany z vektoru numbers , sluzi nam na vytvaranie hran do vectoru edgeList , jeho velkost je numbers.size() teda velkost vektoru ktory obsahuje prebrane data */
	int* array;

	/**
* @brief Vektor do ktoreho pomocou pola vytvarame hrany , jeho velkost je NumberOfLines * 2 */
	vector<int>* edgeList;
	/**
* @brief Pocet riadkov suboru ktory vyuzivame aj ako pocet vrcholov preto zaciname od -1 */
	int NumberOfVertex = 1;

public:
	/**
 * @brief konstruktor spracovava graf a vytvara data potrebne pre jedho prehladavanie
 * @param a     string file , vstupny parameter pre konstruktor do ktoreho zapisujeme subor ktory obsahuje graf
 */
	Graph(string file);
	
	/**
 * @brief Navratova funkcia pre hodnotu NumberOfVertex 
 * @return  vracia  pocet vrcholov 
 */
	int GetNumberOfVectors();

	/**
* @brief Navratova funkcia pre Vektor v ktorom su vytvorene hrany grafu
* @return  vracia vektor v ktorom su  vytvorene hrany grafu
*/
	vector<int>* Getvector()  { return edgeList; }
	
	/**
* @brief Navratova funkcia pre najmensiu zaznamenanu hodnotu zo suboru
* @return  vracia najmensiu hodnotu od ktorej sa bude zacinat prehladavanie
*/
	int GetMin();


	

	





};

