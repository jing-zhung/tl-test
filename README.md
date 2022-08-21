# tl-test

## Build and run

* To build, in 'tl-test' directory run:

```
chmod +x compile.sh
./compile.sh
```

* To run program for question 1:

```
./build/question1
```

* To run program for question 2:

```
./build/question2
```

## Question 1

### Room State Graph

![alt text](src/question1/diagram/Graph.png)

### Usage

* Hotel starts with all rooms available.

* Enter '1' to check in to the nearest room assigned by the program.

* Enter '2' to check out of a room (room name input required).

* Enter '3' to set a vacant room to available (room name input required).

* Enter '4' to set a vacant room for repair (room name input required).

* Enter '5' to set room from repair to vacant (room name input required).

* Program prohibits invalid state changes.

## Question 2

### Usage

* Enter a math operation in terminal with only numbers and the following operators: + - * / ( )

### Output

* Displays binary tree of math operations and returns the answer. Example:

```
String: ((15 / (7 - (1 + 1) ) ) * -3 ) - (2 + (1 + 1))

Tree:
\--(-)
    |--(*)
    |   |--(/)
    |   |   |--(15)
    |   |   \--(-)
    |   |       |--(7)
    |   |       \--(+)
    |   |           |--(1)
    |   |           \--(1)
    |   \--(-)
    |       \--(3)
    \--(+)
        |--(2)
        \--(+)
            |--(1)
            \--(1)

Answer: -13
```

* () represents a node

* |-- represents left branch

* \\-- represents right branch
