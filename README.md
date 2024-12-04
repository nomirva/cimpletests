# cimpletests - Simple testing library for C
At the moment this library is developed mainly for personal use

---
#### Demonstration

The library is made in the style of one header file, so you just need to copy it to your project:
```c
#include "cimpletests.h"
```

Testing functions:
```c
int Add(int a, int b) {
    return a + b;
}

int Divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;

}

int Multiply(int a, int b) {
    return a * b;
}
```

Test functions:
```c
char* TestAdd() {
    if (Add(2, 2) != 4) {
        return "Expected 2 + 2 to equal 4";
    }
    if (Add(2, -2) != 0) {
        return "Expected 2 + (-2) to equal 0";
    }
    return NULL;
}

char* TestMultiply() {
    if (Multiply(2, 3) != 6) {
        return "Expected 2 * 3 to equal 6";
    }
    if (Multiply(-1, 5) != -6) { // Failed: expected -5, but checking against -6
        return "Expected -1 * 5 to equal -5";
    }
    return NULL;
}


char* TestDivide() {
    if (Divide(6, 2) != 3) {
        return "Expected 6 / 2 to equal 3";
    }
    if (Divide(5, 0) != 1) { // Failed: expected 0, but checking against 1
        return "Expected 5 / 0 to handle division by zero";
    }
    return NULL;
}
```

Run tests:
```c
int main(void) {
    Test(TestAdd);
    Test(TestMultiply);
    Test(TestDivide);
    TestResults();
    return 0;
}
```

Output:
![output example](output.png)
