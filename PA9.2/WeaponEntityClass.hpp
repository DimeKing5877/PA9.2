#pragma once	
#include "MainHeader.hpp"
#include "BasicShapes.hpp"
#include <SFML/Graphics/Vertex.hpp>
//weapon entity is the basics for a weapon in the game. future/complex weapons will be derived from this class. 

class weaponEntityClass{
public:
	//constructor
	weaponEntityClass(const sf::Color newColor = sf::Color::White, float x_coordinate = 0, float y_coordinate = 0);

	//getters and setters for x and y coordinates
	void setXCoordinate(float newXCoordinate);
	void setYCoordinate(float newYCoordinate);
	void setColor(const sf::Color newColor);
	float getXCoordinate() const;
	float getYCoordinate() const;
	

	//virtual nose function, as diffrent shapes will have diffrent nose points, so this function will be overwriten in the derived classes.
	virtual void setNoseCoordinate() = 0;
	//draw function, will be implemented in the derived classes, as diffrent weapons will have diffrent shapes.
	virtual void draw(sf::RenderWindow*& window) = 0; 


protected:
	//projectile class gose here, but I have not implemented it yet. //array
	float x_coordinate; //spawn point of the weapon.
	float y_coordinate; //spawn point of the weapon.
	sf::Vector2f Nose; //x cordnent were the projectile spawn
	sf::Color objectColor; //color of the weapon, will be used to color the projectile as well.
};


class cannonWeapon : public weaponEntityClass {
protected:
	sf::ConvexShape cannonShape;//the shape of the cannon, is a convex shape, as it is a vertex, not a circle.
public:
	//cunstructor
	cannonWeapon(const float height = 20, const float bottomWidth = 20, const float topWidth = 10, const sf::Color& newColor = sf::Color::Blue, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate)
	{
		this->cannonShape.setOrigin({0, 0});
		this->cannonShape.setPointCount(4);
		this->cannonShape.setPoint(0, { topWidth/2, height/2 });
		this->cannonShape.setPoint(1, {( - topWidth / 2), height / 2});
		this->cannonShape.setPoint(2, {-bottomWidth/2, -height / 2 });
		this->cannonShape.setPoint(3, { bottomWidth / 2, -height / 2 });
		this->cannonShape.setPosition({ this->x_coordinate, this->y_coordinate });
	}
	void draw(sf::RenderWindow*& window);
	//sets the nose coordinate of the cannon, which is the point where the projectile will spawn, which is the top point of the cannon.
	//posistion is subject to change.
	void setNoseCoordinate() override {
		this->Nose = this->cannonShape.getTransform().transformPoint({ cannonShape.getPoint(0).x, cannonShape.getPoint(0).y});
	}
	
};
