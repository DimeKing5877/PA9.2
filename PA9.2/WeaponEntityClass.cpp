#include "WeaponEntityClass.hpp"

void cannonWeapon::setPosistion(){
	this->cone.position = sf::Vector2f(this->x_coordinate, this->y_coordinate);
}
