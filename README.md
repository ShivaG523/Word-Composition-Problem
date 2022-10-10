# Word-Composition-Problem
# Problem Statement 
Write a program that: 
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one 
word per line, no spaces, all lower case) 
2. Identifies & display below given data in logs/console/output file
o longest compounded word 
o second longest compounded word 
o time taken to process the input file 
Note: A compounded word is one that can be constructed by combining (concatenating) shorter words 
also found in the same file
# Example
Input 01 
Input_01.txt is a small word list, consisting following words
cat
cats 
catsdogcats 
catxdogcatsrat 
dog 
dogcatsdog 
hippopotamuses 
rat 
ratcatdogcat 
Answer: 
1. Longest Compound Word: ratcatdogcat 
2. Second Longest Compound Word: catsdogcats 
Note: 
Hippopotamuses is the longest word but that is not the answer as it is not a compounded word 

 # Approach
 There are various method to approach the solution but I used Dynamic programming and Hashing.
 
 Here are the steps I took
 
  # Step 1-
 In the first step, we scan all the strings present in a input file by the getline function, store them in vector one by one and also store the string in a hashmap by  hashing the string value and then store the hashed value to hashmap.
 
 # Step 2-
 In this step we sort the vector by the size of string and if the size of string are are equal then we sort it by lexiographically and then we iterate the vector from end and check if the string is compounded or not, if it contains all the compounded word then we print the largest compounded word.
 
 # Step 3-
 In this step after printing the largest compounded word , we again check for the second largest compounded word in the vector by the help of dynamic programming and hash map we check the value of substrings in map , if  all the compounded words of string present in a map then we print the second largest compounded word.
 
 # Algorithm
 1. Basically the algorithm we used in this is Rabin Karp algorithm for reducing the size of string and convert the string into the hashed value, then stored it into key of hashmap and intialize the value to 1.
 
 2. We also used dynamic programming and recursion to check that if the hashed value of substring of string present in vector is present in a hashmap or not. 
 # Time Complexity
 The Time Complexity of this algorithm is n*(l*l) where n is the number of string present in a input file and the l is the size of longest string present in input. 
 
 
