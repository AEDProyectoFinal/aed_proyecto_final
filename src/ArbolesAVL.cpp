/*
 * ArbolesAVL.cpp
 *
 *  Created on: 3/05/2018
 *      Author: vonnewmann
 */

#ifdef ARBOLESAVL_H_


#include<iostream>
#include<cmath>

template <typename TipoDato>
ArbolesAVL<TipoDato>::ArbolesAVL(){
	raiz = NULL;
}

template <typename TipoDato>
TipoDato ArbolesAVL<TipoDato>::minimo(){
	return minimoNodo(raiz)->dato;
}

template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::minimoNodo(ArbolesAVL<TipoDato>::NodoAVL*nodo) {
	if (nodo == NULL) return NULL;
	if (nodo->izq == NULL) return nodo;
	return minimoNodo(nodo->izq);
}

//maximo
template <typename TipoDato>
TipoDato ArbolesAVL<TipoDato>::maximo(){
	return maximoNodo(raiz)->dato;
}

template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::maximoNodo(ArbolesAVL<TipoDato>::NodoAVL*nodo) {
	if (nodo == NULL) return NULL;
	if (nodo->der == NULL) return nodo;
	return minimoNodo(nodo->der);
}

// sucesor
template <typename TipoDato>
TipoDato ArbolesAVL<TipoDato>::sucesor(TipoDato dato){
	NodoAVL * nodo = buscarNodo(raiz, dato);
	if (nodo != NULL){
		NodoAVL * sucesor = sucesorNodo(nodo);
		if (sucesor != NULL)
			return sucesor -> dato;
	}
	std::cout << "El elemento " << dato << " no tiene sucesor en el �rbol" << std::endl;
	return NULL;
}

template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::sucesorNodo(ArbolesAVL<TipoDato>::NodoAVL* nodo) {
	if (nodo->der != NULL) return minimoNodo(nodo->der);

	NodoAVL *padre = getNodoPadre(nodo->dato);
	while (padre!=NULL && nodo == padre->der){
		nodo = padre;
		padre = getNodoPadre(padre->dato);
	}
	return padre;
}


//nodo padre
template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::getNodoPadre(TipoDato dato){
	if (raiz -> dato == dato)
		return NULL;
	return getNodoPadre(dato, raiz);
}

template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::getNodoPadre(TipoDato dato, ArbolesAVL<TipoDato>::NodoAVL * nodo){
	if (nodo == NULL)
		return NULL;
	if( (nodo->izq != NULL && nodo->izq->dato == dato) || (nodo->der != NULL && nodo->der->dato == dato) ){
		return nodo;
	}
	if(dato < nodo->dato)
		return getNodoPadre(dato, nodo->izq);
	else
		return getNodoPadre(dato, nodo->der);
}



// buscar

template <typename TipoDato>
bool ArbolesAVL<TipoDato>::buscar(TipoDato dato){
	return buscarNodo(raiz, dato) != NULL;
}


template <typename TipoDato>
typename ArbolesAVL<TipoDato>::NodoAVL * ArbolesAVL<TipoDato>::buscarNodo(ArbolesAVL<TipoDato>::NodoAVL*nodo, TipoDato dato) {
	if (nodo == NULL) return NULL;
	if (dato == nodo->dato) return nodo;
	if (dato < nodo->dato) {
		return buscarNodo(nodo->izq, dato);
	} else {
		return buscarNodo(nodo->der, dato);
	}
}


template <typename TipoDato>
void ArbolesAVL<TipoDato>::insertar(TipoDato dato){
	insertarNodo(raiz, dato);
}

template <typename TipoDato>
void ArbolesAVL<TipoDato>::insertarNodo(ArbolesAVL<TipoDato>::NodoAVL * & nodo, TipoDato dato){
	if (nodo == NULL) {
		nodo = new NodoAVL;
		nodo->dato = dato;
		nodo->izq = nodo->der = NULL;
		nodo->altura=1;
	} else {
		if (dato != nodo->dato) {
			if (dato < nodo->dato) {
				insertarNodo(nodo->izq, dato);
			} else {
				insertarNodo(nodo->der, dato);
			}
		}
	}
	actualizaraltura(nodo);
	//balanceo();
	actualizaraltura(nodo);

}
template<typename TipoDato>
int ArbolesAVL<TipoDato>::altura(NodoAVL * nodo){
	return nodo!= NULL ? nodo->altura : 0;
}

template<typename TipoDato>
void ArbolesAVL<TipoDato>::actualizaraltura(NodoAVL * &nodo){
	nodo->altura = 1 + fmax(altura(nodo->izq), altura(nodo->der));
}



template <typename TipoDato>
void ArbolesAVL<TipoDato>::eliminar(TipoDato dato){
	eliminarNodo(raiz, dato);
}

template <typename TipoDato>
void ArbolesAVL<TipoDato>::eliminarNodo(ArbolesAVL<TipoDato>::NodoAVL * & nodo, TipoDato dato){
	if (nodo == NULL)
		return;
	if(dato < nodo->dato ){
		eliminarNodo(nodo->izq, dato);
	}else if(dato > nodo->dato){
		eliminarNodo(nodo->der, dato);
	}else if(nodo->izq != NULL && nodo->der != NULL){ // caso 2 hijos
		nodo -> dato = minimoNodo(nodo->der)->dato;	  // reemplaza dato del nodo a eliminar por el dato del minimo nodo en el subarbol derecho
		eliminarNodo(nodo->der, nodo->dato);		  // elimina dato que qued� duplicado en el sub�rbol derecho
	}else{											  // caso 1 hijo
		NodoAVL *nodoViejo = nodo;
		nodo = (nodo->izq != NULL) ? nodo->izq : nodo->der;
		delete nodoViejo;
	}
}



template <typename TipoDato>
void ArbolesAVL<TipoDato>::imprimir(){
	std::cout << "- - -" << std::endl;
	imprimirArbol(raiz);
	std::cout << "- - -" << std::endl;
}

template <typename TipoDato>
void ArbolesAVL<TipoDato>::imprimirArbol(ArbolesAVL<TipoDato>::NodoAVL *nodo){
	if (nodo != NULL) {
		imprimirArbol(nodo->izq);
		std::cout << nodo->dato << std::endl;
		imprimirArbol(nodo->der);
	}
}

#endif

