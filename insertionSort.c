#include "mySort.h"
#include "metrics.h" //gives access to myCompare, myCopy, and mySwap

void mySort(int array[], unsigned int first, unsigned int last){
	unsigned int i,j;
	//i: current element
	//j: used to move backwards

	int key; //used to store value temporarily
	
	//i=first+1 because we assume that the first element is already sorted
	//each next element is inserted into the sorted portion (left side) accordingly
	for(i=first+1; i<=last; i++){
		//key=array[i]; --> copies the current element and stores it temporarily into 'key'
		myCopy(&array[i], &key);
		j=i;//j starts from where 'key' originally was
		
		//while (j>first && array[j-1]>key){
		while (j>first && myCompare(array[j-1], key) > 0){
			//array[j]=array[j-1];
			myCopy(&array[j-1], &array[j]);//move bigger elements one to the right
			j--;//move left
		}
		//array[j]=key;
		myCopy(&key, &array[j]);//finally inserting key(the original element working with) to its correct spot
	}
}
