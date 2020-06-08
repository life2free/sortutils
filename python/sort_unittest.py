import sortutils
import unittest


class TestSort(unittest.TestCase):
    '''

    '''

    def test_insertionSortAsc(self):
        arr = [12, 11, 13, 5, 6]
        sortutils.insertionSort(arr)
        self.assertEqual(arr, [5, 6, 11, 12, 13])

        sortutils.insertionSort(arr, 1)
        self.assertEqual(arr, [13, 12, 11, 6, 5])

    def test_insertionSortDesc(self):
        arr = [12, 11, 13, 5, 6]
        sortutils.insertionSort(arr, 1)
        self.assertEqual(arr, [13, 12, 11, 6, 5])

    def test_quickSort(self):
        arr = [3, 6, 8, 19, 1, 5]
        result = sortutils.quickSort(arr)
        self.assertEqual(result, [1, 3, 5, 6, 8, 19])

    def test_selectionSort(self):
        arr = [3, 6, 8, 19, 1, 0, 22, 98, 5]
        sortutils.selectionSort(arr, 1)
        self.assertEqual(arr, [98, 22, 19, 8, 6, 5, 3, 1, 0])

    def test_bubbleSort(self):
        arr = [3, 6, 8, 19, 1, 0, 22, 98, 5]
        sortutils.bubbleSort(arr, 1)
        self.assertEqual(arr, [98, 22, 19, 8, 6, 5, 3, 1, 0])

if __name__ == '__main__':
    unittest.main()
