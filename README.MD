# Sorting Algorithm Examples

### Bogosort

Input: n size array

output: array ordered and time in milliseconds

> Executing task:  'Remove-Item * -Include *.exe' ; g++ -g -std=c++11 main.cpp -o main.exe ; .\main.exe <

Remove-Item * -Include *.exe
21 26 25 16 14

26 21 25 16 14

26 21 14 16 25

26 21 14 25 16

14 21 26 25 16

14 21 16 25 26

14 21 16 25 26

14 21 16 26 25

14 21 26 16 25

14 26 21 16 25

14 16 21 26 25

25 16 21 26 14

25 16 21 26 14

25 16 26 21 14

26 16 25 21 14

14 16 25 21 26

14 16 21 25 26

*Array ordered: 14 16 21 25 26 Time taken by function: **57 milliseconds***
