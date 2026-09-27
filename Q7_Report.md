# Q7 - Hashing vs Linear Search

## 1. Input

Song IDs:
105, 210, 315, 420, 525, 630, 735, 840

Table size: 10

Hash function:
h(key) = key % 10

Collision handling: Separate Chaining

Search keys:
735, 420, 105, 999

## 2. Insertion Result

| Key | Index | Collision |
|-----|-------|-----------|
| 105 | 5 | No |
| 210 | 0 | No |
| 315 | 5 | Yes |
| 420 | 0 | Yes |
| 525 | 5 | Yes |
| 630 | 0 | Yes |
| 735 | 5 | Yes |
| 840 | 0 | Yes |

Total collisions = 6

Load factor = 8 / 10 = 0.80

## 3. Final Hash Table

[0] -> 840 -> 630 -> 420 -> 210
[5] -> 735 -> 525 -> 315 -> 105

Other indexes are EMPTY.

## 4. Search Comparison

| Key | Hashing Comparisons | Linear Comparisons |
|-----|---------------------|--------------------|
| 735 | 1 | 7 |
| 420 | 3 | 4 |
| 105 | 4 | 1 |
| 999 | 0 | 8 |

## 5. Complexity

Hashing:
Average Search = O(1)
Worst Case = O(n)
Space = O(m + n)

Linear Search:
Time = O(n)
Space = O(1)

## 6. Comparison

Hashing can provide faster searching when the hash function distributes keys well.

Linear Search is simple and does not require an extra hash table.

In this experiment, hashing required 1-4 comparisons, while linear search required 1-8 comparisons.

## 7. Conclusion

The experiment shows that hashing can reduce search time compared with linear search.

However, collisions affect hashing
