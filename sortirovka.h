#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
#include <math.h>

template<class sort>
void Sortsel(sort& arr, const size_t size)
{
	for (auto i = 0; i < size; ++i) // i - номер текущего шага
	{
		auto pos = i;
		auto tmp = arr[i];
		for (auto j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp; // меняем местами наименьший с a[i]
	}
};

template<class sort>
void Sortbub(sort& arr, size_t size)
{
	for (auto i = 0; i < size - 1; ++i) // i - номер прохода
	{
		for (auto j = 0; j < size - 1; ++j) // внутренний цикл прохода
		{
			if (arr[j + 1] < arr[j])
			{
				auto tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
};

template<class sort>
void Sortshel(sort& arr, size_t n) //сортировка Шелла
{
	auto d = n / 2;
	while (d > 0)
	{
		for (auto i = 0; i < n - d; i++)
		{
			auto j = i;
			while (j >= 0 && arr[j] > arr[j + d])
			{
				auto count = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}

template<class sort>
void Sortquick(sort& arr, size_t left, size_t right)
{
	auto i = left, j = right-1;
	auto mid = (left + right-1) / 2;
	auto p = arr[mid];
	if (i == j) {
		auto temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
		return;
	}

	do {
		while ((arr[i] <= p) && (i < right-1)) ++i;
		while ((arr[j] >= p) && (j > left)) --j;

		if (i < j) {
			auto temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
			++i; --j;
		}
		if (i == j) break;
	} while (i <= j);

	// рекурсивные вызовы, если есть, что сортировать 
	if (j > left) Sortquick(arr, left, j);
	if (right > i+1) Sortquick(arr, i+1, right);

};

template <class sort>
void Sortnat_twoway_merg(sort& arr, int size) {
	arr.resize(size * 2);
	bool s = true, f = true;
	int i, j, k, l;
	do {
		if (s) {
			i = 0, j = size / 2 - 1, k = size / 2, l = size - 1;
		}
		else {
			k = 0, l = size / 2 - 1, i = size / 2, j = size - 1;
		}
		int d = 1;
		f = false;
		while (true) {
			if (i == j) {
				arr[k] = arr[i];
				s = !s;
				break;
			}
			if (arr[i] < arr[j]) {
				arr[k] = arr[i];
				k = k + d;
				++i;
				if (arr[i - 1] <= arr[i]) continue;
				do {
					arr[k] = arr[j];
					k = k + d;
					--j;
				} while (arr[j + 1] <= arr[j]);
			}
			else {
				arr[k] = arr[j];
				k = k + d;
				--j;
				if (arr[j + 1] <= arr[j]) continue;
				do {
					arr[k] = arr[i];
					k = k + d;
					++i;
				} while (arr[i - 1] <= arr[i]);
			}
			f = true;
			d = -d;
			swap(k, l);
		}
	} while (f);
	if (s)
		arr.resize(size / 2);
	else {
		for (size_t c = 0; c < size / 2; ++c)
			arr[c] = arr[c + size / 2];
		arr.resize(size / 2);
	}
}



