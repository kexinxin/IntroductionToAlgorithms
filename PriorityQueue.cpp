#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

struct Heap{
	vector<int> v;
	int heapSize;
};

int parent(int i){
	return floor(i / 2);
}

int left(int i){
	return 2 * i;
}

int right(int i){
	return 2 * i + 1;
}

void maxHeapTFY(Heap &heap, int i){
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= heap.heapSize && heap.v[l] > heap.v[i])
		largest = l;
	else largest = i;
	if (r <= heap.heapSize && heap.v[r]>heap.v[largest])
		largest = r;
	if (largest != i){
		int temp = heap.v[i];
		heap.v[i] = heap.v[largest];
		heap.v[largest] = temp;
		maxHeapTFY(heap, largest);
	}
}

void buildMaxHeap(Heap &heap){
	for (int i = floor((heap.heapSize) / 2); i >= 1; i--){
		maxHeapTFY(heap, i);
	}
}

void heapSort(Heap &heap){
	buildMaxHeap(heap);
	for (int i = heap.heapSize; i >= 2; i--){
		int temp = heap.v[1];
		heap.v[1] = heap.v[i];
		heap.v[i] = temp;
		heap.heapSize = heap.heapSize - 1;
		maxHeapTFY(heap, 1);
	}
}



int main() {
	vector<int> v;
	int num;
	v.push_back(0);
	//	while ((cin.get()) != '\n'){
	//		cin.unget();
	//		cin >> num;
	//		v.push_back(num);
	//	}
	v.push_back(5);
	v.push_back(15);
	v.push_back(25);
	v.push_back(1);
	v.push_back(3);
	int size = v.size();
	Heap heap;
	heap.v = v;
	heap.heapSize = size - 1;
	heapSort(heap);
	for (int i = 1; i<size; i++){
		cout << heap.v[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}
