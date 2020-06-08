package test;

import org.junit.Test;
import utils.SortUtils;

import static org.junit.Assert.assertArrayEquals;

public class SortJunit {
	@Test
	public void testSort() {
        int[] array = {1, 61, 8, 19, 3, -5, 7, 50, 0, 22, 100, -1, 19, 0};
		int[] ascSortedArray = {-5, -1, 0, 0, 1, 3, 7, 8, 19, 19, 22, 50, 61, 100};
        SortUtils.mergeSort(array);
        assertArrayEquals(array,ascSortedArray);
        int[] array1 = {1, 61, 8, 19, 3, -5, 7, 50, 0, 22, 100, -1, 19, 0};
        SortUtils.mergeSort(array1,1);
		int[] descSortedarray = {100, 61, 50, 22, 19, 19, 8, 7, 3, 1, 0, 0, -1, -5};
		assertArrayEquals(array1,descSortedarray);
	}
}