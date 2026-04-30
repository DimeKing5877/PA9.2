#pragma once	
#include "MainHeader.hpp"
#include "BasicShapes.hpp"
#include "projectile.hpp"
#include <SFML/Graphics/Vertex.hpp>
//weapon entity is the basics for a weapon in the game. future/complex weapons will be derived from this class. 

class weaponEntityClass{
public:
	//constructor
	weaponEntityClass(const sf::Color newColor = sf::Color::Black, float x_coordinate = 0, float y_coordinate = 0);

	//set Color
	void setColor(const sf::Color newColor);

	//set possiton of the object
	void setObjectPosition(float newX, float newY);

	//move
	void moveObject(float newX, float newY);

	//return shape
	sf::ConvexShape& getShape();
	
	//virtual nose function, as diffrent shapes will have diffrent nose points, so this function will be overwriten in the derived classes.
	virtual void setNoseCoordinate() = 0;
	//draw function, will be implemented in the derived classes, as diffrent weapons will have diffrent shapes.
	void draw(sf::RenderWindow*& window); 

	//create the projectiles by calling WeaponClasses functions (each object has set variables for each)
	virtual void shoot(sf::Vector2f nose, sf::Vector2f Mouse, float deltaTime, int shape, int size, float velocity);

	virtual void update();

	//update Nose
	void updateNose() {
		this->setNoseCoordinate();
	}

protected:
	//basic weapon that is latter shaped in chiled class
	sf::ConvexShape weapon;
	//projectile class gose here, but I have not implemented it yet. 
	WeaponClass projectile;

	float x_coordinate; //spawn point of the weapon.
	float y_coordinate; //spawn point of the weapon.
	sf::Color objectColor; //color of the weapon, will be used to color the projectile as well.
};

class cannonWeapon : public weaponEntityClass {
protected:
	//the shape of the cannon, is a convex shape, as it is a vertex, not a circle.
	sf::Vector2f Nose; //cordnent were the projectile spawn

public:
	//cunstructor
	cannonWeapon(const float height = 20, const float bottomWidth = 20, const float topWidth = 10, const sf::Color& newColor = sf::Color::Blue, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate)
	{
		this->weapon.setOrigin({0, height/2});
		this->weapon.setPointCount(5);
		this->weapon.setPoint(0, { topWidth/2, height/2 });
		this->weapon.setPoint(1, { 0, height / 2 });
		this->weapon.setPoint(2, {( - topWidth / 2), height / 2});
		this->weapon.setPoint(3, {-bottomWidth/2, -height / 2 });
		this->weapon.setPoint(4, { bottomWidth / 2, -height / 2 });
		this->weapon.setPosition({ this->x_coordinate, this->y_coordinate });
		this->setNoseCoordinate();
	}
	//sets the nose coordinate of the cannon, which is the point where the projectile will spawn, which is the top point of the cannon.
	//posistion is subject to change.
	void setNoseCoordinate() override {
		this->Nose = this->weapon.getTransform().transformPoint({ weapon.getPoint(1).x, weapon.getPoint(1).y});
	}

	//getters
	sf::Vector2f getNose() {
		return this->Nose;
	}
};

class plusWeapon : public weaponEntityClass {
protected:
	sf::Vector2f Nose1; //cordnent were the projectile spawn
	sf::Vector2f Nose2; //cordnent were the projectile spawn
	sf::Vector2f Nose3; //cordnent were the projectile spawn
	sf::Vector2f Nose4; //cordnent were the projectile spawn
public:
	//constructor
	plusWeapon(const float barrolWidth = 10, const float barrolHight = 20, const sf::Color newColor = sf::Color::Black, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate) {
		this->weapon.setOrigin({ 0,0 });
		this->weapon.setPointCount(16);
		this->weapon.setPoint(0, { (0), barrolHight });
		this->weapon.setPoint(1, { (barrolWidth / 2), barrolHight });
		this->weapon.setPoint(2, { (barrolWidth / 2), (barrolWidth / 2) });
		this->weapon.setPoint(3, { barrolHight, (barrolWidth / 2) });
		this->weapon.setPoint(4, { barrolHight, 0 });
		this->weapon.setPoint(5, { barrolHight, -(barrolWidth / 2) });
		this->weapon.setPoint(6, { (barrolWidth / 2), -(barrolWidth / 2) });
		this->weapon.setPoint(7, { (barrolWidth / 2), -(barrolHight) });
		this->weapon.setPoint(8, { 0, -(barrolHight) });
		this->weapon.setPoint(9, { -(barrolWidth / 2), -(barrolHight) });
		this->weapon.setPoint(10, { -(barrolWidth / 2), -(barrolWidth / 2) });
		this->weapon.setPoint(11, { -(barrolHight), -(barrolWidth / 2) });
		this->weapon.setPoint(12, { -(barrolHight), 0 });
		this->weapon.setPoint(13, { -(barrolHight), (barrolWidth / 2) });
		this->weapon.setPoint(14, { -(barrolWidth / 2), (barrolWidth / 2) });
		this->weapon.setPoint(15, { -(barrolWidth / 2), (barrolHight) });
		this->weapon.setPosition({ x_coordinate, y_coordinate });
		this->setNoseCoordinate();
	}

