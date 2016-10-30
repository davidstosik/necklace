# Necklace challenge

This repository contains various answers and test cases for the [TalentHub](https://talenthub.jp) challenge named [Necklace](https://talenthub.jp/coding_test/show/6).

## Ruby solutions

- `necklace_easy.rb` is the quickest solution I could come up with. It heavily
  relies on Ruby's string and array manipulation methods. Algorithm is:
  * For each necklace:
    * Generate all possible rotations (example: `aab`, `aba` and `baa`)
    * Sort them alphabetically
    * Keep the first (this will be the canonical version of this necklace)
  * Remove duplicates from the list of canonical necklaces
  * Count the resulting list
- `necklace_fast.rb` is a slightly more complex solution, that goes faster on
  bigger sizes. Algorithm is:
  * Canonical necklace:
    * Do L times:
      * Rotate the necklace by one character
      * Compare it to the previously kept necklace
      * Keep the "smallest" (according to alphabetical order)
  * Sorted insert: use dichotomy algorithm to insert a necklace at the right
    position (alphabetical order), and discard duplicates in the process.
  * For each canonical necklace, "sorted insert" it in a list that starts empty
  * Count the resulting list

## C solution

`necklace.c` is an implementation of `necklace_fast.rb`'s algorithm in C. Its
performance results are promising.
Here is how I compile it, then run the tests:

```sh
$ gcc -Wall necklace.c -o necklace
$ ./tester.rb necklace
0.0257s <= tests/example-1.txt
0.0268s <= tests/extra_spaces-1.txt
0.0746s <= tests/max_size-1.txt
0.0759s <= tests/max_size-101.txt
```

## Testing

### Test scenarios

The `tests` folder contains test cases. Each file contains the exact input to be
passed to the solution script. For example, to test the example test on
`necklace_easy.rb`, run:

```sh
$ ./necklace_easy.rb < tests/example-1.txt
1
```

Each test file name ends with a dash and the expected answer, before the `.txt`
extension.

### Tester script

`tester.rb` is a script that takes a solution script as input, and will run the
test suite, to output execution times or errors if wrong answer was returned.
Example:

```sh
$./tester.rb necklace_fast.rb
0.2338s <= tests/example-1.txt
0.2428s <= tests/extra_spaces-1.txt
0.3081s <= tests/max_size-1.txt
0.3122s <= tests/max_size-101.txt
```
