# DCN Lab — C++ Programs

Simple, beginner-friendly C++ implementations of common Data Communication & Networks lab exercises. Each program is self-contained and designed to be readable in one sitting.

## Programs

| # | File | Question |
|---|------|----------|
| 1 | `leaky_bucket.cpp` | Implement traffic policing using the Leaky Bucket algorithm. |
| 2 | `hamming_code.cpp` | Generate Hamming Code for error detection and correction. |
| 3 | `crc_ccitt.cpp` | Error detection using CRC-CCITT (16-bit). |
| 4 | `bellman_ford.cpp` | Shortest path between vertices using Bellman-Ford. |
| 5 | `dijkstra.cpp` | Shortest path between vertices using Dijkstra. |
| 6 | `character_stuffing.cpp` | Data link layer framing — character stuffing. |
| 7 | `bit_stuffing.cpp` | Data link layer framing — bit stuffing. |
| 8 | `tcp_server.cpp` + `tcp_client.cpp` | TCP/IP client-server: client requests a file by name, server returns its contents. |

## Build

Compile any program with `g++`:

```bash
g++ leaky_bucket.cpp -o leaky_bucket
```

Or compile everything at once:

```bash
for f in *.cpp; do g++ "$f" -o "${f%.cpp}"; done
```

## Run

Most programs are interactive — just run the binary and follow the prompts:

```bash
./leaky_bucket
./hamming_code
./crc_ccitt
./bellman_ford
./dijkstra
./character_stuffing
./bit_stuffing
```

### TCP file transfer (needs two terminals)

```bash
# Terminal 1 — start the server
./tcp_server

# Terminal 2 — run the client
./tcp_client
# then enter a filename, e.g.: sample.txt
```

The server listens on port `8080` and looks for the requested file in its working directory. A `sample.txt` is included for testing.

## Quick reference — what each program demonstrates

- **Leaky Bucket** — smooths bursty input traffic into a constant output rate; drops overflow.
- **Hamming(7,4)** — 4 data bits + 3 parity bits; detects and corrects any single-bit error.
- **CRC-CCITT** — uses polynomial `x^16 + x^12 + x^5 + 1` to produce a 16-bit checksum.
- **Bellman-Ford** — works with negative edge weights; detects negative-weight cycles.
- **Dijkstra** — greedy shortest path on non-negative weighted graph (adjacency matrix).
- **Character stuffing** — escapes `DLE` inside a `DLE STX … DLE ETX` frame.
- **Bit stuffing** — inserts a `0` after five consecutive `1`s so the flag `01111110` is unique.
- **TCP file transfer** — uses BSD sockets (`socket`, `bind`, `listen`, `accept`, `connect`).

## Notes

- All programs use only the standard library (and POSIX sockets for the TCP pair).
- Tested with `g++` on Linux. The TCP programs include `<arpa/inet.h>` and `<unistd.h>` and will not compile on Windows without changes.
