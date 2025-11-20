#include <stdlib.h>
#include <string.h>

#include <qapplication.h>
#include <qicon.h>

// include X headers after Qt due to conflicts
#ifdef WITH_X11
# include <X11/Xlib.h>
#endif

#include "first.h"

#ifdef __APPLE__
void
qt_set_sequence_auto_mnemonic (bool);
#endif

int
main ()
{
  int unused_0;
  char unused_1[16];
  QApplication *app;
  scr_first *first;

  // for blacklisting Wayland as LibVLC doesn't support it yet
  setenv("QT_QPA_PLATFORM", "windows;cocoa;xcb", 1);

#ifdef WITH_X11
  // according to LibVLC documentation
  XInitThreads();
#endif

  unused_0 = 1;
  strcpy(unused_1, "./this.program");
  app = new QApplication(unused_0, (char *[]){unused_1, nullptr});

#ifdef __APPLE__
  qt_set_sequence_auto_mnemonic(true);
#endif

  app->setApplicationDisplayName("Animilk");
  app->setWindowIcon(QIcon(":/animilk/animilk.png"));

  first = new scr_first();
  first->show();

  app->exec();

  delete first;
  delete app;

  return 0;
}
