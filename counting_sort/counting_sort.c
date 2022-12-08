
#include <string.h>     // memset()
#include <stdio.h>
#include <stdlib.h>     // malloc()

int get_max(int array[], int length)
{
    int max_val = array[0];

    for (int i = 0; i < length; i++)
        if (max_val < array[i])
            max_val = array[i];

    return max_val;
}

int main()
{
    int max_val;
    int* tmp_arr;
    int before_sort[6] = { 1, 0, 3, 1, 3, 1 };
    int after_sort[6] = { 0, };
    
    max_val = get_max(before_sort, 6);
    tmp_arr = (int*)malloc(sizeof(int) * (max_val + 1));
    memset(tmp_arr, 0, sizeof(int) * (max_val + 1));

    // 각 원소 갯수 계산
    for (int i = 0; i < 6; i++)
        tmp_arr[before_sort[i]]++;

    printf("Element Count: ");
    for (int i = 0; i < max_val + 1; i++)
        printf("%d ", tmp_arr[i]);
    printf("\n");

    // 누적합 계산
    for (int i = 1; i < (max_val + 1); i++)
        tmp_arr[i] += tmp_arr[i - 1];
    printf("Cumulative Sum: ");
    for (int i = 0; i < max_val + 1; i++)
        printf("%d ", tmp_arr[i]);
    printf("\n");

    // 누적합을 이용해 정렬
    for (int i = 5; i >= 0; i--)
        after_sort[--tmp_arr[before_sort[i]]] = before_sort[i];

    // 결과
    printf("Before Counting Sort : ");
    for (int i = 0; i < 6; i++)
        printf("%d ", before_sort[i]);
    printf("\n");

    printf("After Counting Sort : ");
    for (int i = 0; i < 6; i++)
        printf("%d ", after_sort[i]);
    printf("\n");

	return 0;
}