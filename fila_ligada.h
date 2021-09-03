#ifndef FILA_LIGADA_H_
#define FILA_LIGADA_H_


#include<iostream>
using namespace std;


template<class T>
class Fila{
    private:
typedef int Dados;

struct Node{
    Dados dados;
    Node* prox;
};
int size;
int cap;
Node* ini; 
Node* end;
   public: 
   Fila(int capacidade){
       ini = NULL;
       end = NULL;
       this->cap = capacidade;
       size = 0;
   }
   
   ~Fila(){

   }

   void enfileira(T item){
    Node* NovoNo = new Node;
    if(size>=cap){
        throw "Queue overflow";
    }else{
        NovoNo->dados = item;
        NovoNo->prox = NULL;
        if(ini==NULL){
            ini = NovoNo;
        }else{
            end->prox = NovoNo;
        }
        end = NovoNo;
    }
size++;
   }

   T desenfileira(){
       if(size==0){
           throw "Queue underflow";
       }else{
           Node* temp;
           temp = ini;
           Dados item;
           item = ini->dados;
           ini = ini->prox;
        if(ini==NULL){
           end = NULL;
       }
       size--;
       delete temp;
       return item;
       }
       
 
   }
 int cheia(){
        if(size == cap){
            return 1;
        }else{
            return 0;
        }
    }

    int vazia(){
        if(size == 0){
            return 1;
        }else{
            return 0;
        }
    }

   int tamanho(){
       return size;
   }
};
#endif // fila_ligada