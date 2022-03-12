/*
 ============================================================================
 Name        : teste_merge_sort.c
 Author      : Otto
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int merge(int array[], int ini, int mid, int fini){

	int tam1 = mid - ini + 1;
	int tam2 = fini - mid;
	int i = 0;
	int j = 0;


//	int* left_array = (int*) malloc (sizeof(int) * (tam1 + 1));
	int left_array[tam1];

	if(left_array == NULL){
		return EXIT_FAILURE;
	}

//	int* right_array = (int*) malloc (sizeof(int) * (tam2 + 1));
	int right_array[tam2];

	if(right_array == NULL){
		return EXIT_FAILURE;
	}

	//Faz a copia da primeira metade do array prum novo array de nome left
	for(i = 0; i < tam1; i++){

		//Esse ini + 1 -1 é tipo um offset.
		//Porque quando o algoritmo tá analisando o meio do vetor
		//o ini não é o indíce 0 mais. Pode ser o indíce 99 por exemplo.
		//Daí você coloca o valor atual do ini e aí que soma o indexador i.
		//Se usa o -1 (ainda não sei o porquê)

		left_array[i] = array[ini + i];

	}

	//Faz a copia da outra metade do array prum novo array de nome right
	for(j = 0; j < tam2; j++){

		//Esse mid + i é tipo um offset.
		//Porque quando o algoritmo tá analisando o meio do vetor
		//o mid não é o indíce 0 mais. Pode ser o indíce 99 por exemplo.
		//Daí você coloca o valor atual do ini e aí que soma o indexador i.

		right_array[j] = array[mid + j + 1];

	}


	//O '*' vai servir como sentinela, pra saber quando se chegou no fim do vetor.
//	left_array[tam1] = 99999;
//
//	right_array[tam2] = 99999;

	i = 0;
	j = 0;
	int k;

	//Aqui é onde a mágica de verdade acontece
	for (k = ini; k <= fini; k++){

		//Aqui a gente compara o um elemento do array left com um do array right;
		//Se o do left for menor, ele vai e é copiado pro array original, sobrescrevendo
		//o item que tava naquela posição antes;
		if(i < tam1 && j < tam2){


			if(left_array[i] <= right_array[j]){

	//			if(left_array[i] != (int) '*'){
					array[k] = left_array[i];
	//				array[k + 1] = right_array[j];
					i++;
	//			}

			}
			else{
	//			if(right_array[j] != (int) '*'){
					array[k] = right_array[j];
	//				array[k + 1] = left_array[i];
					j++;
	//			}
			}

		}

		else if(i >= tam1){
			array[k] = right_array[j];
			j++;

		}

		else{

			array[k] = left_array[i];

			i++;

		}





	}

	return 0;
}



void merge_sort(int array[], int ini, int fini){

	if(ini < fini){
		//Se ini for menor que fini, quer dizer que o vetor ainda falta casas para ser percorrido.
		//Se ini >= fini, quer dizer que o vetor só tem uma posição ou que ele já foi percorrido.
		//   _ _ _ _ _
		//	|1_|_|_|_|_|
		//
		int mid = (ini +  fini)/2; //Acha o meio e faz uma divisão arredondando pra baixo.

		merge_sort(array, ini, mid);
		merge_sort(array, mid + 1, fini);
		merge(array, ini, mid, fini);



	}
//	return 0;
}




void imprimir_valores(int array[], int tam){

	printf("Imprimindo valores: \n");

	for(int i = 0; i < tam; i++){

		printf(" %d ", array[i]);

	}

}


int main(void) {

	printf("!!!Hello World!!!"); /* prints !!!Hello World!!! */

//	int* array = (int*) malloc (sizeof(int) * 5);
	int tam  = 5;
	int array[tam];

	if(array == NULL){
		printf("Falha na alocação do vetor");
		return EXIT_FAILURE;
	}

////	array = {5,2,4,3,1
//
	array[0] = 5;
	array[1] = 2;
	array[2] = 8;
	array[3] = 3;
	array[4] = 1;
//
	merge_sort(array, 0, tam - 1);

	imprimir_valores(array, tam);


	return EXIT_SUCCESS;
}
