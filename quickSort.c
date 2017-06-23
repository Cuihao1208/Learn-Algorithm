/*
It is a best sort algorithm and improvement for Bubble sort.

 */

void quickSort(int left, int right, int* nums){

	if(left < right){
		int key = nums[left];
		int i = left;
		int j = right;		
		while(i<j){
			while(i < j && key < nums[j]){
				j--;
			}
			nums[i] = nums[j];
			while(i < j && nums[i] < key){
				i++;
			}
			nums[j] = nums[i];
		}
		nums[i] = key;
		quickSort(left, i-1, nums);
		quickSort(i+1, right, nums);

	}
}