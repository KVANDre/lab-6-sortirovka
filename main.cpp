#include "sortirovka.h"
#include <iostream>
#include <libutils/io.h>
#include <libutils/image.h>
#include <cstdio>
#include <chrono>
using namespace std;

template <class sort>
void print(const sort& obj, int n);
void mainMenu(int x);
void nameMenu();

int main() {
	int x = 1;
	mainMenu(x);
}

template <class sort>
void print(const sort& obj, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << obj[i] << endl;
	}
}

void nameMenu() {
	cout << "1. Selection sort" << endl;
	cout << "2. Bubble sort" << endl;
	cout << "3. Shell sort" << endl;
	cout << "4. Quick sort" << endl;
	cout << "5. Natural Two-Way Merge Sort" << endl;
	cout << "0. Exit" << endl;
}

void mainMenu(int x) {
	using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
	using Diff = std::chrono::milliseconds;
	while (x != 0) {
		int n = utils::read_int("Input the size of the array (1, 5000): ", 1, 5000);
		vector<int> A(n);
		for (int i = 0; i < n; ++i) {
			A[i] = rand();
		}
		print(A, n);
		nameMenu();
		x = utils::read_int("Choose sorting, want to go to exit choose 0 (0, 5): ", 0, 5);
		switch (x) {
		case 1: {
			cout << "Selection sort" << endl;
			Time t1 = std::chrono::high_resolution_clock::now();//начальное время
			Sortsel(A, n);
			Time t2 = std::chrono::high_resolution_clock::now();//конечное время
			Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);//время выполнения
			print(A, n);
			std::cout << "Sorting time" << diff.count() << " ms" << std::endl;//вывод времени выполнения
		}break;
		
		case 2: {
			cout << "Bubble sort" << endl;
			Time t1 = std::chrono::high_resolution_clock::now();//начальное время
			Sortbub(A, n);
			Time t2 = std::chrono::high_resolution_clock::now();//конечное время
			Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);//время выполнения
			print(A, n);
			std::cout << "Sorting time" << diff.count() << " ms" << std::endl;//вывод времени выполнения
		}break;

		case 3: {
			cout << "Shell sort" << endl;
			Time t1 = std::chrono::high_resolution_clock::now();//начальное время
			Sortshel(A, n);
			Time t2 = std::chrono::high_resolution_clock::now();//конечное время
			Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);//время выполнения
			print(A, n);
			std::cout << "Sorting time" << diff.count() << " ms" << std::endl;//вывод времени выполнения
		}break;

		case 4: {
			cout << "Quick sort" << endl;
			Time t1 = std::chrono::high_resolution_clock::now();//начальное время
			Sortquick(A, 0, n);
			Time t2 = std::chrono::high_resolution_clock::now();//конечное время
			Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);//время выполнения
			print(A, n);
			std::cout << "Sorting time" << diff.count() << " ms" << std::endl;//вывод времени выполнения
		}break;

		case 5: {
			cout << "Natural Two-Way Merge Sort" << endl;
			Time t1 = std::chrono::high_resolution_clock::now();//начальное время
			Sortnat_twoway_merg(A, n*2);
			Time t2 = std::chrono::high_resolution_clock::now();//конечное время
			Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);//время выполнения
			print(A, n);
			std::cout << "Sorting time" << diff.count() << " ms" << std::endl;//вывод времени выполнения
		}break;
		}
	}
}