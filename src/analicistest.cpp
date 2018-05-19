#include"ArbolAVL.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include <algorithm>
#include <vector>
using namespace std;



class persona{
public:
	map<string,int> *apuntador;
	string indv;
};

// funcion coeficiente similitud
double similitud(persona persona1,persona persona2){
	map<string,int>::iterator it;
	int cont = 0;
	for(it = persona1.apuntador->begin(); it != persona1.apuntador->end();  it++){
		if(!(persona2.apuntador->find(it->first) == persona2.apuntador->end())){
			cont++;
		}
	}

	double indice = cont/20;//Cambiar dependiento del top.
	return indice;
}

//Recolección del top
	class sort_map
{
  public:
	string key;
	int val;
};

bool Sort_by(const sort_map& a ,const sort_map& b){
	return a.val > b.val;
}


void llenartop( map<string,int> & mapa,map<string,int> & topmapa){
	map<string,int>::iterator it;
	vector< sort_map > v;
	vector< sort_map >::iterator itv;
	sort_map sm;
	
	for (it = mapa.begin(); it != mapa.end(); ++it){
		sm.key = it->first;
		sm.val = it->second;
		v.push_back(sm);
	}
	
	sort(v.begin(),v.end(),Sort_by);
	
	for(itv = v.begin(); itv != v.begin()+20; itv++){
	    topmapa.insert(std::pair<string,int>(itv->key,itv->val));
	}
	
}
	
	
	

//Función para imprimir el histograma
void imprimirmapa(map <string, int> &tabela) {
  map<string, int>::iterator it;
  for (it = tabela.begin(); it != tabela.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
}

void imprimirmapa2(map <string, int> *tabela) {
  map<string, int>::iterator it;
  for (it = tabela->begin(); it != tabela->end(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
}


//Llena el arbol con el lexicón
void llenarlexicon(ArbolAVL<string> & arbol){
	ifstream stopwords;
	string stopw;
	stopwords.open("data/lexicon.txt"); // CAMBIAR NOMBRE
	while(getline(stopwords,stopw)){
		arbol.insertar(stopw);
	}
	stopwords.close();
}




//Llena el mapa con las palabras
void llenarhistogramapal(map<string, int> & mapa, ArbolAVL<string> lexicon){

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
							if(tweet[it2]==' '||tweet[it2]==','||tweet[it2]==';'||tweet[it2]==':'||tweet[it2]=='('||tweet[it2]==')'||tweet[it2]=='.'||tweet[it2]=='-'){
								if(!palabra.empty()){    //Se comprueba que no esté vacia la palabra.
									if(!lexicon.buscar(palabra)){    //Se comprueba que no esté en el lexicón de stopwords
										if(mapa.find(palabra) == mapa.end()){
										    mapa.insert(pair<string,int>(palabra,1));
										}else{
											mapa[palabra]++;
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
								if(mapa.find(palabra) == mapa.end()){
									mapa.insert(pair<string,int>(palabra,1));
								}else{
									mapa[palabra]++;
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

}



//Estructura






int main(){

	ArbolAVL<string> lexicon; //Arbol para stopwords
	map<string, int> palanali;
	map<string,int> top50;
	map<string, int> palanali2;
	map<string,int> top502;
	persona petro1;
	persona petro2;


	llenarlexicon(lexicon);//Se llena el arbol de stopwords
	lexicon.imprimir();

	llenarhistogramapal(palanali, lexicon);//Se llena el mapa para crear un histograma
	llenarhistogramapal(palanali2, lexicon);// no pasar el lexicon como parametro
	
	imprimirmapa(palanali);
	llenartop(palanali,top50);
	llenartop(palanali2,top502);
	cout << "----" << endl;
	imprimirmapa(top50);
	// asignar valores a nodo persona
	petro1.indv = "petro";
	petro2.indv = "petro1";
	petro1.apuntador=&top50;
	petro2.apuntador=&top502;

	imprimirmapa2(petro2.apuntador);
	cout << "------" << endl;
	cout << similitud(petro1,petro2) << endl;

}




