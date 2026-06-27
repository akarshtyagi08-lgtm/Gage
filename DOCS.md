## Welcome to the official, comprehensive documentation for the Gage Programming Language v3.1.0.
Gage is an ahead-of-time (AOT) compiled, high-performance language engineered for high execution speeds and clean syntax layout. 

By translating source code structures into highly optimized backend C code and running them through the Clang optimization pipeline (`-O3`), Gage executes programs directly as native machine binaries.

---

## 1. Architectural Principles & Summary
* **Blazing Fast Performance:** No virtual machines, no interpreters. 
* **Syntax Simplicity:** Clean layout structure without trailing semicolons.
* **Strict Structural Rules:** Predictable behavior enforced directly by the AOT compiler engine.

---

## 2. Command Line Interface (CLI)
To compile and run:
`gage main.gg`

To check version:
`gage -v`

---

## 3. Comments
### Single-Line Comments
Wrap text inside double pipes to comment out code on a single line:
`|| This is a single-line comment ||`

### Multiline Comments (v3.1.0+)
Wrap text inside triple pipes to create comments that cross multiple code lines seamlessly:
```text
||| 
This is a multiline comment block.
The Gage engine will ignore all of this!
|||
```

---

## 4. Native Data Types
* **Integer:** 42, -7
* **Float:** 19.99, -0.542
* **Boolean:** true, false
* **String:** "System Initialized\n"

---

## 5. Variables
`let high_score = 5000`
`high_score = 6000`

---

## 6. Operators
* **Math:** `+`, `-`, `*`, `/`, `%`
* **Shorthand:** `+=`, `-=`, `*=`, `/=`
* **Comparisons:** `==`, `!=`, `>`, `<`
* **Logic:** `and` (`&&`), `or`, `!`

---

## 7. Advanced Control Flow (v2.1.0+)
### If, Elif, Else
```text
if (score > 90) {
    print "A"
} elif (score > 80) {
    print "B"
} else {
    print "C"
}
```

### Switch / Case
```text
switch (state) {
    case 1 {
        print "Online"
    }
    default {
        print "Offline"
    }
}
```

---

## 8. Loops & Iteration (v2.1.0+)
### While Loops
```text
let i = 0
while (i < 5) {
    i += 1
}
```

### For Loops
```text
for (let i = 0, i < 10, i += 1) {
    if (i == 5) {
        continue
    }
    if (i == 8) {
        break
    }
    print i
}
```

---

## 9. Custom Functions (v3.0.0+)
Isolate logic using the `fn` keyword. Gage supports parameters, local scoping, explicit `return` statements, and recursion.

### Function Definition & Calling
```text
fn calculate_score(points, multiplier) {
    let final = points * multiplier
    return final
}

let result = calculate_score(10, 5)
print result
```

### Recursion Example
```text
fn fibonacci(n) {
    if (n < 2) {
        return n
    }
    return fibonacci(n - 1) + fibonacci(n - 2)
}
```

---

## 10. Console I/O
* **Print:** `print "Hello"` or `print (10 + 5)`
* **Input:** `let token = input`

---

## 11. Final Summary
* **Gage is an AOT compiled language,** meaning it translates straight to native machine code via a C backend.
* **It runs at pure hardware speed,** completely bypassing slow interpreters and virtual machines.
* **It features a brutally clean syntax** that completely removes the need for trailing semicolons.
* **It is fully loaded** with floats, booleans, single & multiline comments, loops, switch-cases, and recursive functions.
