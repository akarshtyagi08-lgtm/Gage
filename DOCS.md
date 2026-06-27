Welcome to the official, comprehensive documentation for the Gage Programming Language v2.0.1. Gage is an ahead-of-time (AOT) compiled, high-performance language engineered for high execution speeds and clean syntax layout. 

By translating source code structures into highly optimized backend C code and running them through the Clang optimization pipeline (`-O3`), Gage executes programs directly as native machine binaries.

---

## 1. Architectural Principles & Summary

Gage is designed around three primary pillars:
* **Blazing Fast Performance:** No virtual machines, no interpreters. Loops and math equations run at raw hardware speeds.
* **Syntax Simplicity:** Clean layout structure that maximizes development speed without formatting clutter.
* **Strict Structural Rules:** Predictable behavior enforced directly by the AOT compiler engine.

### Strict Syntax Constraints Checklist
1. **File Format:** The compiler strictly requires source code files to utilize the `.gg` file extension.
2. **No Semicolons:** Do not append trailing semicolons `;` to your lines. Statement separation relies cleanly on standard line breaks.
3. **Case Sensitivity:** Identifiers are entirely case-sensitive. Variables named `counter`, `Counter`, and `COUNTER` point to completely distinct memory definitions.

---

## 2. Command Line Interface (CLI)

Interact with the Gage compiler toolchain using the global `gage` terminal execution utility.

### Running Source Scripts
To compile a source code file through the backend optimization script and trigger immediate native execution, supply the target filename:
```text
gage main.gg

```
### Checking Compiler Metadata
To verify system paths, build variations, and view engine build records without targeting a script file, call the version flag:
```text
gage -v
gage --version

```
## 3. Inline and Block Comments
To leave developmental notes, structural documentation, or completely isolate lines of code from parsing passes, wrap the target text segment inside double pipes.
### Syntax Example
```text
|| This is a comment. The compiler engine will completely ignore this text ||

let x = 10 || Comments can also be appended to the end of a live code line ||

```
## 4. Native Data Types
Gage tracks, instantiates, and manipulates four primary structural data types.
| Data Type | Description | Literal Formatting Example |
|---|---|---|
| **Integer** | Whole positive or negative numerical values | 42, -7 |
| **Float** | Decimal values tracking high precision measurements | 19.99, -0.542 |
| **Boolean** | Truth evaluation status toggles | true, false |
| **String** | Textual streams bounded inside literal quote markers | "System Initialized\n" |
## 5. Variable Declarations & Reassignment
Memory allocation is managed via the static initialization keyword let. Gage dynamically maps the proper operational width inside your machine registers based on the underlying data assignment.
### Initializing Variables
```text
let high_score = 5000
let account_balance = 1250.45
let is_engine_active = true
let welcome_banner = "Welcome to Gage Engine"

```
### Modifying Variable States
Once a variable is registered into memory, update its value by targeting its unique identifier directly without repeating the let keyword:
```text
let operational_limit = 100
operational_limit = 250

```
## 6. Operators Deep Dive
Gage comes pre-equipped with an extensive array of mathematical, assignment, structural comparison, and logical evaluation operators.
### Arithmetic Operators
Execute mathematical assignments directly across numerical registers.
```text
let addition = 10 + 5
let subtraction = 20 - 4
let multiplication = 3 * 3
let division = 100 / 4
let remainder = 14 % 3

```
### Update Assignment Operators (Shorthands)
Modify existing numeric variables in place using high-speed updating expressions.
```text
let speed = 50
speed += 10
speed -= 5
speed *= 2
speed /= 3

```
### Evaluation & Comparison Operators
Validate conditions and structures inside control flow sequences.
```text
let threshold = 75

|| Equality validations ||
let matches = (threshold == 75)
let differs = (threshold != 100)

|| Value boundaries ||
let higher = (threshold > 50)
let lower = (threshold < 100)

```
### Logical Logic Operators
Combine multiple structural evaluation clauses into streamlined conditional logic blocks.
```text
let validation_a = true
let validation_b = false

|| Logic AND check ||
if (validation_a && validation_b) {
    print "Both assertions are true"
}

|| Logic OR check ||
if (validation_a or validation_b) {
    print "At least one assertion is true"
}

|| Logic NOT check ||
if (!validation_b) {
    print "validation_b is verified false"
}

```
## 7. Control Flow & Branching Logic
Direct program execution dynamically using standard conditional fork branches and lightning-fast iteration sequences.
### If-Else Conditional Branches
```text
let internal_temperature = 98.6

if (internal_temperature > 100.0) {
    print "Warning: Temperature limit exceeded!"
} else {
    print "System operating within safe baseline parameters."
}

```
### High-Speed While Loops
Loops pass optimization metrics directly to the hardware level, executing iteration loops with minimal operational overhead.
```text
let iteration_counter = 0

while (iteration_counter < 100000) {
    iteration_counter += 1
}

print "Successfully executed 100,000 native iterations!"

```
## 8. Native Data Arrays
Initialize safe, packed sequential index arrays inside memory allocations using standard square bracket arrays.
### Array Generation Syntax
```text
let lottery_numbers = [4, 8, 15, 16, 23, 42]
let coordinate_grid = [10.5, 20.3, 45.1]

```
## 9. Console I/O (Input / Output)
Communicate cleanly with terminal standard input/output channels using low-latency streaming keywords.
### Writing to the Terminal Console (print)
The print keyword processes textual literal lines, variables, and raw equations effortlessly, parsing escape strings like \n natively.
```text
|| Printing literal strings ||
print "System Status Check:\n"

|| Printing evaluations dynamically ||
let metrics = 88.4
print metrics

|| Printing raw math sequences directly ||
print (500 * 2) + 15

```
### Capturing User Responses (input)
Suspend program execution and open standard console input streams to securely ingest string-based terminal values directly inside active variables.

```text
print "Enter access authorization key numeric index:"
let registration_token = input

print "Captured input index token value successfully."

```
