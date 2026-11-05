<div align="center">

# 📁 File Processing Utilities

### C++ · File I/O · Stream Parsing · Single-Pass Streaming

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![File I/O](https://img.shields.io/badge/File_I%2FO-00599C?style=for-the-badge&logoColor=white)
![Streaming](https://img.shields.io/badge/Streaming-00599C?style=for-the-badge&logoColor=white)

</div>

---

A collection of 20 single-function C++ streaming utilities for parsing and aggregating
structured text files, built with `ifstream` and `stringstream`. Each utility processes a
file line by line, without loading the whole file into memory.

> Note: these are reusable functions, not standalone programs - each `.cpp` file defines
> one function and has no `main`. To run one, call it from a small driver program, e.g.
> `g++ -std=c++17 driver.cpp fp18.cpp -o demo`, where `driver.cpp` calls
> `getColumnSum("data.csv", "Salary")`.

## Utilities by format

### Numeric streams
| File | Function | What it does |
| --- | --- | --- |
| `fileProcessing1.cpp` | `sumFile` | Sums all integers in a whitespace-delimited file |
| `fileProcessing2.cpp` | `countNegative` | Counts negative integers |
| `fileProcessing3.cpp` | `countEvens` | Counts even integers |

### CSV records (comma-delimited)
| File | Function | What it does |
| --- | --- | --- |
| `fileProcessing4.cpp` | `calculateActiveAverage` | Average score for records with status `ACTIVE` (`id,name,score,status`) |
| `fp5.cpp` | `averageInStockPrice` | Average price for records marked in stock (`id,name,price,TRUE/FALSE`) |
| `fp6.cpp` | `findTopStudent` | Student with the highest average score across whitespace-separated scores |
| `fp7.cpp` | `findHighestTotalSensor` | Sensor with the highest total across its readings |
| `fp18.cpp` | `getColumnSum` | Sums a named column from a header row; throws if the column is missing |
| `fp19.cpp` | `getColumnAverage` | Averages a named column from a header row, handling `\r` line endings |
| `fp20.cpp` | `calculateCategoryTotal` | Totals a category using a quoted-field parser that respects commas inside quotes |

### Delimited records
| File | Function | Format |
| --- | --- | --- |
| `fp11.cpp` | `countUsersWithPermission` | `name;role;permission,permission,...` |
| `fp12.cpp` | `countProjectsWithTag` | Pipe-delimited fields, comma-delimited tags |
| `fp13.cpp` | `countStudentsInCourse` | Colon-delimited fields, semicolon-delimited course lists |
| `fp14.cpp` | `countServersWithService` | Hash-delimited fields, slash-delimited service lists |

### Configuration, fixed-width, and multi-line records
| File | Function | What it does |
| --- | --- | --- |
| `fp8.cpp` | `getConfigValue` | Looks up a `key=value` config entry, skipping blank lines and `#` comments; returns `-1` if absent |
| `fp10.cpp` | `totalDepartmentSalary` | Totals salaries from fixed-width records (department at columns 24–35, salary from column 36) |
| `fp9.cpp` | `calculateTotalInventoryValue` | Totals quantity × price from three-line inventory records |
| `fp15.cpp` | `findTopSpender` | Customer with the highest total across a block of purchase lines |
| `fp16.cpp` | `findHighestScoringTeam` | Team with the highest total across a block of scores |
| `fp17.cpp` | `findLongestSession` | Session with the highest total, using a shared block-finalization helper |

## Error handling

- Missing or unreadable files raise `std::runtime_error` (except `sumFile`, which reports the failure and returns an error code).
- Missing columns in header-aware utilities raise `std::runtime_error("Column not found: ...")`.
- Empty lines are skipped; `getConfigValue` also skips `#` comment lines.

## Tech

C++ · `ifstream` / `stringstream` · single-pass streaming · delimited, fixed-width, and quoted-field parsing
