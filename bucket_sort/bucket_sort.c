#include <stdio.h>

#define size_of_array 100

/*
	Bucket Sort

	- 가장 간단한 정렬 알고리즘
	- 처리가 간단한 대신 장소적 자원(배열의 크기)을 많이 소모함
	- 빈 양동이 배열을 준비하고, 양동이의 번호와 일치하는 모든 데이터를 저장한
	  다음에 1번째 양동이의 데이터부터 꺼내는 것

	Time Complexity	 
	Best	O(n+k)
	Worst	O(n2)
	Average	O(n)
	Space Complexity	O(n+k)
	Stability	Yes


	- 참고
	스기우라 켄 / 그림으로 배우는 알고리즘 Algorithm Basic
	jooharm's blog / https://blog.naver.com/jooharm/221600060686
	GeeksforGeeks / https://www.geeksforgeeks.org/bucket-sort-2/
	ratsgo's blog / https://ratsgo.github.io/data%20structure&algorithm/2017/10/18/bucketsort/
*/

// 0.0 ~ 10.0 사이의 소수점 첫번째 자리를 가지는 숫자로 이루어진 array를 정렬하는 bucket sort
void Bucket_Sort(double arr[], int n) {
	
	double bucket_arr[10][size_of_array];		// bucket array 설정
	int count[10] = { 0, };
	int which_bucket, cnt = 0;

	// bucket_arr에 정렬
	for (int i = 0; i < n; i++) {
		which_bucket = arr[i] / 1;	// 정수 부분으로 나누기
		bucket_arr[which_bucket][count[which_bucket]] = arr[i];		// 정수 부분에 해당하는 column에 값 저장
		count[which_bucket]++;	// row 증가
	}

	// arr에 대입
	which_bucket = 0;
	while (which_bucket < 10 && cnt < n) {		// loop를 통해 bucket array에 정렬된 값 원래 array에 저장
		for (int j = 0; j < count[which_bucket]; j++) {
			if (bucket_arr[which_bucket][j] != 0) {
				arr[cnt] = bucket_arr[which_bucket][j];
				cnt++;
			}
		}
		which_bucket++;
	}
}

int main() {
	
	double arr[10] = { 0.1,1.1,4.2,0.6,2.3,1.7,3.0,6.1,3.5,6.6 };

	printf("Before bucket sort : ");
	for (int i = 0; i < 10; i++) {
		printf("%.1f ", arr[i]);
	}
	printf("\n\n");

	Bucket_Sort(arr, 10);

	printf("After bucket sort : ");
	for (int i = 0; i < 10; i++) {
		printf("%.1f ", arr[i]);
	}
	printf("\n\n");

	return 0;
}