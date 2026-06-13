# Caesar Cipher Tool

A command-line tool written in pure C that encrypts or decrypts text using the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher). It reads text from a file, applies a user-specified shift, and writes the result to an output file.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## Features

- Shifts alphabetic characters (`A`–`Z`, `a`–`z`) by a configurable amount, preserving case.
- Supports positive (encrypt) and negative (decrypt) shifts between `-26` and `26`.
- Wraps around the alphabet correctly (e.g. with a shift of 3, `Z` → `C`).
- Non-alphabetic characters are replaced with spaces.
- Reads up to 2048 characters of input.
- No external dependencies — just the C standard library.

## Build

Requires `gcc` or any C compiler:

```sh
gcc -o main main.c
```

## Usage

```sh
./main
```

The program prompts for three things in order:

1. **Input file path** — full path to the file containing your plaintext.
2. **Shift value** — an integer between `-26` and `26`.
3. **Output file path** — full path where the result is written.

### Example

With `input.txt` containing:

```
Hello, World!
```

Running with a shift of `5` writes:

```
Mjqqt  Btwqi
```

To decrypt, run again on that output using the inverse shift (`-5`).

## How It Works

The cipher shifts each letter by a fixed number of positions, wrapping at the alphabet boundary. The `Process_string` function in `main.c`:

1. Replaces any non-alphabetic character with a space.
2. Shifts each remaining letter, wrapping the uppercase and lowercase ranges independently so case is preserved.

File handling is split into `read_text_chunk` (reads the input) and `write_text_chunk` (writes the result).

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Source — file I/O and the Caesar cipher logic. |
| `input.txt` | Sample input. |
| `output.txt` | Sample output. |

## License

Released under the [MIT License](LICENSE).
