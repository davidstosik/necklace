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
