Final Project: Test outputs
===========================
Course:   CS 5008 
Student:  Marcela Perro

## Radix Sort python implementation 
1. Testing program compiles 

2. Executing with different array sizes 
n = 10 
Array Size: 1, Time Taken: 0.000082 seconds, Memory Used: 688 bytes
Array Size: 2, Time Taken: 0.000014 seconds, Memory Used: 712 bytes
Array Size: 3, Time Taken: 0.000015 seconds, Memory Used: 736 bytes
Array Size: 4, Time Taken: 0.000010 seconds, Memory Used: 760 bytes
Array Size: 5, Time Taken: 0.000010 seconds, Memory Used: 816 bytes
Array Size: 6, Time Taken: 0.000015 seconds, Memory Used: 840 bytes
Array Size: 7, Time Taken: 0.000018 seconds, Memory Used: 864 bytes
Array Size: 8, Time Taken: 0.000021 seconds, Memory Used: 888 bytes
Array Size: 9, Time Taken: 0.000021 seconds, Memory Used: 976 bytes
Array Size: 10, Time Taken: 0.000025 seconds, Memory Used: 1000 bytes

n = 5 
Array Size: 1, Time Taken: 0.000043 seconds, Memory Used: 688 bytes
Array Size: 2, Time Taken: 0.000041 seconds, Memory Used: 712 bytes
Array Size: 3, Time Taken: 0.000042 seconds, Memory Used: 736 bytes
Array Size: 4, Time Taken: 0.000043 seconds, Memory Used: 760 bytes
Array Size: 5, Time Taken: 0.000046 seconds, Memory Used: 816 bytes
3. Testing program outputs csv file 
python3 radix_sort.py 10 output.csv
file outputs correctly 
Array Size,Time Taken (seconds),Memory Used (bytes)
1,0.000144,688
2,0.000054,712
3,0.000060,736
4,0.000064,760
5,0.000066,816
6,0.000067,840
7,0.000186,864
8,0.000106,888
9,0.000072,976
10,0.000067,1000


## Radix Sort C implementation 
1. Testing program compiles 

2. Executing with different array sizes 
Array Size: 1, Time Taken: 0.000002 seconds, Memory Used: 4 bytes
Array Size: 2, Time Taken: 0.000001 seconds, Memory Used: 8 bytes
Array Size: 3, Time Taken: 0.000001 seconds, Memory Used: 12 bytes
Array Size: 4, Time Taken: 0.000001 seconds, Memory Used: 16 bytes
Array Size: 5, Time Taken: 0.000001 seconds, Memory Used: 20 bytes

3. Testing program outputs csv file 
Array Size,Time Taken (seconds),Memory Used (bytes)
1,0.000002,4
2,0.000001,8
3,0.000001,12
4,0.000001,16
5,0.000001,20

## Radix Sort Strings 
1. Testing program compiles 
3. Executing with different arr[] string inputs 
Original array:
word
category
apple
quest
balloon
race
dog

Sorted array:
dog
race
word
apple
quest
balloon
category

## Radix Sort step by step implementation
1. Testing program compiles 
2. Executing with different array sizes 
Original array:
362 80 41 728 487 342 257 701 166 547
After sorting on digit 1 place:
80 41 701 362 342 166 487 257 547 728
After sorting on digit 10 place:
701 728 41 342 547 257 362 166 80 487
After sorting on digit 100 place:
41 80 166 257 342 362 487 547 701 728
Time taken for Radix Sort: 0.000016 seconds