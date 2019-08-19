# libdlopen-rpath

Test for dlopen() and rpath interaction

To test, build `tests/basics/` with `-v` then copy and paste the linker
command line, remove the library (but keep `-rpath`), relink, and run.

Known results:

```
Linux:           works (as documented)
FreeBSD 12.0:    works
Mac OS 10.14.5:  works
```
