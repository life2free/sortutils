# Sorting Methods

Eight sorting methods: Selection sort, Insertion sort, Bubble sort, Merge sort, Heap sort, Quick sort, Shell sort, Counting sort. Utilized Java, Python and C to implment.

## C

There are two test files in `test` folder. Navigate to folder `c/test`, run below commands to check:

```
gcc testsort.c ../src/utils/*.c -o testsort.out
./testsort.out
```

or

```
gcc testsort1.c ../src/utils/*.c -o testsort1.out
./testsort1.out
```

In file `testsort.c`, can test different sorting method by passing different third parameter to `sortArray(arr, len,"sort function name");`, e.g `sortArray(arr, len,"selectionSort");`

## Java

Use java 1.8. There are two test classes in `test` folder. `SortJunit.java` is used for Junit Test.
Navigate to folder `java`, run below commands to check:

```
javac test/TestSort.java
java test.TestSort

```

## Python

Use Python3. There are two test files. `sort_unittest.py` is used for Unit Test. Navigate to folder `python`, run below commands to check:

```
python3 sort_unittest.py

```

or

```
python3 testsort.py
```

## Contribute

- Source code: https://github.com/life2free/sortutils
- Issue Tracker: https://github.com/life2free/sortutils/issues
