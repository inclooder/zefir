#ifndef ZEFIR_GUI_APP_H
#define ZEFIR_GUI_APP_H

#include <gtkmm.h>

namespace Zefir::Gui {
  class App {
    public:
      App(int argc, char **argv);
      int run();
      void onEnterKeyPressed();
    private:
      int argc;
      char **argv;
  };
};



#endif /* end of include guard: ZEFIR_GUI_APP_H */
