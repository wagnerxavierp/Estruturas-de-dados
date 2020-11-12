/*
*@author: Wagner Xavier
*/

#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);
using namespace std;


template <class Tipo>
class Elemento
{
    private:
        Tipo valor;
        Elemento<Tipo>* proximo;
        Elemento<Tipo>* anterior;
    public:
        Tipo getValor(){
            return this->valor;
        }
        void setValor(Tipo valor){
            this->valor = valor;
        }

        Elemento* getProximo(){
            return this->proximo;
        }
        void setProximo(Elemento* proximo){
            this->proximo = proximo;
        }

        Elemento* getAnterior(){
            return this->anterior;
        }
        void setAnterior(Elemento* anterior){
            this->anterior = anterior;
        }

        Tipo getValorComparacao(){
            return this->valor;
        }
        Tipo getValorImprimir(){
            return this->valor;
        }

};

template <class Tipo>
class Lista
{
private:
    Elemento<Tipo>* inicio;
    Elemento<Tipo>* fim;
    int tamanho;

    Elemento<Tipo>* criarElemento(Tipo valor)
    {
        Elemento<Tipo>* novo = (Elemento<Tipo>*)malloc(sizeof(Elemento<Tipo>));
        novo->setValor(valor);
        novo->setAnterior(NULL);
        novo->setProximo(NULL);
        return novo;
    }

public:

    Lista()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    int is_vazia()
    {
        return (tamanho == 0);
    }

    Elemento<Tipo>* getInicio(){
        return this->inicio;
    }
    Elemento<Tipo>* getFim(){
        return this->fim;
    }


    void imprimeLista()
    {
        Elemento<Tipo>* atual;
        atual = inicio;
        if(atual != NULL)
        {
            cout << atual->getValorImprimir();
            atual = atual->getProximo();
            while(atual)
            {
                cout << ", " << atual->getValorImprimir();
                atual = atual->getProximo();
            }
            cout <<"\n";
        }
    }

    void imprimeListaContrario()
    {
        Elemento<Tipo>* atual;
        atual = fim;
        if(atual!=NULL)
        {
            cout << atual->getValorImprimir();
            atual = atual->getAnterior();
            while(atual)
            {
                cout << ", " << atual->getValorImprimir();
                atual = atual->getAnterior();
            }
            cout <<"\n";
        }
    }



    void insereInicio(Tipo valor)
    {
        Elemento<Tipo>* novo = criarElemento(valor);   //criar novo elemento
        //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
        if(inicio==NULL)
        {
            inicio=novo;
            fim=novo;

            //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
        }
        else
        {
            Elemento<Tipo>* atual; //criar novo elemento caso tenha dado no inicio da lista.
            atual = inicio;
            novo->setProximo(atual);
            atual->setAnterior(novo);
            inicio = novo;
        }
        tamanho++;
    }



    void insereFim(Tipo valor)
    {
        Elemento<Tipo>* novo = criarElemento(valor);   //criar novo elemento
        //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
        if(inicio==NULL)
        {
            inicio=novo;
            fim=novo;
            //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
        }
        else
        {
            Elemento<Tipo>* atual; //criar novo elemento caso tenha dado no inicio da lista.
            atual = fim;
            novo->setAnterior(atual);
            atual->setProximo(novo);
            fim = novo;
        }
        tamanho++;
    }


    void insereValorPosicao(Tipo valor, int posicao)
    {

        Elemento<Tipo>* novo = criarElemento(valor);   //criar novo elemento
        //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
        if(inicio==NULL)
        {
            inicio=novo;
            fim=novo;
            //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
        }
        else if(posicao > this->tamanho)
        {
            insereFim(valor);
        }
        else
        {
            Elemento<Tipo>* atual; //criar novo elemento caso tenha dado no inicio da lista.
            Elemento<Tipo>* anterior;

            int i;

            if(posicao < (this->tamanho/2))
            {
                i = 1;
                atual = inicio;

                while (i != posicao && atual != NULL)
                {
                    i++;
                    atual = atual->getProximo();
                }
            }else{
                i = tamanho;
                atual = fim;

                while (i != posicao && atual != NULL)
                {
                    i--;
                    atual = atual->getAnterior();
                }

            }


            if(i == 1)
            {
                insereInicio(valor);
            }
            else if(atual == NULL)
            {
                insereFim(valor);
            }
            else
            {

                anterior = atual->getAnterior();

                novo->setProximo(atual);
                novo->setAnterior(anterior);
                atual->setAnterior(novo);
                if(anterior != NULL)
                {
                    anterior->setProximo(novo);
                }
            }


        }
        tamanho++;
    }


