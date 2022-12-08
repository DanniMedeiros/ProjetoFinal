#include <iostream>
using namespace std;
#define maximo 10


struct cincof{
 int dado;
 cincof *prox;
};

struct cincop{
  int dado;
  cincop *prox;
};

void push(cincop * & topo){
  
 int dado = 1;

  while(dado != 0){
    cout << "\n\nDigite o valor:\n";
    cin >> dado;
    
   if(dado >= 1){
     
     if(topo == NULL){  
       
      cincop *novo = NULL;  
       novo = (cincop*) calloc (1, sizeof(cincop));  
       novo->dado = dado; 
       topo = novo;
       topo->prox = NULL;  
      
      cout << "\n  --- Valor " << dado << " Adicionado à pilha! ---\n\n"; 
    }  
       
     else{ 
      cincop *novo = NULL;
      novo = (cincop*) calloc (1, sizeof(cincop)); 
     
      novo->dado = dado;
      novo->prox = topo;
      topo = novo;
      cout << "\n  --- Valor " << dado << " Adicionado à pilha! ---\n\n"; 
      }
   }
   else{
      cout <<"Valor 0 acionado, pilha encerrada!\n";
    }
    } 
  }
  
int pop(cincop * & topo){ 
  
	cincop * aux = topo;              
  int val= aux->dado;                   

  if(aux->prox == NULL){
    free(aux);
    return val;
  }
    
  else{
	 topo = aux->prox;      
   free(aux);               
	 return val;
   }   
 }

void enqueue(cincof * & primeiro, cincof * & ultimo, int dado){

    if(ultimo == NULL){   
      
    cincof *novo = NULL;  
     novo = (cincof*) calloc (1, sizeof(cincof)); 
      
     novo->dado = dado;   
     novo->prox = NULL;  
     primeiro = novo;   
     ultimo = novo;
     return;
      }
      
    else { 
    cincof *novo = NULL; 
    novo = (cincof*) calloc (1, sizeof(cincof));
      
      novo->dado = dado;
      novo->prox = NULL;
      ultimo->prox = novo;
      ultimo = novo; 
   } 
  }
      
void pilhaPfila(cincop *& topo, cincof *& primeiro_par, cincof *& ultimo_par, cincof *& primeiro_impar, cincof *& ultimo_impar){
  
 cincop *aux = topo;
 
  while(aux->prox != NULL){
    cout <<"\n\nO topo atual é: "<<aux->dado;
    
     if(aux->dado %2 == 0){
     cout<<"  (PAR)\n\n";
     enqueue(primeiro_par, ultimo_par, pop(aux));
    }
       
    else{
   cout << "  (IMPAR)\n\n";
     enqueue(primeiro_impar, ultimo_impar, pop(aux));
    }
}
  if((aux->dado % 2) == 0 ){
    cout <<"\n\nO topo atual é: "<<aux->dado;
    cout<<"  (PAR)\n\n";
    enqueue(primeiro_par, ultimo_par, pop(aux));
  }

  else{
    cout <<"\n\nO topo atual é: "<<aux->dado;
    cout << "  (IMPAR)\n\n";
    enqueue(primeiro_impar, ultimo_impar, pop(aux));
  }

  
 cincof *aux_par = primeiro_par;
 cincof *aux_impar = primeiro_impar;

  if(aux_par == NULL){
    cout<<"\n\nNenhum elemento PAR encontrado!\n";
  }
  else{
  cout << "\n\nfila par:\n";
  while(aux_par != NULL){
    cout <<"\t" << aux_par->dado;
    aux_par = aux_par->prox;
  }
  }
  
  if(aux_impar == NULL){
    cout<<"\n\nNenhum elemento IMPAR encontrado!\n";
    }
  else{
  cout << "\n\nfila impar:\n";
  while(aux_impar != NULL){
    cout <<"\t"<< aux_impar->dado;
    aux_impar = aux_impar->prox;
    }
  }
}

int main() {

  cincop *topo = NULL;

  push(topo);

  cincof * f1pri = NULL;
  cincof * f1ult = NULL;
  cincof * f2pri = NULL;
  cincof * f2ult = NULL;

  pilhaPfila(topo, f1pri, f1ult, f2pri, f2ult);
  
}