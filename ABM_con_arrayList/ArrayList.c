#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

ArrayList* al_newArrayList(void) //probada
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* objeto;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        objeto = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(objeto != NULL)
        {
            this->size=0;
            this->pElements=objeto;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}

int al_add(ArrayList* this, void* pElement) //probada
{
    int returnAux = -1,flag=0;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size == this->reservedSize)
        {
            if( resizeUp(this)==-1 )
            {
                flag=1;
            }
        }

        if(flag==0)
        {
            (this+this->size)->pElements=pElement;
            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}

int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this->pElements);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

int al_len(ArrayList* this)  // probada
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux= this->size;
    }

    return returnAux;
}

void* al_get(ArrayList* this, int index) //probada
{
    void* returnAux = NULL;

    if(this!=NULL && index >= 0  && index < this->size && this->size > 0)
    {
        returnAux= (this+index)->pElements;

    }

    return returnAux;
}

int al_contains(ArrayList* this, void* pElement) //probada
{
    int returnAux = -1,i;

    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i<this->size ; i++)
        {
            if((this+i)->pElements==pElement)
            {
                returnAux=1;
                break;
            }

            else
            {
                returnAux=0;
            }

        }
    }

    return returnAux;
}

int al_set(ArrayList* this, int index,void* pElement)  //probada
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && index >= 0  && index < this->size)
    {
        (this+index)->pElements=pElement;
        returnAux=0;
    }

    return returnAux;
}

int al_remove(ArrayList* this,int index)  //probada
{
    int returnAux = -1;

    if(this!=NULL && index >= 0  && index < this->size)
    {
        if(contract(this,index) ==0 )
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int al_clear(ArrayList* this) //probada
{
    int returnAux = -1, i,aux;

    if(this!=NULL)
    {
        aux=this->size;

        for(i=0; i< aux ; i++)
        {
            (this+i)->pElements=NULL;
            this->size--;
        }
        returnAux=0;
    }

    return returnAux;
}

ArrayList* al_clone(ArrayList* this) //probada
{
    ArrayList* returnAux = NULL;
    int i;

    if(this!=NULL)
    {
        returnAux= al_newArrayList();

        while(this->reservedSize > returnAux->reservedSize)
        {
            resizeUp(returnAux);
        }

            for(i=0;i<this->size;i++)
            {
                (returnAux+i)->pElements=(this+i)->pElements;
            }

        returnAux->size = this->size;
    }

    return returnAux;
}

int al_push(ArrayList* this, int index, void* pElement) //probada
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL  && index >= 0  && index < this->size )
    {
        if(this->reservedSize==this->size)
        {
            this->add(this,pElement);
            returnAux=0;
        }

        else
        {
            expand(this,index);
            this->set(this,index,pElement);
            returnAux=0;
        }
    }
    return returnAux;
}

int al_indexOf(ArrayList* this, void* pElement) //probada
{
    int returnAux = -1,i;

    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i< this->size; i++)
        {
            if((this+i)->pElements==pElement)
            {
                returnAux=i;
            }
        }
    }
    return returnAux;
}

int al_isEmpty(ArrayList* this) //probada
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux=1;
        }

        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

void* al_pop(ArrayList* this,int index) //probada
{
    void* returnAux = NULL;

    if(this!=NULL && index<this->size && index>=0 )
    {
        returnAux= this->get(this,index);
        this->remove(this,index);
    }

    return returnAux;

}

ArrayList* al_subList(ArrayList* this,int from,int to) //probada
{
    ArrayList* returnAux = NULL;
    int i, cantidad;

    if(this!=NULL && from >=0 && to<=this->size && to>from)
    {
        cantidad=to-from;
        returnAux= al_newArrayList();

        while(cantidad > returnAux->reservedSize)
        {
            resizeUp(returnAux);
        }

        for(i=from; i<to ; i++)
        {
            returnAux->add(returnAux,(this+i)->pElements);
        }
    }

    return returnAux ;
}

int al_containsAll(ArrayList* this,ArrayList* this2) //probada
{
    int returnAux = -1, i;

    if(this!=NULL && this2!=NULL)
    {
        if(this->size == this2->size)
        {
            for(i=0; i< this->size ; i++)
            {
                if( this->pElements[i] == this2->pElements[i] )
                {
                    returnAux=1;
                }
                else
                {
                    returnAux=0;
                    break;
                }
            }
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1,i,j;
    void* aux;

    if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {
                if(order==1)
                {
                    if(pFunc(this->pElements[i],this->pElements[j])==1)
                    {
                        aux= this->pElements[i];
                        this->pElements[i] = this->pElements[j];
                        this->pElements[j] = aux;
                    }
                }
                else
                {
                    if(pFunc(this->pElements[i],this->pElements[j])==-1)
                    {
                        aux= this->pElements[i];
                        this->pElements[i] = this->pElements[j];
                        this->pElements[j] = aux;
                    }
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}

int resizeUp(ArrayList* this)
{
    int returnAux= -1;
    void** aux;

    if(this!=NULL)
    {
        aux=  (void**)  realloc(this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));

        if(aux!=NULL)
        {
            this->pElements= aux;
            this->reservedSize+= AL_INCREMENT;
            returnAux=0;
        }
    }

    return returnAux;
}

int expand(ArrayList* this,int index)
{
    int returnAux = -1,i,flag=1;

    if(this!=NULL &&  index >= 0  && index < this->size)
    {
        if(this->size == this->reservedSize)
        {
            if( resizeUp(this) ==-1)
            {
                flag=0;
            }
        }

        if(flag==1)
        {
            for(i=this->size; i>index ; i--)
            {
                (this+(i+1))->pElements=(this+i)->pElements;
                returnAux=0;
            }
        }
    }

    return returnAux;
}

int contract(ArrayList* this,int index)
{
    int returnAux = -1, i;

    if(this!=NULL && index >= 0  && index < this->size)
    {
        for(i=index; i < this->size ; i++)
        {
            (this+i)->pElements=(this+(i+1))->pElements; // OJO ACA; puede estar un error en el +1
        }

        returnAux=0;
        this->size--;
    }

    return returnAux;
}
