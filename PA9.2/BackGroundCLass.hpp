#pragma once
#include "MainHeader.hpp"
#include "BasicShapes.hpp"

class BackGround {
private:
	sf::Texture backgroundTexture;
	sf::Sprite* backgroundSprite;

public:
	BackGround() : backgroundTexture(), backgroundSprite(nullptr) {
		if (!backgroundTexture.loadFromFile("assets\\grass.png")) {
			std::cerr << "Error loading background texture!" << std::endl;
		}
		else {
			backgroundSprite = new sf::Sprite(backgroundTexture);
			backgroundSprite->setPosition(sf::Vector2f(0.f, 0.f));
		}
	}

	~BackGround() {
		delete backgroundSprite;
	}

	// Draw the background scaled to fill the render window
	void draw(sf::RenderWindow*& window) {
		if (!window) return;
		if (!backgroundSprite) return;

		sf::Vector2u winSize = window->getSize();
		sf::Vector2u texSize = backgroundTexture.getSize();

		if (texSize.x > 0 && texSize.y > 0) {
			float scaleX = static_cast<float>(winSize.x) / static_cast<float>(texSize.x);
			float scaleY = static_cast<float>(winSize.y) / static_cast<float>(texSize.y);
			backgroundSprite->setScale(sf::Vector2f(scaleX, scaleY));
		}
		else {
			backgroundSprite->setScale(sf::Vector2f(static_cast<float>(winSize.x), static_cast<float>(winSize.y)));
		}

		backgroundSprite->setPosition(sf::Vector2f(0.f, 0.f));
		window->draw(*backgroundSprite);
	}
};
