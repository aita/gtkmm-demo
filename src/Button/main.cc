#include <gtkmm.h>
#include <iostream>

class Hello : public Gtk::Window {
public:
  Hello()
      : box_(Gtk::Orientation::VERTICAL), button_("Hello"), toggle_("OFF"),
        check_("check") {
    set_title("Hello Buttons!");
    // set_default_size(400, 400);

    box_.set_margin(10);
    set_child(box_);

    button_.signal_clicked().connect(
        sigc::mem_fun(*this, &Hello::on_button_clicked));
    toggle_.signal_toggled().connect(sigc::mem_fun(*this, &Hello::on_toggled));

    box_.append(button_);
    button_.set_expand();
    box_.append(toggle_);
    toggle_.set_expand();
    box_.append(check_);
    check_.set_expand();
  }

protected:
  void on_button_clicked() { std::cout << "hello world" << std::endl; }
  void on_toggled() {
    if (toggle_.get_active()) {
      toggle_.set_label("ON");
    } else {
      toggle_.set_label("OFF");
    }
  }

  // Member widgets:
  Gtk::Box box_;
  Gtk::Button button_;
  Gtk::ToggleButton toggle_;
  Gtk::CheckButton check_;
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.examples.hello");

  return app->make_window_and_run<Hello>(argc, argv);
}
