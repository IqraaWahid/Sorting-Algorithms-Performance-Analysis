#include "mySort.h"
#include "metrics.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last){
	unsigned int i=first; //left half pointer (to keep track) of position in array
	unsigned int j=mid+1; //right half pointer
	unsigned int k=0; //pointer of temporary array
	
	int temp[last-first +1]; //temporary array: stores merged results
	
	while (i<=mid && j<=last){ //while both halves still have elements
		//if(array[i] <= array[j]){
		if (myCompare(array[i], array[j]) <=0){ // if the left element is smaller than or equal to the right element
			//temp[k++]=array[i++];
			myCopy(&array[i], &temp[k]); //copy the left element into the temporary array
			i++; k++;
		}
		else{ //otherwise, if the right element is greater, then copy the right element into the temporary array
			//temp[k++] = array[j++];
			myCopy(&array[j], &temp[k]);
			j++; k++;
		}
		//as seen above, the smaller element of the two sub arrays are always copied into the temporary array 
	}
	
	//copy the remaining elements into the temporary array
	
	//copy remaining left elements
	while (i<= mid){
		//temp[k++] = array[i++];
		myCopy(&array[i], &temp[k]);
		i++; k++;
	}
	
	//copy remaining right elements
	while (j<= last){
		//temp[k++]=array[j++];
		myCopy(&array[j], &temp[k]);
		j++; k++;
	}
	
	//copy the temporary array into the original array; replacing the original sub array with the sorted merged result
	for(i=0;i<k;i++){
		//array[first+i]=temp[i];
		myCopy(&temp[i], &array[first+i]);
	}
}

void mySort(int array[], unsigned int first, unsigned int last){ //recursion function
	//stopping condition for recursion: checks if the subarray has 1 or 0 elements (that are already sorted since there is only 1/0 elements in the array)
	if(first>= last){ 
		return;
	}
	
	unsigned int mid=(first + last)/2; //finding the middle index of the array; splitting the array into two
	
	//recursive calls: keep splitting the array until size = 1 (tree structure of merge sort as seen in lectures)
	mySort(array, first, mid); //left side of the array
	mySort(array, mid+1, last); // right side of the array
	
	merge(array, first, mid, last); //this call allows the two halves to be sorted individually, and then merged into one sorted subarray
}
