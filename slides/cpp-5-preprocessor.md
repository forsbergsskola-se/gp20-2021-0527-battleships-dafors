
## 1. Preprocessor

- All preprocessor commands start with `#`
<br/><br/>
- Prepares source code for the compiler
  - Strips comments and does textual replacements
  - It can be **conditional** through preprocessor commands
  - It can define **functions** (“macros”)
  - Resolves includes
  - Can be used to **control behavior** of the compiler (through “pragmas”)
<br/><br/>
- Does not understand `C++`
- Can theoretically be used for other purposes than `C++`

---

## 2. #Include

 #### `#include` `<file>` 
 - `#include` \<file> replaces the include statement with the complete contents of the specified file
  - It is typically used to include header and inline files
  - It can in fact include anything
- Looks for the file in the global include folders
- **VC++: Tools** &#8594;  **Options** &#8594;  **Projects and Solutions** &#8594; **VC++ Directories** &#8594;  **Include Files**
<br/><br/>
#### `#include` `“file”`
- Looks for the file relative to the **location** of the current file, and in the directories defined in the project settings


---

## 3. Define

```c++
#define ONE   1		// 0001
#define TWO   2		// 0010
#define FOUR  4 		// 0100
#define EIGHT 8		// 1000

int i = 15;			// 1111
i = i & ~EIGHT;		// 0111
i = i & ~ONE; 		// 0110
```
- `Define` is used to define symbols that will be **replaced** later in the source code
- Symbols do not need to have a value (example: include guards; see there)
- `Defines` can also be added in the compiler options (see project settings)

---

## 4. Macros

```c++
#define max(a,b)  (((a) > (b)) ? (a) : (b))
```

- Can use `defines` to create compile-time functions with parameters
- `Parameters` will be textually replaced in source code

---

## 5. #Undef

```c++
#undef CreateFont	// get rid of windows CreateFont define
```

- Removes the current definition of an `identifier`
  - i.e. all subsequent occurences of that `identifier` will be **ignored**
<br/><br/>
- It is no problem if the `identifier` is not defined at all
- To remove a macro, provide **just the name**, no parameters

---

## 6. #ifdef, #ifndef, #endif

```c++
#ifdef WINDOWS
  ...
#endif
```

#### #ifdef symbol, #ifndef symbol 
- These are ctually short forms of:
  - `#if defined` (symbol)  
  - `#if !defined` (symbol)
<br/><br/>
- All text until next `#endif` is removed if given symbol does not exist / does exist
<br/><br/>
#### Typical uses:
- Include guards of header files
- System-specific code

---

## 7. #else, #elif

```c++
#if defined(WINDOWS)
  ...
#elif defined(LINUX)
  ...
#else
  ...
#endif
```

#### #else, #elif
- Are used in combination with `#if`, `#ifdef` or `#ifndef`
- `#elif = else if` *(which is not possible)*

---

## 8. __FILE__, __LINE__, #line

```c++
cout << "This is file " << __FILE__ << ", line " << __LINE__ << endl;

#line 555 "stupid.cpp"
cout << "This is file " << __FILE__ << ", line " << __LINE__ << endl;
```
- Pre-defined macros `__FILE__ `and `__LINE__` always contain:
  - The name of the current file in **"quotation marks"** and the current line number
  - It is very useful for debugging purposes *(error messages!)*
<br/><br/>
- `#line` command can be used to change the current file name and line number, *it also affects compiler error messages*

---

## 9. __DATE__, __TIME__

```c++
cout << "compiled on: " << __DATE__ << " " << __TIME__ << endl;
```
- `__DATE__` is replaced by the current date (time of compilation) in the form `Mmmm dd yyyy`
- `__TIME__ `is replaced by the current time in the form `hh:mm:ss`

- Both as a string literal (i.e. in quotation marks)

---

## 10. #error

```c++
#if !defined(__cplusplus) 
#error C++ compiler required. 
#endif 

#ifdef LINUX
#error this will not compile on linux
#endif
```
- `#error` causes a (compile-time) error message
- Provide your own error message!
- It is useful to check for requirements when compiling

---

## 11. #pragma

```c++
#pragma warning( push ) 
#pragma warning( disable : 4705 ) 

// Some code 

#pragma warning( pop ) 
```

- `#pragma` allows to access options **specific to your operating system and compiler**
  - i.e. every compiler will support other options here
  - Options that your compiler does **not** know will be (silently) ignored
<br/><br/>
- **Example:** `VC++` allows to (temporarily) disable warnings
for a complete list, see the [docs](https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=msvc-160)
