#pragma once
#include "MainHeader.hpp"

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
	void setColor(const sf::Color& newColor);//sets the color of shape

	virtual void draw(sf::RenderWindow*& window);//needs to be overwriten

protected:
	sf::CircleShape shape;//is any shape, needs a raidus and number of sides
	int numOfSides;
	double area;//raidus for shape
};