	void setNoseCoordinate() override {
		this->Nose1 = this->weapon.getTransform().transformPoint({this->weapon.getPoint(0).x, this->weapon.getPoint(0).y}); //bottem
		this->Nose2 = this->weapon.getTransform().transformPoint({ this->weapon.getPoint(4).x, this->weapon.getPoint(4).y }); //right
		this->Nose3 = this->weapon.getTransform().transformPoint({ this->weapon.getPoint(8).x, this->weapon.getPoint(8).y }); //top
		this->Nose4 = this->weapon.getTransform().transformPoint({ this->weapon.getPoint(12).x, this->weapon.getPoint(12).y }); //left
	}

	//getters:
	sf::Vector2f getNose1(){
		return this->Nose1;
	}
	sf::Vector2f getNose2() {
		return this->Nose2;
	}
	sf::Vector2f getNose3() {
		return this->Nose3;
	}
	sf::Vector2f getNose4() {
		return this->Nose4;
	}
};

class doubleWeapon : public weaponEntityClass {
protected:
	sf::Vector2f Nose1; //cordnent were the projectile spawn
	sf::Vector2f Nose2; //cordnent were the projectile spawn
public:
	//constructor
	doubleWeapon(const float gap = 4, const int numBarrels = 2, const float barrolWidth = 10, const float barrolHight = 40, const sf::Color newColor = sf::Color::Black, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate) {
		this->weapon.setOrigin({ 0,0 });
		this->weapon.setPointCount(8);
		this->weapon.setPoint(0, {(-barrolWidth - gap), 0});
		this->weapon.setPoint(1, { (-barrolWidth - gap), -barrolHight });
		this->weapon.setPoint(2, { -gap, -barrolHight });
		this->weapon.setPoint(3, { -gap, gap });
		this->weapon.setPoint(4, { gap, gap });
		this->weapon.setPoint(5, { gap, -barrolHight });
		this->weapon.setPoint(6, { (barrolWidth + gap), -barrolHight });
		this->weapon.setPoint(7, { (barrolWidth + gap), 0});
		this->weapon.setPosition({ x_coordinate, y_coordinate });
		this->setNoseCoordinate();
	}

	void setNoseCoordinate() override {
		this->Nose1 = this->weapon.getTransform().transformPoint({ this->weapon.getPoint(1).x, this->weapon.getPoint(1).y});
		this->Nose2 = this->weapon.getTransform().transformPoint({ this->weapon.getPoint(6).x, this->weapon.getPoint(6).y });
	}

	//getters
	sf::Vector2f getNose1() {
		return this->Nose1;
	}
	sf::Vector2f getNose2() {
		return this->Nose2;
	}
};

class basicWeapon : public weaponEntityClass {
protected:
	//the shape of the cannon, is a convex shape, as it is a vertex, not a circle.
	sf::Vector2f Nose; //cordnent were the projectile spawn
public:
	//cunstructor
	basicWeapon(const float height = -30, const float Width = 15, const sf::Color& newColor = sf::Color::Black, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate)
	{
		this->weapon.setOrigin({ 0, 0 });
		this->weapon.setPointCount(5);
		this->weapon.setPoint(0, { Width / 2, height });
		this->weapon.setPoint(1, { 0, height });
		this->weapon.setPoint(2, { (-Width / 2), height});
		this->weapon.setPoint(3, { -Width / 2, 0});
		this->weapon.setPoint(4, { Width / 2, 0});
		this->weapon.setPosition({ this->x_coordinate, this->y_coordinate });
		this->setNoseCoordinate();
	}
	//sets the nose coordinate of the cannon, which is the point where the projectile will spawn, which is the top point of the cannon.
	//posistion is subject to change.
	void setNoseCoordinate() override {
		this->Nose = this->weapon.getTransform().transformPoint({ weapon.getPoint(1).x, weapon.getPoint(1).y });
	}
	//getter
	sf::Vector2f getNose() {
		return this->Nose;
	}
};
  
class lazzerWeapon : public weaponEntityClass {
  protected:
	  sf::Vector2f Nose; //cordnent were the projectile spawn
  public:
    	lazzerWeapon(const float height = 20, const float bottomWidth = 10, const float topWidth = 20, const sf::Color& newColor = sf::Color::Blue, float x_coordinate = 300, float y_coordinate = 300) : weaponEntityClass(newColor, x_coordinate, y_coordinate)
	{
		this->weapon.setOrigin({ 0, height / 2 });
		this->weapon.setPointCount(5);
		this->weapon.setPoint(0, { topWidth / 2, height / 2 });
		this->weapon.setPoint(1, { 0, height / 2 });
		this->weapon.setPoint(2, { (-topWidth / 2), height / 2 });
		this->weapon.setPoint(3, { -bottomWidth / 2, -height / 2 });
		this->weapon.setPoint(4, { bottomWidth / 2, -height / 2 });
    this->weapon.setPosition({ this->x_coordinate, this->y_coordinate });
		this->setNoseCoordinate();
	}
        
  //sets the nose coordinate of the cannon, which is the point where the projectile will spawn, which is the top point of the cannon.
	//posistion is subject to change.
	void setNoseCoordinate() override {
		this->Nose = this->weapon.getTransform().transformPoint({ weapon.getPoint(1).x, weapon.getPoint(1).y });
	}
	//getter
	sf::Vector2f getNose() {
		return this->Nose;
	}
};

