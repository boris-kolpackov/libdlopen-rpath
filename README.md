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

Note that on Linux this only works if the executable uses RPATH and not
RUNPATH. See this article for background:

https://blog.qt.io/blog/2011/10/28/rpath-and-runpath/
