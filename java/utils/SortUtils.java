package utils;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class SortUtils {
	
	public static void selectionSort(int[] arr) {
		if(arr != null && arr.length>1) {
			selectionSortAsc(arr);
		}
	}
	
	public static void selectionSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				selectionSortAsc(arr);
			}else {
				selectionSortDesc(arr);
			}
		}
	}
	
	public static void selectionSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			for(int i=0; i<arrLen-1; i++) {
				int minIndex = i;
				for(int j=i+1; j<arrLen; j++) {
					if(arr[minIndex]>arr[j]) {
						minIndex = j;
					}
				}
				if(minIndex != i) {
					swap(arr, i, minIndex);
				}
			}
		}
	}
	
	public static void selectionSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			for(int i=0; i<arrLen-1; i++) {
				int maxIndex = i;
				for(int j=i+1; j<arrLen; j++) {
					if(arr[maxIndex]<arr[j]) {
						maxIndex = j;
					}
				}
				if(maxIndex != i) {
					swap(arr, i, maxIndex);
				}
			}
		}
	}
	
	
	public static void insertionSort(int[] arr) {
		if(arr != null && arr.length>1) {
			insertionSortAsc(arr);
		}
	}
	
	public static void insertionSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				insertionSortAsc(arr);
			}else {
				insertionSortDesc(arr);
			}
		}
	}
	
	public static void insertionSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			for(int i=1; i<arrLen; i++) {
				int temp = arr[i];
				int j = i-1;
				while(j>=0 && arr[j]>temp) {
					arr[j+1] = arr[j];
					j--;
				}
				if(j+1<i) {
					arr[j+1] = temp;
				}
			}
		}
	}
	
	public static void insertionSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			for(int i=1; i<arrLen; i++) {
				int temp = arr[i];
				int j = i-1;
				while(j>=0 && arr[j]<temp) {
					arr[j+1] = arr[j];
					j--;
				}
				if(j+1<i) {
					arr[j+1] = temp;
				}
			}
		}
	}
	
	
	public static void bubbleSort(int[] arr) {
		if(arr != null && arr.length>1) {
			bubbleSortAsc(arr);
		}
	}
	
	public static void bubbleSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				bubbleSortAsc(arr);
			}else {
				bubbleSortDesc(arr);
			}
		}
	}
	
	public static void bubbleSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			boolean swapTag = false;
			for(int i=0; i<arrLen-1; i++) {
				swapTag = false;
				for(int j=0; j<arrLen-1-i; j++) {
					if(arr[j]>arr[j+1]) {
						swap(arr,j,j+1);
						swapTag = true;
					}
				}
				if(!swapTag)
					break;
			}
		}
	}
	
	public static void bubbleSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			boolean swapTag = false;
			for(int i=0; i<arrLen-1; i++) {
				swapTag = false;
				for(int j=0; j<arrLen-1-i; j++) {
					if(arr[j]<arr[j+1]) {
						swap(arr,j,j+1);
						swapTag = true;
					}
				}
				if(!swapTag)
					break;
			}
		}
	}
	
	
	public static void quickSort(int[] arr) {
		if(arr != null && arr.length>1) {
			bubbleSortAsc(arr);
		}
	}
	
	public static void quickSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				quickSortAsc(arr);
			}else {
				quickSortDesc(arr);
			}
		}
	}
	
	private static void quickSortAscPartition(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[low];
			int i = low;
			int j = high;
			while(i<j) {
				while(i<j && arr[j]>=pivot) {
					j--;
				}
				while(i<j && arr[i]<=pivot) {
					i++;
				}
				if(i<j) {
					swap(arr, i ,j);
				}
				
			}
			arr[low]=arr[i];
			arr[i] = pivot;
			quickSortAscPartition(arr, low, i-1);
			quickSortAscPartition(arr, i+1, high);
		}
	}
	
	private static void quickSortAscPartition1(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[low];
			int i = low;
			int j = high;
			while(i<j) {
				while(i<j && arr[j]>=pivot) {
					j--;
				}
				if(i<j){
					arr[i] = arr[j];
					i++;
				}
				while(i<j && arr[i]<=pivot) {
					i++;
				}
				if(i<j) {
					arr[j] = arr[i];
					j--;
				}
				
			}
			arr[i] = pivot;
			quickSortAscPartition1(arr, low, i-1);
			quickSortAscPartition1(arr, i+1, high);
		}
	}
	
	private static void quickSortAscPartition2(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[high];
			int i = low-1;
			int j = low;
			while(j<high) {
				if(arr[j]<=pivot) {
					if(++i<j) {
						swap(arr, i, j);
					}
				}
				j++;
			}
			if(i+1<high) {
				swap(arr, i+1, high);
			}
			quickSortAscPartition2(arr, low, i);
			quickSortAscPartition2(arr, i+2, high);
		}
	}
	
	private static void quickSortDescPartition(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[low];
			int i = low;
			int j = high;
			while(i<j) {
				while(i<j && arr[j]<=pivot) {
					j--;
				}
				while(i<j && arr[i]>=pivot) {
					i++;
				}
				if(i<j) {
					swap(arr, i ,j);
				}
				
			}
			arr[low]=arr[i];
			arr[i] = pivot;
			quickSortDescPartition(arr, low, i-1);
			quickSortDescPartition(arr, i+1, high);
		}
	}
	
	private static void quickSortDescPartition1(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[low];
			int i = low;
			int j = high;
			while(i<j) {
				while(i<j && arr[j]<=pivot) {
					j--;
				}
				if(i<j){
					arr[i] = arr[j];
					i++;
				}
				while(i<j && arr[i]>=pivot) {
					i++;
				}
				if(i<j) {
					arr[j] = arr[i];
					j--;
				}
				
			}
			arr[i] = pivot;
			quickSortDescPartition1(arr, low, i-1);
			quickSortDescPartition1(arr, i+1, high);
		}
	}
	
	private static void quickSortDescPartition2(int[] arr, int low, int high) {
		if(low<high) {
			int pivot = arr[high];
			int i = low-1;
			int j = low;
			while(j<high) {
				if(arr[j]>=pivot) {
					if(++i<j) {
						swap(arr, i, j);
					}
				}
				j++;
			}
			if(i+1<high) {
				swap(arr, i+1, high);
			}
			quickSortDescPartition2(arr, low, i);
			quickSortDescPartition2(arr, i+2, high);
		}
	}
	
	public static void quickSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			quickSortAscPartition2(arr, 0, arrLen-1);
		}
	}
	
	public static void quickSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			quickSortDescPartition2(arr, 0, arrLen-1);
		}
	}	
	
	
	public static void mergeSort(int[] arr) {
		if(arr != null && arr.length>1) {
			mergeSortAsc(arr);
		}
	}
	
	public static void mergeSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				mergeSortAsc(arr);
			}else {
				mergeSortDesc(arr);
			}
		}
	}
	
	public static void mergeSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int[] tempArr = new int[arrLen];
			mergeSortAscUnit(arr, tempArr, 0, arrLen-1);
		}
	}
	
	public static void mergeSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int[] tempArr = new int[arrLen];
			mergeSortDescUnit(arr, tempArr, 0, arrLen-1);
		}
	}
	
	private static void mergeSortAscUnit(int[] arr, int[] tempArr, int startIndex, int endIndex) {
		if(startIndex<endIndex) {
			int index_split = (startIndex + endIndex)/2;
			mergeSortAscUnit(arr, tempArr, startIndex, index_split);
			mergeSortAscUnit(arr, tempArr, index_split+1, endIndex);
			mergeAsc(arr, tempArr, startIndex, index_split, index_split+1, endIndex);
		}
	}
	
	private static void mergeAsc(int[] arr, int[] tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2) {
		if(arr[endIndex1]>arr[startIndex2]) {
			int lIndex = startIndex1;
			int rIndex = startIndex2;
			int tempIndex;
			if(arr[startIndex1]>=arr[endIndex2]) {
				while(rIndex<=endIndex2) {
					tempArr[lIndex++]=arr[rIndex++];
				}
				tempIndex=lIndex;
				lIndex=startIndex1;
				while(lIndex<=endIndex1) {
					tempArr[tempIndex++]=arr[lIndex++];
				}
			}else {
				tempIndex=startIndex1;
				while(lIndex<=endIndex1 && rIndex<=endIndex2) {
					if(arr[lIndex]<=arr[rIndex]) {
						tempArr[tempIndex++]=arr[lIndex++];
					}else {
						tempArr[tempIndex++]=arr[rIndex++];
					}
				}
				while(lIndex<=endIndex1) {
					tempArr[tempIndex++]=arr[lIndex++];
				}
				while(rIndex<=endIndex2) {
					tempArr[tempIndex++]=arr[rIndex++];
				}
			}
			tempIndex=startIndex1;
			while(tempIndex<=endIndex1) {
				arr[tempIndex]=tempArr[tempIndex];
				tempIndex++;
			}
			tempIndex=startIndex2;
			while(tempIndex<=endIndex2) {
				arr[tempIndex]=tempArr[tempIndex];
				tempIndex++;
			}
		}
	}
	
	private static void mergeSortDescUnit(int[] arr, int[] tempArr, int startIndex, int endIndex) {
		if(startIndex<endIndex) {
			int index_split = (startIndex + endIndex)/2;
			mergeSortDescUnit(arr, tempArr, startIndex, index_split);
			mergeSortDescUnit(arr, tempArr, index_split+1, endIndex);
			mergeDesc(arr, tempArr, startIndex, index_split, index_split+1, endIndex);
		}
	}
	
	private static void mergeDesc(int[] arr, int[] tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2) {
		if(arr[endIndex1]<arr[startIndex2]) {
			int lIndex = startIndex1;
			int rIndex = startIndex2;
			int tempIndex;
			if(arr[startIndex1]<=arr[endIndex2]) {
				while(rIndex<=endIndex2) {
					tempArr[lIndex++]=arr[rIndex++];
				}
				tempIndex=lIndex;
				lIndex=startIndex1;
				while(lIndex<=endIndex1) {
					tempArr[tempIndex++]=arr[lIndex++];
				}
			}else {
				tempIndex=startIndex1;
				while(lIndex<=endIndex1 && rIndex<=endIndex2) {
					if(arr[lIndex]>=arr[rIndex]) {
						tempArr[tempIndex++]=arr[lIndex++];
					}else {
						tempArr[tempIndex++]=arr[rIndex++];
					}
				}
				while(lIndex<=endIndex1) {
					tempArr[tempIndex++]=arr[lIndex++];
				}
				while(rIndex<=endIndex2) {
					tempArr[tempIndex++]=arr[rIndex++];
				}
			}
			tempIndex=startIndex1;
			while(tempIndex<=endIndex1) {
				arr[tempIndex]=tempArr[tempIndex];
				tempIndex++;
			}
			tempIndex=startIndex2;
			while(tempIndex<=endIndex2) {
				arr[tempIndex]=tempArr[tempIndex];
				tempIndex++;
			}
		}
	}
	
	
	public static void heapSort(int[] arr) {
		if(arr != null && arr.length>1) {
			heapSortAsc(arr);
		}
	}
	
	public static void heapSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				heapSortAsc(arr);
