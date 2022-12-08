# include <stdio.h>

// 두 변수의 값을 바꿔주는 함수
void swap(int *arr, int start, int end)
{
	int tmp = arr[start];
	arr[start] = arr[end];
	arr[end] = tmp;
}

// pivot을 기준으로 왼쪽 오른쪽을 나누고, 오른쪽 부분의 시작 인덱스를 반환하는 함수
int partition(int *arr, int start, int end)
{
	int pivot = arr[(start + end) / 2];

	while (start <= end)
	{
		while (arr[start] < pivot) start++;
		while (arr[end] > pivot) end--;
		if (start <= end)
		{
			swap(arr, start, end);
			start++;
			end--;
		}
	}

	return start;
}

void quick_sort(int *arr, int start, int end)
{
	int right_part = partition(arr, start, end);

	// 왼쪽 부분에 요소가 하나뿐이라면 재귀호출을 해줄 필요가 없다.
	if (start < right_part - 1)
		quick_sort(arr, start, right_part - 1);
	// 오른쪽 부분에 요소가 하나뿐이라면 재귀호출을 해줄 필요가 없다.
	if (right_part < end)
		quick_sort(arr, right_part, end);
}

int main()
{
	int i;
    int arr[10] = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
	
	printf("Before Quick Sort: ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	quick_sort(arr, 0, 9);

	printf("Before Quick Sort: ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}