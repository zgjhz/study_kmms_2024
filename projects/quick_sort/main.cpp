// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include "quick_sort.hpp"

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);


    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    QuickSort::quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}
