## 1. Static Arrays

```c++
int aiMyArray[10];

int i = 12;
int aiDoesNotWork[i];
```
- **`array`** = a numbered (“indexed”) range of values of same data type
- **`static`** = arrays of constant size

- **`constant`** = known at compile time

---

## 2. Static Arrays - 2

```c++
aiMyArray[0] = 5;

for(int i=0; i<10; ++i)
{
	cout << aiMyArray[i] << endl;
} 
```

- Access elements with the `[]`-operator and an index
  - Index always starts with `0`
  - Last valid index = size `-1`
  - i.e. `array[10]` has indicies `0 - 9`
<br/> <br/>
- Index can also be a `variable` (or any expression)
- **Attention:** `array` bounds are **not** checked! **out-of-bounds access is likely to cause a crash!** 
- Initial contents of `array` is (most of the time) undefined

---

## 3. Initializing Arrays

#### Using a `loop`
```c++
for(int i=0; i<10; ++i)
{
	aiMyArray[i] = 0;
} 
```

#### Using a list of values
```c++
int aiMyArray[10] = { 0, 1, 0, 1, 1, 0, 0, 0, 0, 0 };

or

int aiMyArray[10] = { 0 };
```
- The list may be shorter than actual array; missing values are = `0`

---

## 4. Multi-Dimensional Arrays

```c++
int aiMyArray [3][3] = {{1, 2, 3}, {4, 5 }, {6}};

int aiMyArray [3][3] = {1, 2, 3, 4, 5, 0, 6, 0, 0};
```
- It is possible to create `arrays` with **more than one dimension**

- It can also be initialized using an initializer list
- **There is two ways to do it:**
  - One big list
  - Nested lists
- Values that are **not** specified are assumed to be 0

---

## 5. Random Numbers

```c++
int i = rand() % 6 + 5;
```
#### Function `rand()`
- Included from `stdlib.h`

- Returns a pseudo-random number between `0` and `RAND_MAX`
- It is not really random, but a mathematical function displaying “chaotic” behavior
- Close to the ideal distribution
<br/><br/>
- **How can we obtain a random number inside a desired interval, e.g. a number between 5 and 10?**
  - Use combination of modulo-operator and addition!

---

## 6. Random Numbers - 2

```c++
srand((unsigned int) time(0)); 
```

- Successive calls of `random()` return a deterministic sequence of numbers
  - i.e. you get the same “random” numbers every time you run the program
  - It can be very useful for debugging
<br/><br/>
- The function `srand(unsigned int)` sets `seed` (= starting value) for the random number generator
- **Good trick:** initialize `srand()` with current system time
  - It needs to include `time.h`
  - Do this only once!

---

## 7. Exercise

#### Test the `rand()` function!

- Create a large number of random numbers between 1 and 20!

- Count how often every number appears
- Compare this to the ideal distribution (i.e. display propability of every number or something like that)
---

## 8. Battleships

#### The Rules:
- **2** Players

- **10 x 10** grid per player
- **Ships:** sizes 5, 4, 3, 2 ships with 2
- **Ships** may be placed vertically or horizontally
- **Ships** may not overlap and may not touch each other (i.e. there needs to be at least 1 empty grid cell around the ship in every direction)

- Players take alternating turns
- Coordinates given in the form g7, a2, d2 etc...
- **Feedback** "Hit" or "Miss"
- **Feedback** "Ship sunk!"


---
