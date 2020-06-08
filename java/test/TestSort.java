package test;

import utils.SortUtils;

public class TestSort {
	public static void main(String[] args) {
		int[] array = {1, 61, 8, 19, 3, -5, 7, 50, 0, 22, 100, -1, 19, 0};

		System.out.println("Origin array: ");
		printArray(array);
		System.out.println();
		
		SortUtils.mergeSort(array);
		System.out.println("After sorted by asc: ");
		printArray(array);
		System.out.println();
		SortUtils.mergeSort(array,1);
		System.out.println("After sorted by desc: ");
		printArray(array);
		System.out.println();
	}
	
	
	public static void printArray(int[] arr) {
		if(arr!= null && arr.length>0) {
			for(int i : arr) {
				System.out.print(i+" ");
			}
		}
	}
}
