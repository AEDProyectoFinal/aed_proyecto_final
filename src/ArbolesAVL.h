/*
 * ArbolesAVL.h
 *
 *  Created on: 3/05/2018
 *      Author: vonnewmann
 */

#ifndef ARBOLESAVL_H_
#define ARBOLESAVL_H_

template <typename TipoDato>
class ArbolesAVL {
public:
	/*
	* Tipo: Nodo de �rbol de B�squeda Binaria
	* ----------
	* Estructura para almacenar cada nodo del �rbol.
	*/

	struct NodoAVL {
		TipoDato dato;
		NodoAVL *izq;
		NodoAVL *der;
		int altura;
	};

	//Constructores
	ArbolesAVL();

	ArbolesAVL(TipoDato datoIni);

	//~ArbolBusquedaBinaria();

	//M�todos p�blicos
	bool buscar(TipoDato dato);

	TipoDato minimo();

	TipoDato maximo();

	TipoDato predecesor(TipoDato dato);

	TipoDato sucesor(TipoDato dato);

	NodoAVL* getNodoPadre(TipoDato dato);

	void insertar(TipoDato dato);

	int altura(NodoAVL * nodo);

	void eliminar(TipoDato dato);

	void imprimir();

	void imprimirArbol(NodoAVL * nodo);

	/*

	void imprimirPreOrden();typename ArbolBusquedaBinaria<TipoDato>::NodoABB

	void imprimirPostOrden();

	*/

private:
	/* Atributos */
	NodoAVL *raiz; 	/* Apuntador al nodo ra�z del �rbol */


	NodoAVL* buscarNodo(NodoAVL* nodo, TipoDato dato);

	NodoAVL* minimoNodo(NodoAVL * nodo);

	NodoAVL* maximoNodo(NodoAVL * nodo);

	NodoAVL* predecesorNodo(NodoAVL* nodo, TipoDato dato);

	NodoAVL* sucesorNodo(NodoAVL* nodo);

	NodoAVL* getNodoPadre(TipoDato dato, NodoAVL * nodo);

	void insertarNodo(NodoAVL * & nodo, TipoDato dato);

	void actualizaraltura(NodoAVL * &nodo);

	void eliminarNodo(NodoAVL * & nodo, TipoDato dato);
};




#endif /* ARBOLESAVL_H_ */

#include "ArbolesAVL.cpp"

