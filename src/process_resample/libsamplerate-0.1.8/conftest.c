/* confdefs.h */
#define PACKAGE_NAME "libsamplerate"
#define PACKAGE_TARNAME "libsamplerate"
#define PACKAGE_VERSION "0.1.8"
#define PACKAGE_STRING "libsamplerate 0.1.8"
#define PACKAGE_BUGREPORT "erikd@mega-nerd.com"
#define PACKAGE_URL "http://www.mega-nerd.com/libsamplerate/"
#define PACKAGE "libsamplerate"
#define VERSION "0.1.8"
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define LT_OBJDIR ".libs/"
#define STDC_HEADERS 1
#define HAVE_STDINT_H 1
/* end confdefs.h.  */
#include <stdio.h>
#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#ifdef HAVE_STRING_H
# if !defined STDC_HEADERS && defined HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#ifdef HAVE_STRINGS_H
# include <strings.h>
#endif
#ifdef HAVE_INTTYPES_H
# include <inttypes.h>
#endif
#ifdef HAVE_STDINT_H
# include <stdint.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
static long int longval () { return (long int) (sizeof (int)); }
static unsigned long int ulongval () { return (long int) (sizeof (int)); }
#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  FILE *f = fopen ("conftest.val", "w");
  if (! f)
    return 1;
  if (((long int) (sizeof (int))) < 0)
    {
      long int i = longval ();
      if (i != ((long int) (sizeof (int))))
	return 1;
      fprintf (f, "%ld", i);
    }
  else
    {
      unsigned long int i = ulongval ();
      if (i != ((long int) (sizeof (int))))
	return 1;
      fprintf (f, "%lu", i);
    }
  /* Do not output a trailing newline, as this causes \r\n confusion
     on some platforms.  */
  return ferror (f) || fclose (f) != 0;

  ;
  return 0;
}
