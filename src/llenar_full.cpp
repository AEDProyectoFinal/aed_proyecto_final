/*
 * llenar_full.cpp
 *
 *  Created on: 23/05/2018
 *      Author: vonnewmann
 */

#include <iostream>
#include <map>
#include "ArbolAVL.cpp"
#include <fstream>
#include <string>
using namespace std;

void guardar( map<string, int> & mapa,string palabra){
	std::map<string, int>::iterator it;
	std::ofstream archivo;
	if(palabra == "petro"){
		archivo.open("petro.txt");
		if(archivo.is_open()){
				for(it = mapa.begin();it!=mapa.end();it++){
					archivo << it->first << "," << it->second<<endl;
					archivo.flush();
				}
	}
		else {
							cout << "no se pudo abrir"<< endl;				}
	}
	else if(palabra == "duque"){
		archivo.open("duque.txt",std::ios_base::app);
				for(it = mapa.begin();it!=mapa.end();it++){
					archivo << it->first << "," <<it->second ;
					}
		}
	else{
		archivo.open("fajardo.txt",std::ios_base::app);
				for(it = mapa.begin();it!=mapa.end();it++){
				archivo << it->first << "," <<it->second ;
	}
				archivo.close();


}
}

int main(){
	map<string, int> map;
	map.insert(pair<string,int>("jose",1));
	map.insert(pair<string,int>("mike",1));
	map.insert(pair<string,int>("alo",1));
	map.insert(pair<string,int>("jquin",1));
	string petro = "petro";
	guardar(map,petro);
	return 0;
}


