#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

int main() {
  unsigned int width = 640;
  unsigned int height = 360;

  sf::RenderWindow *window = new sf::RenderWindow(
      sf::VideoMode({width, height}), "SFML Window - My Window");

  while (window->isOpen()) {
    while (const std::optional event = window->pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window->close();
      } else if (const auto *keypressed =
                     event->getIf<sf::Event::KeyPressed>()) {
        if (keypressed->scancode == sf::Keyboard::Scancode::Escape) {
          window->close();
        }
      }
    }

    // Rendering

    window->clear(sf::Color(0xFF8800FF));

    // Drawing

    window->display();
  }

  delete window;
  return 0;
}
