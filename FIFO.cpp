/*
	Name: FIFO.cpp
	Author: Hyago santos
	Date: 11/08/26 11:40
	Description: Programa para implementação de uma fila do tipo FIFO - First in first out;
*/
//FILA primeira aula!!
#include <stdio.h>
#include <windows.h>
	int itens[5];
	int tam = 5;
	int inc = -1; 
	int fim = -1;
	// Prototipação das funções
	void enqueue(int); //Insere um elemento na fila
	int dequeue(); // Retira um elemento do fifo
	int isfull(); // Testa se esta cheia o FIFO(fila)
	void showFIFO(); //exibe o conteudo da fila
	int isEmpty(); // Testa se a fila(fifo) esta vazia
 
main()
{
int opc;
while(1)
{
	system("cls");	
	puts("Menu para manipuklar a fila - FIFO");
	puts("===================================");
	puts("1 - Inserir na FIFO\n2 - Retira da FIFO\n3 - Exibir\n4 - Sair...");
	puts("===================================");
	printf("Escolçha sua opcao: ");
	scanf("%d", &opc);
	
	switch(opc)
	{
		case 1: int elem;
				printf("\nDigite um elemento");
				scanf("%d", &elem);
				enqueue(elem);
				break;
		case 2: dequeue();
				break;
		case 3: showFIFO();
				break;
		case 4: exit(0);
		default: puts("anta, escolha a opc");
	}
	Sleep(2000); 
	}
}
//Função para inserir um elemento na FIFO (Enfilheirar)
void enqueue(int elem)
{
	if(isfull() == 1)
		puts("\n FILA CHEIA!! ");
	else
	{
		if(inc == -1)
			inc = 0;
		fim = (fim+1)%tam;
		itens[fim] = elem;
		printf("\n elemento %d foi inserido no fifo", elem);
	}
}
 
//Função para retira um elemento na FIFO
int dequeue()
{
	int elem;
	if(isEmpty() == 1)
	{
		puts("\n======>A FILA ESTA VAZIA!!!");
		return -1;
	}
	else{
		elem == itens[inc];
		if(inc == fim)
		{
			inc = -1;
			fim = -1;
		}
		else{
			inc = (inc+1)%tam;
		}
		printf("\n o numero %d foi retirado da FILA", elem);
		return elem;
	}
}
 
//Função para testa se FIFO esta cheia
int isfull()
{
	if((inc == (fim +1)%tam) || (inc == 0 && fim == tam -1))
		return 1; // retorn true se estiver cheia 
	else
		return 0; // retorn false se estiver cheia 
}
 
//Função para testa se FIFO esta vazia
int isEmpty()
{
	if(inc == -1)
		return 1; // retorn true se fila estiver vazia 
	else 
		return 0; // retorn false se fila estiver não vazia 
}
 
//Função para exibir todo o conteudo de FIFO(fila)
void showFIFO()
{
	int i;
	if(isEmpty() == 1)
		puts("\n===> A FIFO ESTA VAZIA!!!");
	else
	{
		puts("\nConteudo da fila: ");
		for(i = inc; i!=fim; i = (i+1)%tam)
		{
			printf("%d|", itens[i]);
		}
		printf("%d|", itens[i]);
	}	
}
