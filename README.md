# Caesar Cipher Tool

A command-line tool written in C that encrypts text using the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) algorithm. Reads text from a file, applies a user-specified shift value, and writes the encrypted result to an output file.

## Features

- Encrypts alphabetic characters (A-Z, a-z) by shifting them by a configurable amount
- Supports both positive and negative shifts (up to ±26)
- Non-alphabetic characters are replaced with spaces
- Handles up to 2048 characters of input

## Build

Requires GCC or any C compiler.

```sh
gcc -o main main.c
```

## Usage

```sh
./main
```

The program will prompt for:

1. **Input file path** — full path to the file containing plaintext (max 2048 characters)
2. **Shift value** — integer between -26 and 26
3. **Output file path** — full path where the encrypted text will be written

### Example

Given `input.txt` containing:

```
Hello, World!
```

Running with a shift of `5` produces:

```
Mjqqt  Btwqi
```

To decrypt, run again with the inverse shift (e.g., `-5`).

## How It Works

The Caesar cipher shifts each letter in the alphabet by a fixed number of positions. For example, with a shift of 3, `A` becomes `D`, `B` becomes `E`, etc. The shift wraps around at the end of the alphabet (`Z` → `C` for a shift of 3).

The `Process_string` function in `main.c` handles this by:
1. Filtering out non-alphabetic characters (replacing them with spaces)
2. Shifting remaining letters, wrapping around at alphabet boundaries

## Files

| File | Description |
|------|-------------|
| `main.c` | Source code |
| `main` | Compiled binary |
| `input.txt` | Sample input file |
| `output.txt` | Sample output file |
| `LICENSE` | MIT license |

## License

MIT — see [LICENSE](LICENSE) for details.
