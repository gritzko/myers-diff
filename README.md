# Myers Diff - a C++ header-only lib

A Myers diff algorithm with various optimizations, based on the
[google/diff-match-patch](https://github.com/google/diff-match-patch) library
by Neil Fraser.  The purpose of this refactoring is to have a battle-tested
Myers implementation in idiomatic C++, made with some acceptable standard of
quality.

Improvements made:

* object-oriented interface a MyersDiff<String> template parametrized with an
* arbitrary string class (or an arbitrary vector with an STL-like interface)
* zero-allocation (the original Java/JavaScript code does a lot of annoying
* (sub)string (re)allocations) fuzz tested

Again, the algorithm accepts arbitrary container classes, so there is no need to have a separate implementation for a line-based diff and char-based diff, for example.
Just use `std::vector<std::string>` to have a line-based diff (this idea is borrowed from [dtl](https://github.com/cubicdaiya/dtl)).

Omissions made:

* no matching
* no patching

I only need the diff part... other parts are skipped. Feel free to add.
