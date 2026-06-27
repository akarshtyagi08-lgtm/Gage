## Welcome to the official, comprehensive documentation for the Gage Programming Language v3.1.0.
Gage is an ahead-of-time (AOT) compiled, high-performance language engineered for high execution speeds and clean syntax layout[span_0](start_span)[span_0](end_span)[span_1](start_span)[span_1](end_span). 

By translating source code structures into highly optimized backend C code and running them through the Clang optimization pipeline (`-O3`), Gage executes programs directly as native machine binaries[span_2](start_span)[span_2](end_span)[span_3](start_span)[span_3](end_span).

---

## 1. Architectural Principles & Summary
* **Blazing Fast Performance:** No virtual machines, no interpreters[span_4](start_span)[span_4](end_span). 
* **Syntax Simplicity:** Clean layout structure without trailing semicolons[span_5](start_span)[span_5](end_span)[span_6](start_span)[span_6](end_span).
* **Strict Structural Rules:** Predictable behavior enforced directly by the AOT compiler engine[span_7](start_span)[span_7](end_span).

---

## 2. Command Line Interface (CLI)
To compile and run[span_8](start_span)[span_8](end_span):
`gage main.gg`

To check version[span_9](start_span)[span_9](end_span):
`gage -v`

---

## 3. Comments[span_10](start_span)[span_10](end_span)
### Single-Line Comments[span_11](start_span)[span_11](end_span)
Wrap text inside double pipes to comment out code on a single line[span_12](start_span)[span_12](end_span):
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

## 4. Native Data Types[span_13](start_span)[span_13](end_span)
* **Integer:** 42, -7[span_14](start_span)[span_14](end_span)
* **Float:** 19.99, -0.542[span_15](start_span)[span_15](end_span)
* **Boolean:** true, false[span_16](start_span)[span_16](end_span)
* **String:** "System Initialized\n[span_17](start_span)"[span_17](end_span)

---

## 5. Variables[span_18](start_span)[span_18](end_span)
`let high_score = 5000`[span_19](start_span)[span_19](end_span)
`high_score = 6000`[span_20](start_span)[span_20](end_span)

---

## 6. Operators[span_21](start_span)[span_21](end_span)
* **Math:** `+`, `-`, `*`, `/`, `%`[span_22](start_span)[span_22](end_span)
* **Shorthand:** `+=`, `-=`, `*=`, `/=`[span_23](start_span)[span_23](end_span)
* **Comparisons:** `==`, `!=`, `>`, `<`[span_24](start_span)[span_24](end_span)
* **Logic:** `and` (`&&`), `or`, `!`[span_25](start_span)[span_25](end_span)

---

## 7. Advanced Control Flow (v2.1.0+)[span_26](start_span)[span_26](end_span)
### If, Elif, Else[span_27](start_span)[span_27](end_span)[span_28](start_span)[span_28](end_span)
```text
if (score > 90) {
    print "A"
} elif (score > 80) {
    print "B"
} else {
    print "C"
}
```

### Switch / Case[span_29](start_span)[span_29](end_span)
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

## 8. Loops & Iteration (v2.1.0+)[span_30](start_span)[span_30](end_span)
### While Loops[span_31](start_span)[span_31](end_span)
```text
let i = 0
while (i < 5) {
    i += 1
}
```

### For Loops[span_32](start_span)[span_32](end_span)
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

## 9. Custom Functions (v3.0.0+)[span_33](start_span)[span_33](end_span)
Isolate logic using the `fn` keyword[span_34](start_span)[span_34](end_span). Gage supports parameters, local scoping, explicit `return` statements, and recursion[span_35](start_span)[span_35](end_span).

### Function Definition & Calling[span_36](start_span)[span_36](end_span)
```text
fn calculate_score(points, multiplier) {
    let final = points * multiplier
    return final
}

let result = calculate_score(10, 5)
print result
```

### Recursion Example[span_37](start_span)[span_37](end_span)
```text
fn fibonacci(n) {
    if (n < 2) {
        return n
    }
    return fibonacci(n - 1) + fibonacci(n - 2)
}
```

---

## 10. Console I/O[span_38](start_span)[span_38](end_span)
* **Print:** `print "Hello"` or `print (10 + 5)`[span_39](start_span)[span_39](end_span)
* **Input:** `let token = input`[span_40](start_span)[span_40](end_span)

---

## 11. Final Summary
* **Gage is an AOT compiled language,** meaning it translates straight to native machine code via a C backend[span_41](start_span)[span_41](end_span)[span_42](start_span)[span_42](end_span).
* **It runs at pure hardware speed,** completely bypassing slow interpreters and virtual machines[span_43](start_span)[span_43](end_span).
* **It features a brutally clean syntax** that completely removes the need for trailing semicolons[span_44](start_span)[span_44](end_span)[span_45](start_span)[span_45](end_span).
* **It is fully loaded** with floats, booleans, single & multiline comments, loops, switch-cases, and recursive functions[span_46](start_span)[span_46](end_span)[span_47](start_span)[span_47](end_span).
