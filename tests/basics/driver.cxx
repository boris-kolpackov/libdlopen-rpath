#include <errno.h>
#include <dlfcn.h>

#include <iostream>

static const char* name =
#ifdef __APPLE__
  "libdlopen-rpath.dylib"
#else
  "libdlopen-rpath.so"
#endif
  ;

using namespace std;

template <typename F>
static inline F
function_cast (void* p)
{
  union { void* p; F f; } r;
  r.p = p;
  return r.f;
};

int main ()
{
  void* h (dlopen (name, RTLD_LAZY | RTLD_GLOBAL));

  if (h == nullptr)
  {
    cerr << "unable to dlopen " << name << ": " << dlerror () << endl;
    return 1;
  }

  auto f (function_cast<void (*) ()> (dlsym (h, "dlopen_rpath_load")));

  if (f == nullptr)
  {
    cerr << "unable to dlsym dlopen_rpath_load: " << dlerror () << endl;
    return 1;
  }

  f ();

  if (dlclose (h) != 0)
  {
    cerr << "unable to dlclose " << name << ": " << dlerror () << endl;
    return 1;
  }
}
