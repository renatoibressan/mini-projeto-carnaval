# mini-projeto-carnaval

Small C project (mini-project) used for learning and demonstrating basic program structure in C.

**Description**
- **mini-projeto-carnaval** is a compact, educational C project that contains a small command-line application with modular source files split between `src/` and `include/`.
- The code is organized into separate modules for menu handling, file operations, creature logic, and utility helpers.

**Repository structure**
- `build.bat` : Windows build script
- `include/` : Public headers used by the project
	- `arquivo.h`
	- `criatura.h`
	- `menu.h`
	- `utils.h`
- `src/` : Source files
	- `arquivo.c`
	- `criatura.c`
	- `main.c`
	- `menu.c`
	- `utils.c`

**Requirements**
- A C compiler (GCC/MinGW, Clang, or MSVC).
- Basic command-line / terminal access.

**Build (Windows)**
1. Open a Command Prompt or PowerShell in the project root.
2. Run the provided build script:

```powershell
build.bat
```

The script will compile the sources and produce an executable in the project root (name depends on the script/toolchain).

**Manual build (GCC / MinGW / Linux / macOS)**
You can compile the project manually with `gcc`. From the project root run:

```bash
gcc -Iinclude -o carnaval src/main.c src/menu.c src/arquivo.c src/criatura.c src/utils.c -Wall -Wextra
```

This produces an executable named `carnaval` (or `carnaval.exe` on Windows). Adjust filenames and flags to suit your toolchain.

**Usage**
- Run the produced executable from the project root.

```powershell
./carnaval    # Unix-like
.\carnaval.exe  # Windows PowerShell/CMD
```

- The program uses a simple CLI menu (see `src/menu.c`) to interact with the user. Source comments and header files in `include/` explain module responsibilities.

**Notes & tips**
- If you get missing-header errors, ensure the compiler include path includes `include/` (see `-Iinclude`).
- For debugging builds, add `-g` and remove optimization flags. For release builds, consider `-O2` or `-O3`.

**Contributing**
- Feel free to open issues or submit pull requests. Keep changes small and focused; document behavior changes in code comments.

**License**
- No license is specified in this repository. Add a `LICENSE` file or contact the repository owner to confirm licensing.

**Contact**
- For questions about the project structure or to request features, open an issue in the repository.
