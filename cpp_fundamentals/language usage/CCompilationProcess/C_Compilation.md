# How a C program is compiled

## Commands 

```
gcc ./helloworld.c ./main.c -save-temps
```

## Steps
1. Pre-processing (.i files):
    - Removal of Comments
    - Expansion of Macros
    - Expansion of the included files.
    - Conditional compilation (#if, #ifndef, etc.)
2. Compilation (.s files --> assembly):
3. Assembling (.o files --> machine code):
    - The assembler turns the assembly into machine code
    - At this phase, only existing code is converted into machine language, and the function calls like printf() or HelloWorld() are not resolved.
4. Linking (.out files):
    - The .o files contain symbol tables which list resolved and undefined(need resolution) variables and functions.
    - The linker matches undefined symbols in one object file with the corresponding definitions in another.
    - The linker also does the address relocation: Adjusts addresses in the machine code to reflect the final memory layout of the program.


## How Dynamic Linking Works?
- Code Sharing: DLLs are shared libraries containing code and data used by multiple programs.
- Import Table: Executables include an import table that lists the DLLs they depend on and the symbols (functions/variables) required from each DLL.
- Runtime Loading: When the program runs, the Windows loader identifies the required DLLs from the import table.
- Dynamic Linking: The loader locates the DLLs in memory or loads them into memory if they are not already loaded.
- Symbol Resolution: The loader updates the program's import table with the actual memory addresses of the required symbols from the DLLs.
- Execution: When the program calls a function or accesses a variable from the DLL, the call is redirected to the resolved address in the DLL.