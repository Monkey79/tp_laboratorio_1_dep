#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);
void _swapNodes(Node* pNodeA, Node* pNodeB);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *  o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL
 * o la cantidad de elementos de la lista
 */
int ll_len(LinkedList *this) {
	int len = -1;
	if (this != NULL) {
		len = this->size;
	}
	return len;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL
 * o (si el indice es menor a 0 o mayor al len de la lista) (pElement) Si funciono correctamente
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode = NULL;
	int len = 0;
	int i = 0;
	if (this != NULL) {
		len = ll_len(this);
		if (nodeIndex >= 0 && nodeIndex < len) {
			pNode = this->pFirstNode;
			while (i < nodeIndex) {
				pNode = pNode->pNextNode;
				i++;
			}
		}
	}
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;
	Node *prev = NULL;
	Node *next = NULL;
	Node *nuevoNodo = NULL;
	int len = 0;
	if (this != NULL) {
		len = ll_len(this);
		nuevoNodo = (Node*) malloc(sizeof(Node));
		nuevoNodo->pElement = pElement;
		if (nodeIndex <= len) {
			if (nodeIndex > 0) {
				prev = getNode(this, nodeIndex - 1);
				next = prev->pNextNode;
				nuevoNodo->pNextNode = next;
				prev->pNextNode = nuevoNodo;
				returnAux = 0;
				this->size++;
			} else if (nodeIndex == 0) {
				next = this->pFirstNode;
				nuevoNodo->pNextNode = next;
				this->pFirstNode = nuevoNodo;
				this->size++;
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento AL FINAL de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int indice = 0;
	Node *actual;
	Node *prev;
	if (this != NULL) { // && pElement != NULL
		indice = ll_len(this);
		actual = (Node*) malloc(sizeof(Node));
		if (actual != NULL) {
			actual->pElement = pElement;
			if (indice > 0) {
				prev = getNode(this, indice - 1);
				prev->pNextNode = actual;
				this->size++;
			} else if (indice == 0) {
				this->pFirstNode = actual;
				this->size++;
			}
			returnAux = 0;
		}
	}

	return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o
 * (si el indice es menor a 0 o mayor al len de la lista)
 * (pElement) Si funciono correctamente
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *pNode = NULL;
	int len = 0;
	int i = 0;
	if (this != NULL) {
		len = ll_len(this);
		if (index >= 0 && index < len) {
			pNode = this->pFirstNode;
			while (i < index) {
				pNode = pNode->pNextNode;
				i++;
			}
		}
	}
	returnAux = (pNode != NULL) ? pNode->pElement : NULL;
	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *actual;
	Node *prev;
	Node *next;
	int len;

	if (this != NULL) {
		len = ll_len(this);
		actual = (Node*) malloc(sizeof(Node));
		actual->pElement = pElement;
		if (index == 0 && len >= 0) {
			this->pFirstNode = actual;
			this->size++;
			returnAux = 0;
		} else if (index > 0 && index < len) {
			prev = getNode(this, index - 1);
			next = prev->pNextNode;
			prev->pNextNode = actual;
			actual->pNextNode = next;
			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *prev;
	Node *actual;
	Node *next;
	int len = 0;

	if (this != NULL) {
		len = ll_len(this);
		if (index == 0 && index < len) {
			actual = this->pFirstNode;
			next = actual->pNextNode;

			if (actual->pElement != NULL)
				free(actual->pElement);
			free(actual);

			this->pFirstNode = next;
			this->size--;
			returnAux = 0;
		} else if (index > 0 && index < len) {
			prev = getNode(this, index - 1);
			actual = prev->pNextNode;
			next = actual->pNextNode;
			prev->pNextNode = next;

			if (actual->pElement != NULL)
				free(actual->pElement);
			free(actual);
			this->size--;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	int i;
	int len;
	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			returnAux = ll_remove(this, i);
		}
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;
	int len;
	if (this != NULL) {
		len = ll_len(this);
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int len;
	int i;
	int found = 0;
	void *pAnElement;
	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len && !found; i++) {
			pAnElement = ll_get(this, i);
			//debido al test indexOfTest (linea 42) NO valido NULL
			//if(nodo != NULL)
			found = (pAnElement == pElement);
		}
		returnAux = (found) ? (i - 1) : returnAux;
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		if (ll_len(this)) {
			returnAux = 0;
		} else {
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *actual;
	Node *prev;
	Node *next;
	int len;

	if (this != NULL) {
		len = ll_len(this);
		actual = (Node*) malloc(sizeof(Node));
		actual->pElement = pElement;
		if (index == 0 && len == 0) {
			this->pFirstNode = actual;
			this->size++;
			returnAux = 0;
		} else if (index > 0 && index <= len) {
			prev = getNode(this, index - 1);
			next = prev->pNextNode;
			prev->pNextNode = actual;
			actual->pNextNode = next;
			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *prev;
	Node *actual;
	Node *next;
	int len = 0;

	if (this != NULL) {
		len = ll_len(this);
		if (index == 0 && index < len) {
			actual = this->pFirstNode;
			next = actual->pNextNode;

			if (actual->pElement != NULL)
				returnAux = actual->pElement;
			free(actual);
			this->pFirstNode = next;
			this->size--;
		} else if (index > 0 && index < len) {
			prev = getNode(this, index - 1);
			actual = prev->pNextNode;
			next = actual->pNextNode;
			prev->pNextNode = next;

			if (actual->pElement != NULL)
				returnAux = actual->pElement;
			free(actual);
			this->size--;
		}
	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = (ll_indexOf(this, pElement) >= 0) ? 1 : 0;
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	int equals;
	int len;
	int i;
	Node *nodo;

	if (this != NULL && this2 != NULL) {
		len = ll_len(this2);
		for (i = 0; i < len && equals; i++) {
			nodo = getNode(this2, i);
			equals = ll_contains(this, nodo->pElement);
		}
		returnAux = (equals) ? 1 : 0;
	}

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int e = 0;
	int len;
	Node *node;
	if (this != NULL) {
		len = ll_len(this);
		if (from >= 0 && to <= len) {
			cloneArray = ll_newLinkedList();
			for (int i = from; i < to; i++) {
				node = getNode(this, i);
				addNode(cloneArray, e, node->pElement);
				e++;
			}
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	int len;
	Node *node;
	if (this != NULL) {
		len = ll_len(this);
		cloneArray = ll_newLinkedList();
		for (int i=0; i<len; i++) {
			node = getNode(this, i);
			addNode(cloneArray, i, node->pElement);
		}
	}
	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	int len=0;
	Node* pNodeA;
	Node* pNodeB;
	int pFuncRslt;

	if(this!=NULL && pFunc!=NULL && (order==1 || order==0)){
		len = ll_len(this);
		for(int i=0;i<len-1;i++){
			pNodeA = getNode(this, i);
			for(int e=i;e<len;e++){
				pNodeB = getNode(this, e);
				if(pNodeA!=NULL & pNodeB!=NULL){
					pFuncRslt = pFunc(pNodeA->pElement,pNodeB->pElement);
					if(order==1 && pFuncRslt==1){
						_swapNodes(pNodeA,pNodeB);
					}else if(order==0 && pFuncRslt==-1){
						_swapNodes(pNodeA,pNodeB);
					}
				}
			}
		}//end for
		returnAux=0;
	}
	return returnAux;
}

void _swapNodes(Node* pNodeA, Node* pNodeB){
	void *pAux;
	pAux = pNodeA->pElement;
	pNodeA->pElement = pNodeB->pElement;
	pNodeB->pElement = pAux;
}

