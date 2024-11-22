#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

void bubbleSort(int arr[], int size) {
	int i, j, temp;
	
	for(i = 0; i < size - 1; i++) {
		for(j = i + 1; j < size; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 
			}
		}
	}
}

int main() {
	clock_t start, end;
    double time;
    randomValues(arr, SIZE);
    //printArray(arr, SIZE);
    start = clock();
	bubbleSort(arr, SIZE);
    end = clock();
    time = ((double)(end - start)) / 1000;
	printf("Sorted array:");
	printArray(arr, SIZE);
    printf("time = %f", time);
	return 0;
}
