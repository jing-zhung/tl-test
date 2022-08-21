# Question 2

## Usage

* Enter a math operation in terminal with only numbers and the following operators: + - * / ( )

## Output

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
