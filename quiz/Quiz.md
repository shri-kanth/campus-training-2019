# Instructions :

Create a new Folder in your GitHub repository named 'Quiz'.Solve Each of the Questions below and commit your solutions to this folder in GitHub. Send an email containing the link to this GitHub folder.

Check your submission against various test cases. Your code will be judged based on the following criteria in that order
* Correctness
* Computational complexity and Space Complexity
* Readability
* Maintainability

# Questions :

### Question  1 : 

Write a c program, which takes a positive integer as a command line argument and prints an English phrase that describes the integer. Use the short scale system to print the string literals. The program should handle any incorrect usage by printing a message indicating the correct usage and exiting with appropriate exit code. Your program should be able to handle input range from zero to one trillion.
Example : 
Input : `1234560`, 
OutPut :  `One million two hundred and thirty four thousand five hundred and sixty`.
---
### Question  2 : 

Write a c function, which takes two integer arrays as arguments. From these two arrays find a pair of values (one from each array) that you can swap to give the two arrays the same sum. Print these two values separated by a comma to output on a new line. If no such pair exists print "Not Possible". (You could have more than one valid pair for given input, in such cases printing any one valid pair is acceptable)
Example : 
Input : `{4,1,2,1,1,2}` and `{3,6,3,3}`  
OutPut :  `{1,3}`
---
### Question  3 : 

A 'majority element' is an element that makes up half or more than half of the items in an array. Write a C function which takes a positive integer array as argument and returns the majority element.If there is no majority element return -1. Do this in O(N) time complexity and O(1) space complexity.
Example : 
Input : `{1,2,5,9,5,9,5,5,5}`  
OutPut :  `5`
---
### Question  4 :

Reusing the "dictionary.h", "dictornary.c" and "dictionaries/large" files from Week-5 DataStructures Exercise problem Implement a c function that takes two char arrays representing two words as arguments. The first word is the "source" and the second word is the "target". Your job is to transform the "source" to "target". You could transform one word into another word by changing one letter at a time. You are allowed to add a letter to existing word, remove a letter from existing word or replace a letter from existing word. The new word you get at each step must be in the dictionary. If it is possible to transform 'source' into 'target', print the list of words at each step as shown in example. Print "Not Possible" if it is not possible to reach "target" word from "source" with a given dictionary".
Example : 
Input : `DAMP`, `LIKE` 
output : `DAMP -> LAMP -> LIMP -> LIME -> LIKE`
---
### Question 5 :
 
You are given two arrays, one shorter (with all distinct elements) and one longer array (where elements may or may not be unique). Find the shortest sub-array in the long array that contains all the elements in the shorter array. The order of elements is not important, the Sub-array can contain all the elements of shorter array in any order. Write a C function that takes the two arrays as arguments. And prints the start and end indices of the longer array that represent the required sub-array. Print "Not Possible" if there is no sub-array in the entire long array which contains all the elements present in shorter array.
Example : 
Input `{1, 5, 9}` | `{7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7}` 
Out put : `[7, 10]`
Explanation : Here 
shorter array : `{1, 5, 9}`
longer array : `{7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7}` 
sub-array : `{5,7,9,1}` ( i.e  `{7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7}`  )
[note : all the elements of shorter array `(1, 5, 9)` are present in the sub-array]
Index of long array that is start of sub-array : 7, index of long array that is end of sub-array : 10 ====> output : `[7, 10]`
--- 

***Note : Make suitable assumptions where ever you think necessary. But document those assumptions as comments.***
