#include "mvsort.hpp"

int main() {
	std::vector<int> list = { };

	for (int i = 0; i <  10000000; i++) {
		list.emplace_back(rand());
	}

	MVsort(list);
	return 0;
}