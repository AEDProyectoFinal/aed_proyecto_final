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


//Función para imprimir el histograma
void imprimirmapa(map <string, int> &tabela) {
  map<string, int>::iterator it;
  for (it = tabela.begin(); it != tabela.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
}


//Creación del arbol con el lexicón
void crearlexicon(ArbolesAVL<string> & arbol){
	ifstream stopwords;
	string stopw;
	stopwords.open("data/stopwords-es.txt");
	while(getline(stopwords,stopw)){
		arbol.insertar(stopw);
	}
	stopwords.close();
}




int main(){

	ArbolesAVL<string> lexicon; //Arbol para stopwords
	map<string, int> palanali;


	crearlexicon(lexicon);//Se lena el arbol de stopwords
	lexicon.imprimir();



	ifstream doc;
		doc.open("data/Twitter_API.txt");
		string linea;
		string tweet= "";
		while(getline(doc, linea)){
			for(int i = 0; i<linea.length(); i++){
				if(linea[i]=='"'&&linea[i+1]=='t'&&linea[i+2]=='e'&&linea[i+3]=='x'&&linea[i+4]=='t'){
					int e = i+8;
					while(true){
						if(linea[e]=='"')break;
						else{
						tweet.push_back(linea[e]);
						e++;
						}

					}
					if(!(tweet[0]=='R'&&tweet[1]=='T'&&tweet[2]==' ')){
						cout << tweet << endl;//Remover posteriormente
						//En esta linea se puede guardar el tweet en una estructura.

						//Contrucción del histograma.
						string palabra = "";
						for(int it2 = 0; it2 < tweet.length(); it2++ ){
							if(tweet[it2]==' '||tweet[it2]==','||tweet[it2]==';'||tweet[it2]==':'||tweet[it2]=='('||tweet[it2]==')'||tweet[it2]=='.'){
								if(!palabra.empty()){    //Se comprueba que no esté vacia la palabra.
									if(!lexicon.buscar(palabra)){    //Se comprueba que no esté en el lexicón de stopwords
										if(palanali.find(palabra) == palanali.end()){
										    palanali.insert(pair<string,int>(palabra,1));
										}else{
											palanali[palabra]++;
										}
										cout << palabra << "---";//Remover posteriormente
									}
								}
								palabra = "";
							}else{
								palabra+= tweet[it2]; //Se van agregando los caracteres para formar la palabra
							}
						}
						//Nuevamente para incluir la ultima palabra
						if(!palabra.empty()){    //Se comprueba que no esté vacia la palabra.
							if(!lexicon.buscar(palabra)){    //Se comprueba que no esté en el lexicón de stopwords
								if(palanali.find(palabra) == palanali.end()){
									palanali.insert(pair<string,int>(palabra,1));
								}else{
									palanali[palabra]++;
								}
								cout << palabra << "---";//Remover posteriormente
							}
						}

					}
					i = i + tweet.size()+7;
					tweet = "";
				}
			}
		}
	doc.close();



	imprimirmapa(palanali);



}





