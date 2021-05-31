## 1. Precompiled Headers - 1

#### Problem:
- Almost every cpp-File has got **includes**

- **includes** have includes themselves, and so on.
- Result of pre-processing step becomes very large (easily several 10,000 lines!) since parsing takes time
- Many cpp-files use same header files
- &#8594; same headers being parsed over and over!
- &#8594; waste of time

---

## 2. Precompiled Headers - 2

#### Solution:
- What takes so long is parsing of headers into internal data structures!
<br/><br/>
 #### **Idea:**
  - [ ] Parse *once*
  - [ ] Save internal data structures to *disc*
  - [ ] *Reload* for every compilation unit (e.g. cpp-file)  
  - [x] &#8594; #### "Precompiled" Headers!
<br/><br/>
- Microsoft-only, works with Visual `C++`
- Program remains compatible to C++-standard, e.g. still works with other compilers

---

## 3. Precompiled Headers - 3

#### Two files: `stdafx.h` and `stdafx.cpp`
- `stdafx` = **"Standard Application Framework"**

- It's a default name and can be named differently if desired
<br/><br/>
#### `stdafx.h`
- Almost normal header file

- User includes **all** headers that are often used here
- `stdafx.h` **must** be included in every `cpp` file as the **first line**
- All lines before `#include` `"stdafx.h"` are ignored!
<br/><br/>
#### `stdafx.cpp`
- Is a (otherwise empty!!) `cpp` file that includes `stdafx.h`

- If `stdafx.h` changes, this file will be **recompiled**

- This file has a special compiler setting that causes it to **"create [the] precompiled header"**
- i.e. it reads and *parses* `stdafx.h`, then writes the result to disc (in a file called `stdafx.pch`)
- All other files in the project have the setting **"use precompiled header"**
- i.e. instead of *parsing* `stdafx.h` themselves, they will *load* `stdafx.pch`
---




---
