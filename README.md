# minitalk
Minitalk is a small inter-process messaging project that demonstrates sending and receiving messages between processes using UNIX signals. The project provides two executables: a server that receives messages and a client that sends messages to the server.

# This project is part of the School 42 curriculum (42 Network).
# It was developed as an assignment to implement inter-process communication using UNIX signals.

## Project layout

- `SRCS/` — C source files:
  - `client.c` — client program that encodes and sends a message to the server via signals.
  - `server.c` — server program that prints its PID and receives messages via signals.
  - `minitalk.c` — shared helpers used by both client and server (encoding/decoding bits, helpers).
- `includes/` — project headers (e.g. `minitalk.h`, `libft.h`).
- `libft/` — precompiled `libft.a` library (already compiled and included; the Makefile will not try to recompile or delete this archive).
- `Makefile` — build rules.

## Programs

- `server`
  - Behaviour: prints its PID and waits for incoming messages from clients. When it receives a message it reconstructs bytes sent bit-by-bit via signals and prints the received text to stdout.
  - Typical use: run it first so it can accept messages.

- `client`
  - Behaviour: sends a message string to a server process by sending sequences of signals representing each bit of each byte. The client requires the target server PID.
  - Typical use: provide the server PID and a message to send.

## Build

The Makefile is configured to use explicit file paths and to keep the provided `libft/libft.a` untouched (it will not be rebuilt or removed by `make` rules).

To build both programs:

```bash
make
```

This will produce the executables `client` and `server` in the project root.

## Usage examples

1. Start the server (it will print its PID):

```bash
./server
# output example:
# Server PID: 12345
```

2. In another terminal, send a message with the client, using the server PID from the previous step:

```bash
./client 12345 "Hello, server!"
```

The server should print the received message.

## Cleaning

- Remove object files:

```bash
make clean
```

- Remove object files and executables (does NOT remove `libft/libft.a`):

```bash
make fclean
```

## Notes and dependencies

- The implementation uses POSIX signals (`SIGUSR1`, `SIGUSR2`) for bit transmission; it requires a standard UNIX-like environment.
- A C compiler (e.g., `cc`/`gcc`/`clang`) is required to build the project.
- `libft/libft.a` is expected to be present and precompiled in the `libft/` folder. The Makefile intentionally avoids building or removing it.

## Authors

- Hector Gamiz (hgamiz-g)
