Here is a detailed README for the **ft_printf** project based on the provided PDF:

---

# ft_printf

## 📜 Project Overview
The **ft_printf** project challenges you to reimplement the standard `printf()` function from the C Standard Library. This exercise introduces variadic functions and focuses on structured, extensible, and memory-efficient programming in C.

---

## 🚀 Functionality

### **Mandatory Part**
- **Program Name**: `libftprintf.a`
- **Function**: `int ft_printf(const char *, ...);`
- **Purpose**: Mimics the behavior of the standard `printf()` function with selected features.
- **Conversions Supported**:
  - `%c` - Prints a single character.
  - `%s` - Prints a string.
  - `%p` - Prints a `void *` pointer in hexadecimal format.
  - `%d` - Prints a signed decimal integer.
  - `%i` - Prints an integer (base 10).
  - `%u` - Prints an unsigned decimal integer.
  - `%x` - Prints a number in lowercase hexadecimal.
  - `%X` - Prints a number in uppercase hexadecimal.
  - `%%` - Prints a percent symbol.

### **Bonus Part**
- **Extra Features**:
  - Manage flags `'-'`, `'0'`, `'.'`, and field width for all conversions.
  - Support additional flags: `'#'`, `' '`, `'+'`.

---

## 🛠️ Implementation Details

### **Mandatory Files**
1. **Source Files**: 
   - Core implementation files containing the `ft_printf` logic.
   - Helper functions for parsing and formatting.
2. **Header Files**:
   - Prototypes for the `ft_printf` function and its utilities.

### **Bonus Files**
1. Additional files with `_bonus` suffix for the extra features.

### **External Functions Used**
- `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.

### **Compilation**
- The `Makefile` must include rules for:
  - `all`: Build the library.
  - `clean`: Remove object files.
  - `fclean`: Remove object files and library files.
  - `re`: Rebuild the project.

Example compilation:
```bash
make
```

---

## 📋 Usage

1. Include `libftprintf.a` in your project.
2. Use `ft_printf` as a replacement for `printf`:
   ```c
   ft_printf("Hello %s! The number is %d.\n", "world", 42);
   ```

---

## 💡 Key Concepts

### **Variadic Functions**
- Allows handling a variable number of arguments passed to a function.
- Core mechanism for parsing the format string in `ft_printf`.

### **Library Creation**
- Use the `ar` command to create `libftprintf.a` at the root of the project directory.

### **Memory Management**
- Ensure efficient allocation and deallocation of memory.
- Avoid leaks and undefined behavior.

---

## 🏆 Bonus Objectives
- Implement advanced formatting flags.
- Ensure modular design for extensibility.

---

## 📂 Submission and Evaluation

1. Push your project to the assigned Git repository.
2. Verify file naming and adherence to the Norm.
3. Test the project rigorously against the standard `printf` for all supported conversions and edge cases.

---

## 🤔 FAQ

1. **What does `ft_printf` return?**
   - It returns the total number of characters printed.

2. **Can I use `libft`?**
   - Yes, this project allows the use of your `libft`.

3. **Do I need to manage the output buffer?**
   - No, buffer management of the original `printf` is not required.
