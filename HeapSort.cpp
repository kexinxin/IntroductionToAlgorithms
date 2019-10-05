#include <iostream>
#include<vector>
#include<math.h>
#include<limits.h>
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

int heapMaxiMum(Heap &heap){
	return heap.v[1];
}

int heapExtractMax(Heap &heap){
	if (heap.heapSize < 1)
		cout << "heap underflow" << endl;
	int max = heap.v[1];
	heap.v[1] = heap.v[heap.heapSize];
	heap.heapSize = heap.heapSize - 1;
	maxHeapTFY(heap, 1);
	return max;
}

void heapIncreaseKey(Heap &heap, int i, int key){
	if (key < heap.v[i])
		cout << "new key is smaller than current key";
	heap.v[i] = key;
	while (i>1 && heap.v[parent(i)] < heap.v[i]){
		int temp = heap.v[i];
		heap.v[i] = heap.v[parent(i)];
		heap.v[parent(i)] = temp;
		i = parent(i);
	}
}

void maxHeapInsert(Heap &heap, int key){
	heap.heapSize = heap.heapSize + 1;
	heap.v.push_back(INT_MIN);
	heapIncreaseKey(heap, heap.heapSize, key);
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
	v.push_back(6);
	v.push_back(8);
	v.push_back(3);
	v.push_back(16);
	int size = v.size();
	Heap heap;
	heap.v = v;
	heap.heapSize = size - 1;
	buildMaxHeap(heap);
	maxHeapInsert(heap, 100);
	cout << "the reuslt of heapSort is:" << endl;
	for (int i = 1; i<size; i++){
		cout << heap.v[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}
