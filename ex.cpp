#include <iostream>

using namespace std;

void buildHeap(int arr[], int size) {
	int roop = 1, parent = 1, child = 1;

	for (int i = size; i >= 1; i--) {
		child = i;
		parent = child / 2;
		while (arr[child -1] > arr[parent - 1] && parent != 0)
		{
			swap(arr[child - 1], arr[parent - 1]);
			child = parent;
			parent = child / 2;
		}
	}
}

void heapify(int start, int end, int arr[]) {
	int current = start;
	int leftchild = 2 * current;
	int rightchild = 2 * current + 1;

	if (leftchild <= end && arr[current - 1] < arr[leftchild - 1]) current = leftchild;
	if (rightchild <= end && arr[current - 1] < arr[rightchild - 1]) current = rightchild;

	if (start != current) {
		swap(arr[start - 1], arr[current - 1]);
		heapify(current, end, arr);
	}
}

void heapSort(int arr[], int size) {
	buildHeap(arr, size);
	for (int i = size; i > 1; i--) {

		swap(arr[0], arr[i - 1]);
		heapify(1, i - 1, arr);
	}
}


int Add(int arr[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += arr[i];
	}
	return total;
}

float Average(int total, int size) {
	float average = (float)(total / size);
	return average;
}

int main()
{
	int arr = 0;
	int count = 0;
	int scending = 0;
	
	while (true) {
		std::cout << "입력할 숫자의 갯수는 몇개입니까?";
		if (cin >> arr) {
			break;
		}
		else {
			cout << "잘못된 입력입니다 \n";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	int* arrp = new int[arr];


	while (count < arr){
		std::cout << "숫자를 입력하세요";

		if (!(cin >> arrp[count])) {
			cout << "잘못된 입력입니다 \n";
			cin.clear();
			cin.ignore(100, '\n');
			
		}
		else {
			count++;
		}
	}

	while (true) {
		std::cout << "오름차순(1) 내림차순(2)";
		if (cin >> scending) {
			if (1 <= scending && scending <= 2)
			{
				break;
			}
			else {
				cout << "잘못된 입력입니다 \n";
				cin.clear();
				cin.ignore(100, '\n');
			}
			
		}
		else {
			cout << "잘못된 입력입니다 \n";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	heapSort(arrp, arr);

	if (scending == 1) {
		for (int i = 0; i < arr; i++) {
			cout << arrp[i];
		}
	}
	else {
		for (int i = arr - 1; i >= 0; i--) {
			cout << arrp[i];
		}
	}
	cout << endl;

	int total = Add(arrp, arr);
	std::cout << "합 :" << total;
	std::cout << "평균 :" << Average(total, arr);

	delete[] arrp;
	return 0;
}