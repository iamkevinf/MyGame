#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), L"���Դ���");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("Item_Speed.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	 //Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("msyh.ttf"))
		return EXIT_FAILURE;
	sf::Text text(L"English����", font, 50);
	text.setFillColor(sf::Color::Red);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(1.f);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("start.wav"))
		return EXIT_FAILURE;
	// Play the music
	music.setLoop(true);
	music.play();

	sf::SoundBuffer buffer;
	buffer.loadFromFile("beng.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);
	//sound.play();

	 //Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.key.code == sf::Keyboard::V)
			{
				sound.play();
			}

		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Draw the string
		window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}