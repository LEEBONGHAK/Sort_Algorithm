
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 배열 중 가장 큰 값을 찾는 함수
int get_max(int *arr, int size)
{
    int max_val = arr[0];

    for (int i = 0; i < size; i++)
        if (max_val < arr[i])
            max_val = arr[i];

    return max_val;
}

void    counting_sort(int *arr, int size)
{
    int i;
    int max_val = get_max(arr, size);
    int *tmp_arr;
    int *sorted_arr;
    
    tmp_arr = (int*)malloc(sizeof(int) * (max_val + 1));
    memset(tmp_arr, 0, sizeof(int) * (max_val + 1));

    sorted_arr = (int *)malloc(sizeof(int) * size);
    memset(sorted_arr, 0, sizeof(int) * size);

    // 각 원소 갯수 계산
    for (i = 0; i < size; i++)
        tmp_arr[arr[i]]++;

    // 누적합 계산
    for (i = 1; i < (max_val + 1); i++)
        tmp_arr[i] += tmp_arr[i - 1];

    // 누적합을 이용해 정렬
    for (i = size - 1; i >= 0; i--)
        sorted_arr[--tmp_arr[arr[i]]] = arr[i];

    // 원래 배열 갱신
    for (i = 0; i < size; i++)
        arr[i] = sorted_arr[i];
    
    free(tmp_arr);
    free(sorted_arr);
}

int main()
{
    int arr[6] = { 1, 0, 3, 1, 3, 1 };

    // 결과
    printf("Before Counting Sort : ");
    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
    printf("\n");

    counting_sort(arr, 6);

    printf("After Counting Sort : ");
    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
    printf("\n");

	return 0;
}