    void insereOrdenado(Tipo valor)
    {

        Elemento<Tipo>* novo;   //criar novo elemento
        //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
        if(inicio==NULL)
        {
            novo = criarElemento(valor);

            inicio=novo;
            fim=novo;
            //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
        }
        else
        {
            Elemento<Tipo>* atual = inicio; //criar novo elemento caso tenha dado no inicio da lista.
            Elemento<Tipo>* anterior;

            while (atual != NULL && atual->getValorComparacao() < valor)
            {
                atual = atual->getProximo();
            }

            if(atual == NULL)
            {
                insereFim(valor);
            }
            else if(atual->getAnterior() == NULL)
            {
                insereInicio(valor);
            }
            else
            {
                novo = criarElemento(valor);

                anterior = atual->getAnterior();

                novo->setProximo(atual);
                novo->setAnterior(anterior);
                atual->setAnterior(novo);
                if(anterior != NULL)
                {
                    anterior->setProximo(novo);
                }
            }
        }
        tamanho++;
    }



    Elemento<Tipo>* removeInicio()
    {
        if(is_vazia())
        {
            return NULL;
        }
        else
        {
            Elemento<Tipo>* p = inicio;
            Elemento<Tipo>* atual = inicio;

            inicio = atual->getProximo();
            inicio->setAnterior(NULL);
            tamanho--;
            return p;
        }

    }


    Elemento<Tipo>* removeFim()
    {
        if(is_vazia())
        {
            return NULL;
        }
        else
        {

            Elemento<Tipo>* p = fim;
            Elemento<Tipo>* atual = fim;

            fim = atual->getAnterior();
            fim->setProximo(NULL);
            tamanho--;

            return p;

        }
    }

    Elemento<Tipo>* remover(Tipo valor)
    {
        Elemento<Tipo>* p = this->inicio;
        Elemento<Tipo>* anterior = NULL;
        Elemento<Tipo>* proximo = NULL;

        if(is_vazia())return NULL;

        while(p != NULL && p->getValorComparacao() != valor){
            p = p->getProximo();
        }

        if(p == NULL)return NULL;

        anterior = p->getAnterior();
        proximo = p->getProximo();

        if(anterior == NULL){
            return removeInicio();
        }else if(proximo == NULL){
            return removeFim();
        }else{
            anterior->setProximo(proximo);
            proximo->setAnterior(anterior);
            tamanho--;
            return p;
        }
    }



    Elemento<Tipo>* pesquisar (Tipo valor)
    {
        Elemento<Tipo>* tmp;
        if (is_vazia())
        {
            tmp = NULL;
        }
        else
        {
            tmp = inicio;
            while(tmp != NULL)
            {
                if (tmp->getValorComparacao() == valor) return tmp;
                tmp = tmp->getProximo();
            }
        }
        return tmp;
    }

    int igual(Lista lista2){
        Elemento<Tipo>* p1;
        Elemento<Tipo>* p2;

        for(p1 = this->inicio, p2 = lista2.getInicio();
            p1 != NULL && p2 != NULL;
            p1 = p1->getProximo(), p2 = p2->getProximo())
            {
                if(p1->getValorComparacao() != p2->getValorComparacao()) return 0;
            }

        return p1 == p2;

    }

};



int main()
{
    fastIO;

    //Criar lista
    Lista<int> lista1;
    Lista<int> lista2;

    //Inserir
    lista1.insereOrdenado(30);
    lista1.insereOrdenado(10);
    lista1.insereOrdenado(20);

    lista1.insereFim(50);
    lista1.insereInicio(100);
    lista1.insereValorPosicao(40, 1);

    lista2.insereInicio(10);

    //Remover
    Elemento<int>* elemento = lista1.removeInicio();
    cout << "Elemento removido da lista 1: " << elemento->getValor() << "\n";

    lista1.removeFim();
    lista1.remover(20);

    //Imprimir lista
    cout << "Lista 1: ";
    lista1.imprimeLista();

    cout << "Lista 1 invertida: ";
    lista1.imprimeListaContrario();

    cout << "Lista 2: ";
    lista2.imprimeLista();

    //Verificar igualdade
    if(lista1.igual(lista2)){
        cout << "Listas iguais\n";
    }else{
        cout << "Listas diferentes\n";
    }

    //Pesquisar Elemento
    if(lista1.pesquisar(80)){
        cout << "Elemento 80 existe na lista 1\n";
    }else{
        cout << "Elemento 80 nao existe na lista 1\n";
    }

    return 0;

}


/*

Saida:


Elemento removido da lista 1: 40
Lista 1: 100, 10, 30
Lista 1 invertida: 30, 10, 100
Lista 2: 10
Listas diferentes
Elemento 80 nao existe na lista 1

*/
