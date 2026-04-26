#pragma once	
#include "MainHeader.hpp"
#include "BasicShapes.hpp"
#include <SFML/Graphics/Vertex.hpp>
//weapon entity is the basics for a weapon in the game. future/complex weapons will be derived from this class. 

class weaponEntityClass : public Shape {
public:
	//constructor
	weaponEntityClass(const int newNumOfSides = 0, const double newArea = 0, const sf::Color newColor = sf::Color::White, float x_coordinate = 0, float y_coordinate = 0) : Shape(newNumOfSides, newArea, newColor)
	{
		this->x_coordinate = x_coordinate;
		this->y_coordinate = y_coordinate;
		this->x_Nose = x_coordinate;
		this->y_Nose = y_coordinate;
	}

	//getters and setters for x and y coordinates, and x and y nose
	void setXCoordinate(float newXCoordinate);
	void setYCoordinate(float newYCoordinate);
	float getXCoordinate() const;
	float getYCoordinate() const;

protected:
	//projectile class gose here, but I have not implemented it yet.
	float x_coordinate;//spawn point of the weapon.
	float y_coordinate; //spawn point of the weapon.
	float x_Nose; //x cordnent were the projectile spawn
	float y_Nose; //y cordnent were the projectile spawn
};


class cannonWeapon : public weaponEntityClass {
protected:
	sf::ConvexShape cannonShape;//the shape of the cannon, is a convex shape, as it is a vertex, not a circle.
public:
	//cunstructor
	cannonWeapon(const float height, const float bottomWidth, const float topWidth, const int newNumOfSides, const double newArea, const sf::Color& newColor, float x_coordinate, float y_coordinate) : weaponEntityClass(newNumOfSides, newArea, newColor, x_coordinate, y_coordinate)
	{
		this->cannonShape.setOrigin({0, 0});
		this->cannonShape.setPointCount(4);
		this->cannonShape.setPoint(0, { topWidth/2, height/2 });
		this->cannonShape.setPoint(1, {( - topWidth / 2), height / 2});
		this->cannonShape.setPoint(2, {-bottomWidth/2, -height / 2 });
		this->cannonShape.setPoint(3, { bottomWidth / 2, -height / 2 });
		this->cannonShape.setPosition({ this->x_coordinate, this->y_coordinate });
	}
	void draw(sf::RenderWindow*& window) override;
	

	//functions that weapon enharets
	//get num of sides, get area, get color, set num of sides, set area, set color, draw
	//x_coordinate, y_coordinate
	//use numsides to deturman loop count
};
