#include <gtkmm.h>
#include <iostream>

class RadioButtons : public Gtk::Window {
public:
  RadioButtons()
      : box1_(Gtk::Orientation::VERTICAL),
        box2_(Gtk::Orientation::VERTICAL, 10),
        box3_(Gtk::Orientation::VERTICAL, 10), button1_("button1"),
        button2_("button2"), button3_("button3"), close_button_("close") {
    set_title("Radio Buttons");

    button2_.set_group(button1_);
    button3_.set_group(button1_);

    set_child(box1_);

    box1_.append(box2_);
    box1_.append(separator_);
    box1_.append(box3_);

    box2_.set_margin(10);
    box3_.set_margin(10);

    box2_.append(button1_);
    box2_.append(button2_);
    box2_.append(button3_);
    button1_.set_expand();
    button2_.set_expand();
    button3_.set_expand();

    button1_.set_active(true);

    box3_.append(close_button_);
    close_button_.set_expand();

    set_default_widget(close_button_);

    close_button_.signal_clicked().connect(
        sigc::mem_fun(*this, &RadioButtons::on_button_clicked));
  }

protected:
  // Signal handlers:
  void on_button_clicked() { hide(); }

  // Member widgets:
  Gtk::Box box1_, box2_, box3_;
  Gtk::CheckButton button1_, button2_, button3_;
  Gtk::Separator separator_;
  Gtk::Button close_button_;
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.examples.hello");

  return app->make_window_and_run<RadioButtons>(argc, argv);
}
