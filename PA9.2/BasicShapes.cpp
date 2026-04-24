#include "BasicShapes.hpp"

Shape::Shape(const int newNumOfSides, const double newArea, const sf::Color& newColor)
{
	this->numOfSides = newNumOfSides;
	this->area = newArea;

	this->shape.setFillColor(newColor);
	this->shape.setRadius(newArea);

	if (newNumOfSides >= 3) // Can only create a shape if there are 3 or more sides
	{
		this->shape.setPointCount(newNumOfSides);
	}
	else
	{
		this->shape.setPointCount(50); // Creates a circle
	}
}

Shape::~Shape()
{

}


int Shape::getNumOfSides() const
{
	return numOfSides;
}

double Shape::getArea() const
{
	return area;
}

sf::Color Shape::getColor() const
{
	return shape.getFillColor();
}

void Shape::setNumOfSides(int newNumOfSides)
{
	numOfSides = newNumOfSides;
}

void Shape::setArea(double newArea)
{
	area = newArea;
}

void Shape::setColor(const sf::Color& newColor)
{
	shape.setFillColor(newColor);
}

void Shape::draw(sf::RenderWindow*& window)
{
	window->draw(shape);
}