//				heapSortAsc1(arr);
			}else {
				heapSortDesc(arr);
//				heapSortDesc1(arr);
			}
		}
	}
	
	public static void heapSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int index_last_fathernode = arrLen/2-1;
			for(int i=index_last_fathernode;i>=0;i--) {
				adjustHeapMax(arr, i, arrLen);
			}
			
			for(int i=arrLen-1;i>0;i--) {
				swap(arr, 0, i);
				adjustHeapMax(arr, 0, i);
			}
		}
	}
	
	public static void heapSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int index_last_fathernode = arrLen/2-1;
			for(int i=index_last_fathernode;i>=0;i--) {
				adjustHeapMin(arr, i, arrLen);
			}
			
			for(int i=arrLen-1;i>0;i--) {
				swap(arr, 0, i);
				adjustHeapMin(arr, 0, i);
			}
		}
	}
	
	private static void adjustHeapMax(int[] arr, int index, int len) {
		int temp=arr[index];
		int index_left_childnode = 2*index+1;
		int index_max;
		while(index_left_childnode<len) {
			index_max=index_left_childnode;
			if((index_left_childnode+1)<len && arr[index_left_childnode]<arr[index_left_childnode+1]) {
				index_max=index_left_childnode+1;
			}
			if(arr[index_max]>temp) {
				arr[index]=arr[index_max];
				index=index_max;
				index_left_childnode = 2*index+1;
			}else
				break;
		}
		arr[index]=temp;
	}
	
	private static void adjustHeapMin(int[] arr, int index, int len) {
		int temp=arr[index];
		int index_left_childnode = 2*index+1;
		int index_min;
		while(index_left_childnode<len) {
			index_min=index_left_childnode;
			if((index_left_childnode+1)<len && arr[index_left_childnode]>arr[index_left_childnode+1]) {
				index_min=index_left_childnode+1;
			}
			if(arr[index_min]<temp) {
				arr[index]=arr[index_min];
				index=index_min;
				index_left_childnode = 2*index+1;
			}else
				break;
		}
		arr[index]=temp;
	}
	
	public static void heapSortAsc1(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			heapInsertMax1(arr, arrLen);
			
			for(int i=arrLen-1;i>0;i--) {
				swap(arr, 0, i);
				heapInsertMax1(arr, i);
			}
		}
	}
	
	public static void heapSortDesc1(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			heapInsertMin1(arr, arrLen);
			
			for(int i=arrLen-1;i>0;i--) {
				swap(arr, 0, i);
				heapInsertMin1(arr, i);
			}
		}
	}
	
	private static void heapInsertMax(int[] arr, int len) {
		int index_current, index_fathernode;
		for(int i=1;i<len;i++) {
			index_current = i;
			index_fathernode=(index_current-1)/2;
			while(index_fathernode>=0 && arr[index_current]>arr[index_fathernode]) {
				swap(arr, index_current, index_fathernode);
				index_current = index_fathernode;
				if(index_current==0)
					break;
				index_fathernode=(index_current-1)/2;
			}
		}
	}
	
	private static void heapInsertMin(int[] arr, int len) {
		int index_current, index_fathernode;
		for(int i=1;i<len;i++) {
			index_current = i;
			index_fathernode=(index_current-1)/2;
			while(index_fathernode>=0 && arr[index_current]<arr[index_fathernode]) {
				swap(arr, index_current, index_fathernode);
				index_current = index_fathernode;
				if(index_current==0)
					break;
				index_fathernode=(index_current-1)/2;
			}
		}
	}
	
	private static void heapInsertMax1(int[] arr, int len) {
		int index_current, index_fathernode,temp;
		for(int i=1;i<len;i++) {
			index_current = i;
			index_fathernode=(index_current-1)/2;
			temp=arr[index_current];
			while(index_fathernode>=0 && temp>arr[index_fathernode]) {
				arr[index_current]=arr[index_fathernode];
				index_current = index_fathernode;
				if(index_current==0)
					break;
				index_fathernode=(index_current-1)/2;
			}
			arr[index_current]=temp;
		}
	}
	
	private static void heapInsertMin1(int[] arr, int len) {
		int index_current, index_fathernode,temp;
		for(int i=1;i<len;i++) {
			index_current = i;
			index_fathernode=(index_current-1)/2;
			temp=arr[index_current];
			while(index_fathernode>=0 && temp<arr[index_fathernode]) {
				arr[index_current]=arr[index_fathernode];
				index_current = index_fathernode;
				if(index_current==0)
					break;
				index_fathernode=(index_current-1)/2;
			}
			arr[index_current]=temp;
		}
	}
	
	
 	public static void countSort(int[] arr) {
		if(arr != null && arr.length>1) {
			countSortAsc(arr);
		}
	}
	
	public static void countSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				countSortAsc(arr);
			}else {
				countSortDesc(arr);
			}
		}
	}
	
	public static void countSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int min,max;
			List<Integer> boxedArray = Arrays.stream(arr).boxed().collect(Collectors.toList());
			max = Collections.max(boxedArray);
			min = Collections.min(boxedArray);
			int countArrLen = max-min+1;
			int[] resultArr = new int[arrLen];
			int[] countArr = new int[countArrLen];
			for(int i=0;i<arrLen;i++) {
				countArr[arr[i]-min]++;
			}
			for(int i=1;i<countArrLen;i++) {
				countArr[i] += countArr[i-1];
			}
			
			int countArrIndex=-1;
			for(int i=arrLen-1;i>=0;i--) {
				countArrIndex=arr[i]-min;
				resultArr[countArr[countArrIndex]-1] = arr[i];
				countArr[countArrIndex]--;
			}
			
			for(int i=0;i<arrLen;i++) {
				arr[i] = resultArr[i];
			}
		}
	}
	
	public static void countSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int min,max;
			List<Integer> boxedArray = Arrays.stream(arr).boxed().collect(Collectors.toList());
			max = Collections.max(boxedArray);
			min = Collections.min(boxedArray);
			int countArrLen = max-min+1;
			int[] resultArr = new int[arrLen];
			int[] countArr = new int[countArrLen];
			for(int i=0;i<arrLen;i++) {
				countArr[arr[i]-min]++;
			}
			for(int i=countArrLen-2;i>=0;i--) {
				countArr[i] += countArr[i+1];
			}
			
			int countArrIndex=-1;
			for(int i=arrLen-1;i>=0;i--) {
				countArrIndex=arr[i]-min;
				resultArr[countArr[countArrIndex]-1] = arr[i];
				countArr[countArrIndex]--;
			}
			
			for(int i=0;i<arrLen;i++) {
				arr[i] = resultArr[i];
			}
		}
	}
	
	
	public static void shellSort(int[] arr) {
		if(arr != null && arr.length>1) {
			shellSortAsc(arr);
		}
	}
	
	public static void shellSort(int[] arr, int order) {
		if(arr != null && arr.length>1) {
			if(order == 0) {
				shellSortAsc(arr);
			}else {
				shellSortDesc(arr);
			}
		}
	}
	
	public static void shellSortAsc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int gap = arrLen/2;
			while(gap>0) {
				for(int i=gap; i<arrLen; i++) {
					int temp = arr[i];
					int j = i - gap;
					while(j>=0 && arr[j]>temp) {
						arr[j+gap] = arr[j];
						j -= gap;
					}
					if(j+gap<i) {
						arr[j+gap] = temp;
					}
				}
				gap /=2;
			}
		}
	}
	
	public static void shellSortDesc(int[] arr) {
		if(arr != null && arr.length>1) {
			int arrLen = arr.length;
			int gap = arrLen/2;
			while(gap>0) {
				for(int i=gap; i<arrLen; i++) {
					int temp = arr[i];
					int j = i - gap;
					while(j>=0 && arr[j]<temp) {
						arr[j+gap] = arr[j];
						j -= gap;
					}
					if(j+gap<i) {
						arr[j+gap] = temp;
					}
				}
				gap /=2;
			}
		}
	}
	
	
	private static void swap(int[] arr, int iIndex, int jIndex) {
		int temp = arr[iIndex];
		arr[iIndex] = arr[jIndex];
		arr[jIndex] = temp;
	}
}
