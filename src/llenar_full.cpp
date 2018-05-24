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
							cerr << "No se pudo guardar"<< endl;
		}
	}
	else if(palabra == "duque"){
		archivo.open("duque.txt");
		if(archivo.is_open()){
				for(it = mapa.begin();it!=mapa.end();it++){
					archivo << it->first << "," <<it->second ;
					archivo.flush();
					}
		}
		else{
			cerr << "no se pudo guardar"<< endl;
		}
	}
	else if (palabra == "fajardo"){
		archivo.open("fajardo.txt");
		if(archivo.is_open()){
				for(it = mapa.begin();it!=mapa.end();it++){
				archivo << it->first << "," <<it->second ;
				archivo.flush();
				}
		}
		else{
			cerr << "No se pudo guardar"<< endl;
		}

	}
	archivo.close();
}

void txt_mapa(map<string, int> & mapa,string palabra){
	std::map<string, int>::iterator it;
	std::ifstream archivo;
	string linea;
	string delimitador =",";
	if(palabra == "petro"){
		archivo.open("petro.txt");
		if(archivo.is_open()){
				cout << "lo pudo abrir para leer" << endl;
		}
		else {
				cerr<< "No se pudo abrir"<< endl;
		}
	}
	else if(palabra == "duque"){
		archivo.open("duque.txt");
		if(archivo.is_open()){
			cout << "lo pudo abrir para leer" << endl;
		}
		else{
			cerr << "No se pudo abrir"<< endl;
		}
	}
	else if (palabra == "fajardo"){
		archivo.open("fajardo.txt");
		if(archivo.is_open()){
			cout << "lo pudo abrir para leer" << endl;
		}
		else{
			cerr << "No se pudo abrir"<< endl;

		}

	}
	while(getline(archivo,linea)){
		string palabra = linea.substr(0,linea.find(delimitador));
		string entero = linea.substr(linea.find(delimitador)+1, linea.length());
		int entero1 = std::stoi(entero);
		mapa.insert(pair<string,int>(palabra,entero1));
	}
	archivo.close();
}
void imprimir(map<string, int> &mapa){
	std::map<string, int>::iterator it;
	for(it = mapa.begin();it!=mapa.end();it++){
						cout << it->first << "//" << it->second<<endl;
					}
}

int main(){
	map<string, int> map;
	std::map<string, int> mapa;
	map.insert(pair<string,int>("jose",1));
	map.insert(pair<string,int>("mike",1));
	map.insert(pair<string,int>("alo",1));
	map.insert(pair<string,int>("jquin",1));
	string petro = "petro";
	guardar(map,petro);
	txt_mapa(mapa,petro);
	imprimir(mapa);
	return 0;
}



