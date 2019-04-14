#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* objeto);
int expand(ArrayList* objeto,int index);
int contract(ArrayList* objeto,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
 /* crea y retorna un nuevo arraylist , da valores iniciales a variables y asiga funciones a punteros.*/
ArrayList* al_newArrayList(void)
{
    ArrayList* objeto;
    ArrayList* returnAux = NULL;
    void* things;
    objeto = (ArrayList *)malloc(sizeof(ArrayList));

    if(objeto != NULL)
    {
        things = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(things != NULL)
        {
            objeto->size=0;
            objeto->pElements=things;
            objeto->reservedSize=AL_INITIAL_VALUE;
            objeto->add=al_add;
            objeto->len=al_len;
            objeto->set=al_set;
            objeto->remove=al_remove;
            objeto->clear=al_clear;
            objeto->clone=al_clone;
            objeto->get=al_get;
            objeto->contains=al_contains;
            objeto->push=al_push;
            objeto->indexOf=al_indexOf;
            objeto->isEmpty=al_isEmpty;
            objeto->pop=al_pop;
            objeto->subList=al_subList;
            objeto->containsAll=al_containsAll;
            objeto->deleteArrayList = al_deleteArrayList;
            objeto->sort = al_sort;
            returnAux = objeto;
        }
        else
        {
            free(objeto);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* objeto, void* pElement)/* agrega un elemento al final del array */
{

    int returnAux = -1;
    int flag = 0;

    if (pElement != NULL && objeto != NULL) // SIEMPRE VALIDAR DE ESTA MANERA
    {
        if(objeto->size == objeto->reservedSize)
        {

            if (resizeUp(objeto)==-1)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            *(objeto->pElements +objeto->size) = pElement;
            returnAux = 0;
            objeto->size++;
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* objeto) /* elimina el arraylist */
{
    int returnAux = -1;

    if (objeto != NULL)
    {
        free(objeto);
        free(objeto->pElements);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* objeto) /* retorna el tamanio del arraylist */
{
    int returnAux = -1;

    if(objeto != NULL)
    {
        returnAux = objeto->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* objeto, int index) //retorna un puntero en el indice especificado
{
    void* returnAux = NULL;

    if(objeto!=NULL && index >= 0  && index <= objeto->size)
    {
        returnAux = *(objeto->pElements+index);
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if objeto list contains at least one element pElement
 *
 */
int al_contains(ArrayList* objeto, void* pElement) /* comprueba si existe el elemento que se le pasa por parametro */
{
    int returnAux = -1;
    int i;

    if(objeto != NULL && pElement != NULL)
    {
        for(i=0; i<objeto->size; i++)
        {
            if(pElement == *(objeto->pElements+i))
            {
                returnAux = 1;
                break;
            }
            else
            {
                returnAux = 0;
            }
        }

    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* objeto, int index,void* pElement) /* inserta un elemento en el arraylist, en la posicion especificada */
{
    int returnAux = -1;

    if (objeto != NULL && pElement != NULL && index >= 0 && index < objeto->size)
    {
        *(objeto->pElements+index) = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* objeto,int index) /* remueve un elemento en la posicion especificada */
{
    int returnAux = -1;

    if (objeto != NULL && index>=0 && index<=objeto->size)
    {
        contract(objeto,index);
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from objeto list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* objeto) /* borra todos los elementos del arraylist */
{
    int returnAux = -1;
    int tamSize, i;
    if (objeto != NULL)
    {
        tamSize = objeto->size;

        for (i=0; i<tamSize; i++)
        {
            *(objeto->pElements+i)= NULL;
        }

        objeto->size = 0;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Returns an array containing all of the elements in objeto list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* objeto) /* retorna un nuevo arraylist copia del original */
{
    ArrayList* returnAux = NULL;
    int i;

    returnAux = al_newArrayList();

    if (objeto != NULL && returnAux!=NULL)
    {
        for(i=0; i<objeto->size;i++)
        {
            returnAux->add(returnAux,*(objeto->pElements+i));
        }
    }

    return returnAux;
}


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* objeto, int index, void* pElement) /* inserta un elemento en la posicion indicada , desplazando los elementos. */
{
    int returnAux = -1;

    if(objeto != NULL && pElement != NULL && index >=0 && index <= objeto->size)
    {
        if(index==objeto->size)
        {
            objeto->add(objeto,pElement);
        }
        else if(expand(objeto,index)==0)
        {
            *(objeto->pElements+index) = pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* objeto, void* pElement) /* devuelve la posicion del elemento buscado en el arraylist */
{
    int returnAux = -1;
    int i;
    if(objeto != NULL && pElement != NULL)
    {
        for(i=0; i<objeto->size; i++)
        {
            if(*(objeto->pElements+i)== pElement)
            {
                returnAux = i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if objeto list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* objeto) /* retorna 1 si el array no tiene elementos y 0 si tiene */
{
    int returnAux = -1;

    if(objeto != NULL)
    {
        if(objeto->size==0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* objeto,int index) /* retorna  un puntero al elemento que se encuentra en el índice especificado y lo elimina de la lista */
{
    void* returnAux = NULL;

    if(objeto != NULL && index <= objeto->size && index >=0)
    {
        returnAux=objeto->get(objeto,index);
        objeto->remove(objeto,index);

    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* objeto,int from,int to)
{
    ArrayList* returnAux = NULL;
    int cantidad, i;


    if(objeto != NULL &&  from>=0 && from < to && to <=objeto->size)
    {
        cantidad=to-from;

        returnAux = al_newArrayList();

        while(returnAux->reservedSize < cantidad)
        {
            resizeUp(objeto);
        }

        for(i=from; i<to; i++)
        {
            returnAux->add(returnAux,*(objeto->pElements+i));
        }
    }

    return returnAux ;
}

/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* objeto,ArrayList* objeto2)
{
    int returnAux = -1;
    int i;

    if(objeto != NULL && objeto2 != NULL)
    {
        if(objeto->size == objeto2->size)
        {
            for(i=0; i<objeto->size; i++)
            {
                if(*(objeto->pElements+i)== *(objeto2->pElements+i))
                {
                    returnAux = 1;
                }

            }
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* objeto, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i,j;
    void* aux;

    if(objeto != NULL && pFunc !=NULL && (order==0 || order==1))
    {
        for(i=0; i<objeto->size-1; i++)
        {
            for(j=i+1; j<objeto->size; j++)
            {
                if(order==0)
                {
                    if(pFunc(*(objeto->pElements+i),*(objeto->pElements+j))== -1)
                    {
                        aux= *(objeto->pElements+i);
                        *(objeto->pElements+i)=*(objeto->pElements+j);
                        *(objeto->pElements+j)= aux;

                    }
                }
                else
                {
                    if(pFunc(*(objeto->pElements+i),*(objeto->pElements+j))== 1)
                    {
                        aux= *(objeto->pElements+i);
                        *(objeto->pElements+i)=*(objeto->pElements+j);
                        *(objeto->pElements+j)= aux;

                    }
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* objeto)
{
    int returnAux = -1;
    void** auxArray;
    if (objeto != NULL)
    {

        auxArray = (void**)realloc(objeto->pElements,sizeof(void*)*(objeto->reservedSize+AL_INCREMENT));

        if (auxArray != NULL)
        {
            objeto->pElements = auxArray;
            objeto->reservedSize = objeto->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* objeto,int index)
{
    int returnAux = -1;
    int i;

    if (objeto != NULL && index >= 0 && index <= objeto->size && objeto->size > 0)
    {
        if(objeto->reservedSize == objeto->size)
        {
            resizeUp(objeto);
        }

        for (i=objeto->size; i>index; i--)
        {
            *(objeto->pElements+(i+1)) = *(objeto->pElements+i);
        }
        returnAux = 0;
        objeto->size++;
    }


    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* objeto,int index)
{
    int returnAux = -1, i,j;

    if(objeto!=NULL && index >= 0  && index < objeto->size)
    {
        for(i=index; i < objeto->size ; i++)
        {
            j=i+1;
            *(objeto->pElements+i)= *(objeto->pElements+j); // OJO ACA; puede estar un error en el +1
        }
        returnAux=0;
        objeto->size--;
    }

    return returnAux;
}
