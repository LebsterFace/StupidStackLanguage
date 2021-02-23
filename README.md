# StupidStackLanguage
A stack-based esoteric programming language. See wiki page [here](https://esolangs.org/wiki/StupidStackLanguage)

## Operations
| Character | Operation                                                                                                                   |
|-----------|-----------------------------------------------------------------------------------------------------------------------------|
| a         | Pushes 0 to the top of the stack                                                                                            |
| b         | Pops the 1st item from the stack                                                                                            |
| c         | Subtracts the 2nd item on the stack from the 1st item and pushes the result to the stack                                    |
| d         | Decrements the 1st item of the stack by 1                                                                                   |
| e         | Pushes the 1st item mod the 2nd item onto the stack                                                                         |
| f         | Prints the 1st item on the stack as an ASCII character                                                                      |
| g         | Adds the first 2 stack items together and pushes the result to the stack                                                    |
| h         | Gets input from the user as a number and pushes to the stack                                                                |
| i         | Increments the 1st item of the stack by 1                                                                                   |
| j         | Gets input from the user as a character and pushes that characters ASCII code onto the stack                                |
| k         | Skips the next command if the 1st item on the stack is 0                                                                    |
| l         | Swaps the 1st and 2nd items on the stack                                                                                    |
| m         | Multiplies the first two stack items together and pushes the result onto the stack                                          |
| n         | If the 1st item on the stack is equal to the 2nd item, push a 1 to the stack, else push a 0                                 |
| o         | Pops the (first item on the stack)th item on the stack                                                                      |
| p         | Divides the 1st item on the stack ''by'' the 2nd item and pushes the result onto the stack                                  |
| q         | Duplicates the 1st item on the stack                                                                                        |
| r         | Pushes the total length of the stack onto the stack                                                                         |
| s         | Swaps the 1st and (first item on the stack)th items on the stack                                                            |
| t         | If the 1st item on the stack is 0, jumps to the corresponding 'u' in the program, otherwise does nothing                    |
| u         | If the 1st item on the stack is '''not''' 0, jumps ''back'' to the corresponding 't' in the program, otherwise does nothing |
| v         | Increments the top item on the stack by 5                                                                                   |
| w         | Decrements the top item on the stack by 5                                                                                   |
| x         | Prints the 1st item on the stack                                                                                            |
| y         | Deletes the entire stack                                                                                                    |
| z         | Exits the script                                                                                                            |

## Example Programs

### Hello world
```
avdqvdmavvqmiqiiifvdlfbffiiiflblblfbqviiifbfiiifwdfwwiif
```
 
### Find the factorial of a number
```
hqdtmldubx
```

### Print the Fibonacci Sequence
```
axiqvvdflxlwwltgavvfbxu
```
