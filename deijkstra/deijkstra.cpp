// deijkstra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>


struct node {
	int num;
	int metrick;
};


int main()
{	
	int N;
	scanf("%i",&N);

	if (N < 0 || N> 5000) {
		printf("bad number of vertices");
		return 0;
	}

	int S, F;
	scanf("%i",&S);
	scanf("%i",&F);

	int M;
	scanf("%i", &M);
	if (M<0 || M>M*(N + 1) / 2) {
		printf("bad number of edges");
		return 0;
	}

	int  *matrix = (int*)malloc(sizeof(int)*N*N);

	struct node *graph = (struct node *)malloc(sizeof(struct node)*N);
	
	int i = 0;
	while (i < N) {
		graph[i].num = i;
		if (i == S) {
			graph[i].metrick = 0;
		}
		else {
			graph[i].metrick = INT_MAX;
		}
		i++;
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(matrix + i * N + j) = 0;
		}
	}


	int a, b, c;
	int count = 0;
	while (scanf("%i",&a) != EOF){
		scanf("%i", &b);
		scanf("%i",&c);
		if (a<0 || a> N) {
			printf("bad vertex");
			return 0;
		}
		if (b<0 || b> N) {
			printf("bad vertex");
			return 0;
		}
		if (c<0 || c > INT_MAX) {
			printf("bad length");
			return 0;
		}

		*(matrix + (a - 1)*N + b - 1) = c;
	}


	//Берем самую легкую вершину из массива начиная с S 
	//Обновляем метрики смежных вершин через матрицу смежности
	//Проходом по массиву с вершинами ищем самую минимальную начинаем с шага 1
	//Сортируем вершины и увеличиваем счетчик вершины которую сейчас обрабатываем




	if (count!= M) {
		printf("bad number of lines");
		return 0;
	}


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
