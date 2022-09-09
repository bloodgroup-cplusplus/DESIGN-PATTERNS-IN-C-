# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-src"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-build"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/bhushansharma/Programs/DESIGN-PATTERNS-IN-C-/SimpleAdder/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
