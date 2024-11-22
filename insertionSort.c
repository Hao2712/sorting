#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000 // Kích thước mảng tĩnh

int arr[SIZE];

// Hàm khởi tạo mảng tĩnh với các giá trị ngẫu nhiên
void randomValues(int arr[], int size) {
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));
    
    // Gán giá trị ngẫu nhiên cho các phần tử của mảng
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size; // Số ngẫu nhiên từ 0 đến 9999
    }
}

// Hàm in một số phần tử của mảng
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) { // In chỉ 100 phần tử đầu tiên
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size) {
	int i, j, key;

	for(i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
	
}
int main() {
	clock_t start, end;
    double time;
    randomValues(arr, SIZE);
    //printArray(arr, SIZE);
    start = clock();
	insertionSort(arr, SIZE);
    end = clock();
    time = ((double)(end - start)) / 1000;
	printf("Sorted array:");
	printArray(arr, SIZE);
    printf("time = %f", time);
	return 0;
}
