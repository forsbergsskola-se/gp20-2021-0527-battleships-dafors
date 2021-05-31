## 1. Functions
### Logical units inside the source code
**IPO-Principle**
  - Input: `Parameters`
  - Processing
  - Output: `Return Value`  
  <br/><br/>
  
  **Goal: Reusable Code**
  - Within a program
  - Across two or more programs  
  <br/><br/>
  
  **Why?**
  - Saves time
  - Reduces complexity, error-proneness
  - Saves money!

---

## 2. Syntax -1
```c++
ReturnType FunctionName ([ParameterType1 ParameterName1], [ParameterType2 ... ] ...)
```
```c++
int Add(int iValue1, int iValue2)
{
	return iValue1 + iValue2;
}
```
- A function can have **any** number of `parameters`, but that number is fixed
  - *variable number of parameters is possible, but more complicated and considered ugly*
<br/><br/>

- But only **one** return type 
  - can use `parameters` to return more than one value, more on that later
- **Return** terminates a function immediately and returns the argument
- Data types must match (or implicitly convertible)
- There should be *at least* one return statement on every code path

---

## 3. Syntax -2
```c++
void Print()
{
	cout << "Hello" << endl;
}
```
<br/><br/>

- Special return type **void** for functions without a return type
  - `Void` has more uses,  more on that later
  <br/><br/>
  
```c++
void Print(void)
{
	cout << "Hello" << endl;
}
```

- Formerly: `void` as `parameter` type for functions without parameters
  - *They can still do that, but do not have to*
  <br/><br/>
  
- Void-functions do not have to use return, but can without specifying a return value

---

## 4. Syntax -3

- Functions can only be used **below it’s declaration** in the source code
  - Analog to variables
  <br/><br/>
- Correct sorting is difficult, and is in fact not always possible (when not?)
<br/><br/>
- Therefore,  separation of **declaration** and **definition**: `Implementation` opens possibility of a **Forward Declaration**

---

## 5. Forward Declaration

```c++
int Add(int iValue1, int iValue2);		// forward
...
int i = Add(5, 6);			// use
...
int Add(int iValue1, int iValue2)	        // definition
{
	return iValue1 + iValue2;
}
```

- Declaration consists of **function head**
  - `Parameter identifiers` (names) are optional and will not be used, but increase readability
<br/><br/>
- Definition consists of **function head** and **functions body**
  - These must match (what if not?)
  <br/><br/>
- Compiler only needs declaration
<br/><br/>
- Linker needs implementation 

---

## 6. Call by Value

- `Parameters` behave like `variables`
- Scope is whole function body

- Values can be modified inside the function, but they are only copies of the values passed, i.e. changing them only affects the function


---

## 7. Overloading of Names

```c++
void Foo()				{ ... }
void Foo(int i, int j)		{ ... }
void Foo(float i, float j)		{ ... }
```
- These can declare several functions by the same name, if the versions differ in `parameter types´ and/or `parameter count`
<br/><br/>
- This is called **overloading of function names**


---

## 8. Default Parameters

```c++
void Foo(int i, int j=10)			{ ... }
void Foo(float i=5.0f, float j=10.0f)	{ ... }
```
- The value of `parameters` can be **predefined**
- This makes passing of `parameter` **optional**

- It can only be done in the *declaration*, **not** in *definition* (if they are separate)
- All `parameters` following a default-parameter must also be default-parameters

- Calls must not be ambiguous!

---

## 9. Header and Source Files -1

![image](https://user-images.githubusercontent.com/7360266/119901798-aca45980-bf46-11eb-9c10-d9f194d9dcd2.png)


- It makes sense to split source code into several files
  - **Orderliness:** we don’t want millions of lines of code in one file
  - It also speeds up compiling (why?)
  <br/><br/>
- Can put functions into different `cpp` files
<br/><br/>
- The function still has to be forward-declared in files where it is used
<br/><br/>
- Linker will put everything together!

---

## 10. Header and Source files -2

![image](https://user-images.githubusercontent.com/7360266/119902230-3eac6200-bf47-11eb-9856-8f9c214bf1d2.png)

- It is bad to repeat same forward-declarations in every file
  - It could be a lot of work with thousands of functions
  <br/><br/>
- **Instead:** put forward-declaration in **header file**
  - **Headers** and **sources** typically come in pairs with the same file name (but different extensions)
  <br/><br/>
- The **header** file is included into every source file that needs it

---

## 11. Include Guards -1

![image](https://user-images.githubusercontent.com/7360266/119902388-6ef40080-bf47-11eb-84f1-539c7ec18b45.png)

- If a header is included twice, you get double-definition error messages

- This can easily happen when headers include each other

---

## 12. Include Guards -2

```c++
#ifndef MYFILE_H_INCLUDED
#define MYFILE_H_INCLUDED

int Add(int, int);
void Foo();

#endif
```

- Problems can be prevented by enclosing **every** header file with the following construction:
   called `include guards`
- The preprocessor will include code only once, second include will be skipped

```c++
#pragma once

int Add(int, int);
void Foo();
```

- More modern approach for include guards
- Not a C++ Standard!
- But supported by most compilers
- Behaviour may be partially unpredictable
  - e.g. for duplicate files in separate paths

---

## 13. Inline Functions -1

- Functions can be completely defined inside a header file &#8594; `Inline Functions`

- **Advantage:** compiler is free to – *instead of generating a function call* – insert the complete source code of the called function

- This may be faster but is only effective for **smaller** functions (typically one or two lines)
  - Mind you: *compiler is free to make that decision*


---

## 14. Inline Functions -2
```c++
int Add(int i, int j);

...

inline
int Add(int i, int j)	
{ 
	return i + j;	
}
```
- When `declaration` and `definition` are separated, and **both** are in a header file, a definition must use key word  **inline**
<br/><br/>
- **Otherwise:** `Linker error!` (why?)

---

## 15. Inline Files

![image](https://user-images.githubusercontent.com/7360266/119903506-158cd100-bf49-11eb-85c6-ac01b0734e88.png)

- Some programmers prefer to have functions bodies in a separate file because the header file looks tidier
  - The functions are still inlined for better performance
  <br/><br/>
- A compromise is the use of **inline files**
  - These are not a standardized feature, but something you can do with the `#include` statement
  - Explicitly discouraged by Google Standard

---

## 16. Extern Variables

```c++
extern int g_iNumEntries;
```
### What if several source files need to access the same variable?

- A variable must be declared in every file *(remember: compilation units!)*
  - Possibly by using headers
<br/><br/>

#### Problem:
- It causes linker errors, because variable exists multiple times
<br/><br/>

#### Solution: 
- Key word extern
- It is similar to forward declaration; compiler knows variable, but does not actually create it
- But exactly one compilation unit must create it

---

## 17. Recursion

- Functions can call themselves!
- But be careful, not to run into endless loops! :)
---
