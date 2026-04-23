#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

// Creates a shape based of the given number of sides and stores attributes with the basic call functions
class Shape
{
public:
	Shape(const int newNumOfSides, const double newArea, const sf::Color& newColor);
	virtual ~Shape();

	int getNumOfSides() const;
	double getArea() const;
	sf::Color getColor() const;

	void setNumOfSides(int newNumOfSides);
	void setArea(double newArea);
	void setColor(const sf::Color& newColor);

	void draw(sf::RenderWindow& window);

protected:
	sf::CircleShape shape;
	int numOfSides;
	double area;
};
