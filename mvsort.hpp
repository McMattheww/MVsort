#include<vector>

template <typename T>
void insertionSort(std::vector<T>& list, int start, int size) {
	for (int i = start + 1; i < start + size; i++)
	{
		int j = i - 1;
		while (j > start - 1 && list[j + 1] < list[j]) {
			std::swap(list[j + 1], list[j]);
			j--;
		}
	}
}

template <typename T>
void mergeSort(std::vector<T>& list, int start, int size1, int size2) {
	std::vector<T> temp(size1 + size2);

	int i = start;
	int j = start + size1;
	for (int k = 0; k < size1 + size2; k++) {
		if (j >= start + size1 + size2 || i < start + size1 && list[i] < list[j]) {
			temp[k] = list[i];
			i++;
		}
		else {
			temp[k] = list[j];
			j++;
		}
	}
	for (int i = 0; i < size1 + size2; i++) {
		list[start + i] = temp[i];
	}
}

template <typename T>
void MVsort(std::vector<T>& list) {
	//size of subarray in current iteration
	int i;
	for (i = 0; i < list.size() - 19; i += 20) {
		insertionSort(list, i, 20);
	}
	if (list.size() % 20 != 0) {
		insertionSort(list, i, list.size() % 20);
	}
	int size = 20;
	int current = 0;
	while (size < list.size()) {
		current = 0;
		while (current < (int)list.size() - (size * 2) + 1) {
			mergeSort(list, current, size, size);
			current += (size * 2);
		}
		if (list.size() % (2 * size) > size) {
			mergeSort(list, current, size, list.size() % size);
		}
		size *= 2;
	}
}



