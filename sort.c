/*
Here are some sort algorithm.

*/

/*************************************************/

/* Best case O(n)   Worst case O(N²） */

/* Bubble Sort -- 冒泡排序 */

void Bubble_Sort(int *a, int n){  
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1 ; j++){
            if(a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    //	return a;
}

/* Bubble Sort 2 */

void Bubble_Sort2(int* a, int n){
	int temp = 0;
	for(int p = n-1; p >= 0; p--){
		int flag = 0;
		for(int i = 0; i < p; i++){
			if(a[i] > a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0) break;
	}
}

/************************************************/

/* Best case O(n)   Worst case O(N²） */

/* Insertion Sort -- 插入排序 */

void Insertion_Sort(int *a, int n){
    int temp = 0;
    int i =0;
    int p = 0;
    for( p = 1; p < n; p++){
        temp = a[p];
        for( i = p; i>0 && a[i-1]>temp; i--){
            a[i] = a[i-1];
        }
        a[i] = temp;
    }
}

/************************************************/

/* Shell sort -- 希尔排序 */

void Sort(int* a, int n){
	int d,temp;
	int p,i;
	for(d = n/2; d>0; d/=2){
		for(p = d; p<n; p++){
			temp = a[p];
			for(i = p; i>=d && a[i-d]>temp; i-=d)
				a[i] = a[i-d];
			a[i]=temp;
		}
	}
}

/************************************************/

/* Quick Sort -- 快速排序 */

void quickSort(int* a, int left, int right){
	int key = a[left];
	int i = left;
	int j = right;
	while(i<j){
		while(i<j && key<a[j]){
			j--;
		}
		a[i] = a[j];
		while(i<j && a[i]<=key){
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	quickSort(a, left, i-1);
	quickSort(a, i+1, right);
}

void Quick_Sort(int* a, int n){
	quickSort(a, 0, n-1);
}

/************************************************/

/************************************************/

/************************************************/

/************************************************/




