#include <iostream>
#define maximo 8

using namespace std;

struct UM { // Estrutura que compõe a Pilha
    int INF; // Dado armazenado na Pilha
    UM *prox; // Apontamento para o proximo nivel
}; 

int quantidade(UM * & topo){ //Retorna a quantidade de niveis da pilha
  
 UM *temp = topo; //Ponteiro temporario para contar niveis
 int qnt = 0;  //Variavel que armazenara o dado
  
   while(temp != NULL){  //Enquanto ponteiro temporario não apontar para NULO
     qnt++; //Acrescenta em 1 nivel da pilha
     temp=temp->prox; //Temporario percorre todos os niveis da pilha
  } 
   return qnt; //Retorna tamanho da pilha
}

void push(UM * & topo, int INF){

  if(maximo <= 0){   //Verifica se o valor maximo definido pelo usuario nao seja 0
    printf("Pilha sem espaços disponiveis!\n");
   } 
    
  else {    
    if(topo == NULL){        //Verifica se a pilha esta inicialmente vazia
    
      UM *pilha = NULL;  //Aloca espaço para novo nivel da pilha
      pilha = (UM*) calloc (1, sizeof(UM));  
      
      if(pilha == NULL){     //Verifica se foi alocado memória
     printf("ERRO DE ALOCAÇÂO!\n");
      } 
        
      else{  //aloca elemento na pilha
      pilha->INF = INF;   //Novo nivel recebe dado informado pelo usuario
      pilha->prox = NULL;   //Nivel mais baixo da pilha aponta para NULO
      topo = pilha;         //Atualiza Topo para novo nivel
      cout << "\n\nValor " << INF << " Adicionado à pilha!\n";  
      return;
      }
   }
      
  else if(quantidade(topo) < maximo) { //verifica se pilha não esta cheia
    UM *pilha = NULL;
      pilha = (UM*) calloc (1, sizeof(UM)); //aloca ponteiro
    
    if(pilha == NULL){ 
      printf("ERRO DE ALOCAÇÂO!\n");}//verifica falha na alocação
    else{ //demais elementos da pilha
      pilha->INF = INF;
      pilha->prox = topo;
      topo = pilha;
      cout << "\nValor " << INF << " Adicionado à pilha!\n";   
     } 
    } 
   }  
  }

int pop(struct UM * & topo){  //Função para remover elementos da pilha
 
	UM * aux;               //Ponteiro váriavel
    aux = topo;
  
  int val;                   //Valor a ser removido da pilha
    val = aux->INF;
  
	 topo = aux->prox;         //Topo passa a aponta para o proximo elemento da pilha
   free(aux);                //Libera Endereço do antigo topo

  if(aux != topo){           //Verifica se o topo foi removido
    cout << "\n"<< val << " Removido da pilha!\n";
  }

  else{
    cout << "Erro ao remover nivel atual!\n";
  }
	 return val;             //Retorna valor removido da pilha
 }

void listar(UM * & topo){
  if(topo == NULL){  //Verifica se pilha está vazia
		printf("\nPilha vazia\n");
	}

  else{ //Lista todos elementos da pilha
    
		printf("\nPilha Atual:\n");
		struct UM * aux = topo;
		while(aux != NULL){ //Percorre a pilha inteira
			printf("%d\n", aux->INF);
			aux = aux->prox;  
			}
	}
}

void Isfull_Isempty(UM *& topo) { //Verifica se pilha esta vazia ou cheia 
  if(topo == NULL){ 
    cout << "\nPilha Vazia!\n";
  }
  else if(quantidade(topo) == maximo){
    cout << "\n\nPilha cheia!\n\n";
  }

  else{  //Indica quantos niveis ainda podem ser adicionados
    cout << "\nPilha com " << maximo - quantidade(topo) << " espaços disponiveis\n";
    }
}

void consultar(UM * topo, int c){ //Verifica se valor esta contido na pilha
  UM * aux;
  aux = topo;
  int nivel = 0;
 
 if(topo == NULL){
    cout << "Pilha Vazia!\n";
    return;
  }
  else{
    while(aux != NULL){
    if (aux->INF == c){ //Se valor for encontrado na pilha
      printf("Valor encontrado no nivel %d\n", nivel);
      return;
    }
    else {  //Enquanto valor não for encontrado na pilha
      aux = aux->prox; 
      nivel++;
    } 
  }
   printf("Valor não encontrado na pilha!\n");
 }
}

int main() {
  
  UM *topo = NULL; //Ponteiro que aponta para o topo da pilha
  int qtd; //Variavel que armazena tamanho da pilha

  Isfull_Isempty(topo); //Verifica situação da pilha

  for (int i=1;i<6;i++){ //Adiciona valor na pilha
   push(topo, i*5);
  }
  
  Isfull_Isempty(topo);
  
  listar(topo);  //Mostra todos os niveis atuais da pilha 
  qtd = quantidade(topo);  //Mostra quantidade de niveis na pilha
  cout << "\nQuantidade de niveis na pilha: " << qtd << "\n";  
  
  pop(topo); //Remove topo da pilha
  pop(topo);
  
  push(topo, 100);
    
  listar(topo);
  
  qtd = quantidade(topo);
  cout << "\nQuantidade de niveis na pilha: " << qtd << "\n\n";  

  consultar(topo, 5); //Busca elemento na pilha
}