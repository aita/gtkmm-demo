#include <gtkmm.h>
#include <iostream>

class Hello : public Gtk::Window {
public:
  Hello() : button_("Hello") {
    set_title("Hello gtkmm");
    set_default_size(400, 400);

    // Sets the margin around the button.
    button_.set_margin(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    button_.signal_clicked().connect(
        sigc::mem_fun(*this, &Hello::on_button_clicked));

    // This packs the button into the Window (a container).
    set_child(button_);
  }

protected:
  // Signal handlers:
  void on_button_clicked() { std::cout << "hello world" << std::endl; }

  // Member widgets:
  Gtk::Button button_;
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.examples.hello");

  return app->make_window_and_run<Hello>(argc, argv);
}
