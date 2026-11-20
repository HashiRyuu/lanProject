# Hashi language — a small C++ interpreter

A learning project that reads a **line-oriented text file** and executes simple commands for variables, printing, and integer arithmetic. It is implemented in C++ using string streams and maps.

This is a small interpreter prototype, **not a full compiler or general-purpose language**.

## Implemented commands

| Syntax | Behavior |
| --- | --- |
| `int x = 293` | Store an integer under the name `x` |
| `str name = hashi` | Store text under the name `name` |
| `print x` | Print a stored variable |
| `add x y` | Print `x + y` |
| `subtract x y` | Print `x - y` |
| `multiply x y` | Print `x * y` |
| `divide x y` | Print integer division `x / y` |

Commands are whitespace-delimited and process one line at a time. Arithmetic commands currently operate on integer variables, not general expressions.

## Build and run

Requires a C++ compiler with support for at least C++11.

On Linux or macOS:

```sh
g++ -std=c++11 main.cpp -o hashi
./hashi main.hashi
```

On Windows with MinGW-w64:

```powershell
g++ -std=c++11 main.cpp -o hashi.exe
.\hashi.exe main.hashi
```

The repository includes [`main.hashi`](main.hashi) as a sample program. Pass the input filename as a command-line argument.

Example input:

```text
str name = hashi
print name
int x = 12
int y = 4
add x y
divide x y
```

Expected output:

```text
hashi
16
3
```

## Implementation

- `main.cpp` opens the file and feeds each line to the command dispatcher.
- `Lexer.h` contains the command parser and two `std::map` symbol tables: one for strings and one for integers.
- A `std::stringstream` extracts whitespace-separated tokens; the first token selects the command to execute.

Despite its filename, `Lexer.h` combines tokenization, parsing, and execution in one class.

## Current limitations

- The parser expects a fixed word order and does not support quoted strings or nested expressions.
- Integer division truncates the result; division by zero prints an error and currently returns `0`.
- Some invalid variable references can silently evaluate to `0`, because arithmetic methods use `std::map::operator[]`.
- The program expects a command-line filename and does not yet validate that `argc >= 2`.
- There are no automated tests yet.

## Possible next steps

Introduce a distinct tokenizer/parser, validate tokens and variable names, add unit tests, and return structured errors instead of printing or silently inserting missing variables.
