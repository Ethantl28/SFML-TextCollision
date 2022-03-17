#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

//Variables
sf::Vector2u resolution = { 1280, 720 };

int main()
{
	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML Testing Window", sf::Style::Close | sf::Style::Titlebar);
	
	//Text
	sf::Text score;
	sf::Font scoreFont;

	if (!scoreFont.loadFromFile(".\\assets\\fonts\\DIGITALDREAMFATSKEW.ttf")) return 0;
	score.setFont(scoreFont);
	score.setCharacterSize(16);
	score.setString("text lol");
	score.setFillColor(sf::Color::White);
	score.setPosition(resolution.x / 2, resolution.y / 2);
	score.setOrigin(8, 8);

	sf::Clock timer;

	sf::Vector2f ballVelocity(16.f, 10.f);

	//Sprites
	sf::Sprite topWall;
	sf::Sprite rightWall;
	sf::Sprite bottomWall;
	sf::Sprite leftWall;
	sf::Sprite ball;

	//Textures
	sf::Texture wallTexture;
	if (!wallTexture.loadFromFile(".//assets//textures//tile.png")) return 0;
	wallTexture.setRepeated(true);
	sf::Texture ballTexture;
	if (!ballTexture.loadFromFile(".//assets//textures//beachball.png")) return 0;

	//Wall Setup
	topWall.setTextureRect(sf::IntRect(0, 0, resolution.x, 50));
	rightWall.setTextureRect(sf::IntRect(0, 0, 50, resolution.y));
	bottomWall.setTextureRect(sf::IntRect(0, 0, resolution.x, 50));
	leftWall.setTextureRect(sf::IntRect(0, 0, 50, resolution.y));

	topWall.setTexture(wallTexture);
	rightWall.setTexture(wallTexture);
	bottomWall.setTexture(wallTexture);
	leftWall.setTexture(wallTexture);

	sf::FloatRect topWallBoundingBox = topWall.getGlobalBounds();
	sf::FloatRect bottomWallBoundingBox = bottomWall.getGlobalBounds();
	sf::FloatRect rightWallBoundingBox = rightWall.getGlobalBounds();
	sf::FloatRect leftWallBoundingBox = leftWall.getGlobalBounds();

	bottomWall.setPosition(0, resolution.y - 50);
	rightWall.setPosition(resolution.x - 50, 0);
	leftWall.setPosition(0, 0);

	//Ball Setup
	ball.setTexture(ballTexture);
	ball.setScale(100.0f / ballTexture.getSize().x, 100.0f / ballTexture.getSize().y);
	ball.setOrigin(50.0f, 50.0f);
	ball.setPosition(resolution.x / 2, resolution.y / 2);
	sf::FloatRect ballBoundingBox = ball.getGlobalBounds();

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}

			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					cout << "LMB" << endl;
				}
			}

			//Move ball
			/*sf::Time timeElapsed = timer.getElapsedTime();
			if (timeElapsed.asSeconds() > 0.01)
			{
				sf::Vector2f deltaPosition = ballVelocity * timeElapsed.asSeconds();
				ball.move(deltaPosition.x, deltaPosition.y);
				ballBoundingBox = ball.getGlobalBounds();

				if (ballBoundingBox.intersects(topWallBoundingBox))
				{
					ball.setPosition(ball.getPosition().x, resolution.y - 1);
					ballVelocity.y = -ballVelocity.y;
				}
				if (ballBoundingBox.intersects(bottomWallBoundingBox))
				{
					ball.setPosition(ball.getPosition().x, resolution.y - 1);
					ballVelocity.y = -ballVelocity.y;
				}
				if (ballBoundingBox.intersects(rightWallBoundingBox))
				{
					ball.setPosition(resolution.x - 1, ball.getPosition().y);
					ballVelocity.x = -ballVelocity.x;
				}
				if (ballBoundingBox.intersects(leftWallBoundingBox))
				{
					ball.setPosition(resolution.x + 1, ball.getPosition().y);
					ballVelocity.x = -ballVelocity.x;
				}
				if (ball.getPosition().x > resolution.x || ball.getPosition().y > resolution.y)
				{
					ball.setPosition(resolution.x / 2, resolution.y / 2);
				}
			}*/

			window.clear(sf::Color::Black);
			window.draw(score);
			window.draw(ball);
			window.draw(topWall);
			window.draw(rightWall);
			window.draw(leftWall);
			window.draw(bottomWall);
			window.display();
		}
	}

	return 0;
}
