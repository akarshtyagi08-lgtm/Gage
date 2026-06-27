# Gage Programming Language v3.4.0 Master Manual
The official, complete reference for Gage.

## 1. Syntax Overview
* `let x = 10` : Mutable variable.
* `const Y = 5` : Immutable constant.
* `|| Comment` : Comments.
* `&&`, `||` : Logical operators.

## 2. Standard Modules
Import with `import [name]`:
* `math`: `sqrt`, `abs`, `max`, `min`
* `random`: `randint(min, max)`, `rand_float()`
* `time`: `timestamp()`
* `io`: `print`, `render`

## 3. System & Graphics
* `exec("cmd")`, `clear()`, `sleep(s)`
* `cursor(x,y)`, `color(c)`, `delay(ms)`, `hide_cursor()`
