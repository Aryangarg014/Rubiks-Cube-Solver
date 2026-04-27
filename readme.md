# Rubik's Cube Solver using IDA*

A C++17 Rubik's Cube solver built around object-oriented cube modeling, interchangeable state representations, and informed search. The project implements DFS, BFS, IDDFS, and IDA* across the same cube interface, and uses a corner pattern database heuristic to guide IDA* search.

## Highlights

- Three interchangeable cube representations:
  - 3D array
  - 1D array
  - bitboard
- A shared `RubiksCube` abstraction with common move, shuffle, print, and corner-inspection helpers.
- Search implementations for DFS, BFS, IDDFS, and IDA*.
- Hashable cube states so the representations can be used directly with `unordered_map` and `unordered_set`.
- A corner pattern database stored in a compact nibble array for fast heuristic lookup.
- Binary persistence for the heuristic table so the database can be generated once and reused.

## Project Idea

The cube is modeled as a reusable domain object rather than a single concrete structure. Each representation exposes the same move semantics and solved-state logic, which makes it possible to compare algorithm behavior and state-storage trade-offs without changing the solver logic itself.

The current demo path in `src/main.cpp`:

1. loads the corner database from disk if it exists,
2. generates it with BFS if the file is missing,
3. scrambles a cube,
4. runs IDA* with the pattern database heuristic,
5. prints the scramble and the solved state.

## Architecture

### Cube representations

The repository contains three concrete cube models under `src/cube/`.

`RubiksCube3dArray` stores the cube as `vector<vector<vector<char>>>` and is straightforward to inspect and debug.

`RubiksCube1dArray` stores all 54 stickers in a flat `vector<char>` for a denser layout.

`RubiksCubeBitboard` packs each face into a compact 64-bit representation, which keeps the state small and makes the comparison and hash logic lightweight.

All three implementations provide the same face-turn methods and override equality and hashing support, which allows them to be used in standard hashed containers during search.

### Search algorithms

The solver folder includes these implementations:

- `BFSSolver.h`
- `DFSSolver.h`
- `IDDFSSolver.h`
- `IDAStarSolver.h`

DFS, BFS, and IDDFS are present as alternate search strategies for comparison. The active solver path uses IDA*, which keeps the memory footprint lower than BFS while still using heuristic guidance to reduce the search space.

### Corner pattern database

The heuristic is based on corner-state information only.

- `CornerPatternDatabase` maps a cube state to a database index using corner permutation rank plus corner orientation.
- `CornerDBMaker` builds the database with BFS from the solved state and stores the discovered depths.
- `NibbleArray` stores two 4-bit values per byte, so the heuristic table is packed densely on disk and in memory.

The current database size is derived from corner permutation and orientation:

$$8! \times 3^7 = 40{,}320 \times 2{,}187 = 88{,}179{,}840$$

Stored as 4-bit entries, that is about 44,089,920 bytes, or roughly 42 MB.

## Implementation Notes

- The solver code uses templates so the same algorithm can run on any cube representation that exposes the shared interface and hash/equality support.
- The cube move set is the standard 18-turn face metric: quarter turns, inverse turns, and double turns for all six faces.
- The repository keeps older DFS/BFS/IDDFS experiments in commented code inside `main.cpp`, which makes the file a useful experiment harness for comparing search strategies.
- The project uses `unordered_map` and `unordered_set` internally for visited-state tracking and parent reconstruction.
- The pattern database is persisted as a binary file, so it does not need to be regenerated on every run once created.

## Repository Layout

- `src/cube/` - cube abstraction and the three concrete cube backends
- `src/solver/` - DFS, BFS, IDDFS, and IDA* implementations
- `src/PatternDatabase/` - pattern database storage, indexing, and generation
- `Databases/` - saved heuristic artifacts
- `build/` - local CMake build output

## Build

Requirements:

- CMake 3.20 or newer
- A C++17-capable compiler

Build from the repository root:

```bash
cmake -S . -B build
cmake --build build
```

The executable target is named `cube` and is written to the build directory.

## Run

Run the executable from the build directory.

```bash
./cube
```

On Windows PowerShell:

```powershell
.\build\cube.exe
```

The current demo in `src/main.cpp` uses a hardcoded path for the corner database file. If you are running the project from a different checkout location, update that path to a repository-relative path such as `Databases/cornerDepth8.bin`.

If the database file is missing, the program generates it before solving.

## Data Files

The `Databases/` directory currently contains:

- `cornerDepth8.bin` - the binary corner pattern database used by the demo
- `cornerDepth5.txt` - an additional text artifact kept in the repository

## Notes

- `main.cpp` is set up as a demo and benchmarking entry point rather than a final CLI.
- The cube code uses `<bits/stdc++.h>`, which keeps the project compact but ties it to toolchains that provide that header.
- No license file is currently present in the repository.
