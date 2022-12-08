#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 나누어진 왼쪽 오른쪽 부분을 병합하는 함수
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	for (int i = start; i <= end; i++)
		tmp[i] = arr[i];
	int left = start;
	int right = mid + 1;
	int idx = start;

	while (left <= mid && right <= end)
	{
		if (tmp[left] <= tmp[right])
		{
			arr[idx] = tmp[left];
			left++;
		}
		else
		{
			arr[idx] = tmp[right];
			right++;
		}
		idx++;
	}

	// 앞쪽 데이터가 남아있을 경우
	for (int i = 0; i <= mid - left; i++)
		arr[idx + i] = tmp[left + i];
}

// 재귀를 통해 최소 단위로 배열을 나누어주고 병합하여 정렬
void merge_sort(int *arr, int *tmp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(arr, tmp, start, mid);
		merge_sort(arr, tmp, mid + 1, end);
		merge(arr, tmp, start, mid, end);
	}
}

int main()
{
	int i;
	int arr[10] = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
	int *tmp = (int *)malloc(sizeof(int) * 10);

	memset(tmp, 0, sizeof(int) * 10);

	printf("Before Merge Sort: ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	merge_sort(arr, tmp, 0, 9);

	printf("Before Merge Sort: ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;

}