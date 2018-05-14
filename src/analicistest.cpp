/*
 * testAVL.cpp
 *
 *  Created on: 3/05/2018
 *      Author: vonnewmann
 */

#include"ArbolesAVL.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

int main(){

	ArbolesAVL<string> lexicon;
	map<string, int> palanali;

//Creación del lexicon de stopwords: Aquí se crea un arbol binario balanceado para comparar con mayor agilidad las palabras.
	ifstream stopwords;
	string stopw;
	stopwords.open("data/stopwords-es.txt");
	while(getline(stopwords,stopw)){
		lexicon.insertar(stopw);
	}
	stopwords.close();

	lexicon.imprimir();


//Lectura de la información
	ifstream datos;
	string linea;
	datos.open("data/prueba.txt");
	while(getline(datos, linea)){
		string palabra = "";
		for(int i = 0; i < linea.length(); i++ ){
			if(linea[i]==' '||linea[i]==','||linea[i]==';'||linea[i]==':'||linea[i]=='('||linea[i]==')'||linea[i]=='.'){
				if(!palabra.empty()){    //Se comprueba que no esté vacia la palabra.
					if(!lexicon.buscar(palabra)){    //Se comprueba que no esté en el lexicón de stopwords
						if(palanali.find(palabra) == palanali.end()){
							palanali.insert(pair<string,int>(palabra,0));
						}else{
							palanali[palabra]++;
						}
					}
				}
				palabra = "";
			}else{
				palabra+= linea[i];
			}
		}
		//Nuevamente para incluir la ultima palabra
		if(!palabra.empty()){    //Se comprueba que no esté vacia la palabra.
			if(!lexicon.buscar(palabra)){    //Se comprueba que no esté en el lexicón de stopwords
				if(palanali.find(palabra) == palanali.end()){
					palanali.insert(pair<string,int>(palabra,0));
				}else{
					palanali[palabra]++;
				}
			}
		}
	}
	datos.close();

	map<string, int>::iterator p = palanali.begin();
	while(p!=palanali.end()){
		cout << p->first << " : " << p->second << endl;
	}



}


//Se presentan problemas en la inserción de los elementos del mapa.

