#include <stdio.h>
#include <stdlib.h>     // malloc()

int max_value(int array[], int length) {

    int max = array[0];

    for (int i = 0; i < length; i++) {

        if (max < array[i]) {

            max = array[i];
        }
    }

    return max;
}

int main()
{
    int max;
    int* temp_array;
    int before_sort[6] = { 1, 0, 3, 1, 3, 1 };
    int after_sort[6] = { 0, };
    
    max = max_value(before_sort, 6);
    temp_array = (int*)malloc(sizeof(int) * (max + 1));

    for (int i = 0; i < (max + 1); i++) {

        temp_array[i] = 0;
    }

    // 각 원소 갯수 계산
    for (int i = 0; i < 6; i++) {

        temp_array[before_sort[i]]++;
    }

    // 누적합 계산
    for (int i = 1; i < (max + 1); i++) {
        
        temp_array[i] += temp_array[i - 1];
    }

    // 누적합을 이용해 정렬
    for (int i = 5; i >= 0; i--) {

        after_sort[--temp_array[before_sort[i]]] = before_sort[i];
    }

    /*
        // 안정정렬
        for (int i = 0; i < 6; i++) {

            after_sort[--temp_array[before_sort[i]]] = before_sort[i];
        }
    */
    
    // 결과
    printf("Before Counting Sort : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", before_sort[i]);
    }
    printf("\n");

    printf("After Counting Sort : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", after_sort[i]);
    }
    printf("\n");

	return 0;
}