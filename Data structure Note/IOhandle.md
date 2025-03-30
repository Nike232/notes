Below is an overview of many typical I/O scenarios you might encounter in online judge problems – along with strategies and concrete coding tips to handle each one.

------

## 1. Handling Unknown Input Lengths

**Situation:**
 Many problems (especially on judges like POJ) do not specify how many test cases or numbers you’ll receive. Instead, you must read until the end-of-file (EOF).

**Techniques:**

- EOF-based Loops:

  In C++ you can write:

  ```cpp
  int a, b;
  while (cin >> a >> b) {
      // Process each test case
      cout << a + b << "\n";
  }
  ```

- getline for Lines:

  For inputs where a full line is needed (or the numbers may be separated by spaces in a line), use:

  ```cpp
  string line;
  while (getline(cin, line)) {
      // Use istringstream to parse 'line'
  }
  ```

*These methods ensure your program continues reading until no more input is available.*

------

## 2. Multiple Test Cases with a Given Count

**Situation:**
 Sometimes, the first line contains a number (say T) indicating how many test cases follow.

**Techniques:**

- Fixed Loop:

  ```cpp
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
      // Read test case data
  }
  ```

*This is straightforward when T is provided.*

------

## 3. Special Input Formats

**Situation:**
 Inputs may be mixed (strings and numbers), require reading whole lines, or even involve space-containing strings.

**Techniques:**

- **Mixing `cin` and `getline`:**
   After using `cin >>`, use `cin.ignore()` before a subsequent `getline` to flush the newline.

- Using String Streams:

  If a line contains several data types, read the whole line and then use an 

  ```
  istringstream
  ```

   to extract values:

  ```cpp
  string line;
  getline(cin, line);
  istringstream iss(line);
  int x; double y; string s;
  iss >> x >> y >> s;
  ```

------

## 4. Special Output Formatting

**Situation:**
 Sometimes, output must follow an exact format (e.g., fixed width, specific decimal places, or custom separators).

**Techniques:**

- Using I/O Manipulators in C++:

  ```cpp
  cout << fixed << setprecision(2) << result << "\n";
  ```

- Using `printf` for Strict Formatting:

  ```cpp
  printf("%.2f\n", result);
  ```

*Make sure you follow the sample output exactly—this may include managing extra spaces or newlines between test cases.*

------

## 5. Reading From and Writing To Files

**Situation:**
 Occasionally (especially in practice sessions or specific assignments), you might be asked to read input from a file rather than standard input.

**Techniques:**

- Using `freopen`:

  ```cpp
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ```

  This redirects the standard input/output to the specified files.

*Note that many online judges automatically use standard input/output, so you’ll typically remove these lines before submitting.*

------

## Conclusion

In summary, when preparing for online judge problems:

- **For unknown quantities of input:** Use EOF-based loops or `getline` for full lines.
- **When the number of test cases is given:** Use a fixed loop based on the count.
- **For mixed or specially formatted inputs:** Combine `cin`, `getline`, and string streams.
- **For precise output requirements:** Use I/O manipulators (like `fixed` and `setprecision`) or `printf`.
- **For file-based input/output (if required):** Use redirection with `freopen`.

***

# Examples:

Below are five example problem descriptions (focusing on the I/O parts) corresponding to each situation:

------

### 1. Unknown Input Length

**Example Problem – “Sum Until EOF”**
 *Input Description:*
 The input consists of an unknown number of lines. Each line contains one integer. The end of the input is indicated by end-of-file (EOF).

*Output Description:*
 Print a single integer – the sum of all the input integers.

------

### 2. Multiple Test Cases with a Given Count

**Example Problem – “Add Two Numbers”**
 *Input Description:*
 The first line contains an integer T, indicating the number of test cases.
 Each of the following T lines contains two space-separated integers.

*Output Description:*
 For each test case, output a line containing the sum of the two integers.

------

### 3. Special Input Formats (Mixed Data)

**Example Problem – “Process CSV Record”**
 *Input Description:*
 A single line containing a record in CSV format: a name (a string which may include spaces), an age (integer), and a score (a floating-point number). The fields are separated by commas.

*Output Description:*
 Output the three fields on separate lines in the following order:

- Name
- Age
- Score (formatted to exactly two decimal places)

------

### 4. Special Output Formatting

**Example Problem – “Formatted Number Output”**
 *Input Description:*
 A single floating-point number.

*Output Description:*
 Output the number in a single line formatted to have a total width of 10 characters with exactly 2 digits after the decimal point.
 For example, if the input is 3.14159, the output should look like:

```
     3.14
```

------

### 5. Reading From and Writing To Files

**Example Problem – “File-Based Square Calculator”**
 *Input Description:*
 The program reads from a file named `input.txt`. The file contains an unknown number of lines, each with a single integer.

*Output Description:*
 Write to a file named `output.txt` the square of each input integer. Each result should be on a separate line in the same order as the input.

------

These examples capture the essence of different input/output requirements you might face in online judge problems. Happy practicing!