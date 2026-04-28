#include "Player.hpp"

Player::~Player()
{}

bool Player::vulnrable(){
    return isVulnrable;
}
void Player::setVulnrabile(const bool vulnrable){
    isVulnrable = vulnrable;
}


int Player::getWeaponSlot(){
    return weaponSlot;
}
void Player::setWeaponSlot(const int newWeaponSlot){
    weaponSlot = newWeaponSlot;
}
void Player::setWeaponSlot(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
        weaponSlot = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
        weaponSlot = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
        weaponSlot = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
        weaponSlot = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
        weaponSlot = 5;
    }
}


int Player::getBodyDamage(){
    return bodyDamage;
}
void Player::setBodyDamage(const int newBodyDamage){
    bodyDamage = newBodyDamage;
}





void Player::pointToMouse(const sf::Vector2f mousePosition)
{
    sf::Vector2f direction = mousePosition - shape.getPosition();
    float angle = atan2(direction.y, direction.x);
    shape.setRotation(sf::radians(angle + (3.141/2)));
    rotateWeapons(sf::radians(angle + (3.141 / 2)));
}

void Player::playerMove(float deltatime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (this->shape.getPosition().y > 0))
    {
        shape.move({0.f,float(0-moveSpeed)* deltatime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (this->shape.getPosition().x > 0))
    {
        shape.move({ float(0-moveSpeed)* deltatime,0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (this->shape.getPosition().y < WINDOW_LENGTH))
    {
        shape.move(sf::Vector2f{ 0.f,float(moveSpeed)* deltatime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (this->shape.getPosition().x < WINDOW_WIDTH))
    {
        shape.move({ float(moveSpeed)* deltatime,0.f });
    }

    //update weapon position 
    setWeaponsPosition();
}



void Player::draw(sf::RenderWindow*& window){
   
    if (weaponSlot == 1) {
        mainWeapon.draw(window);
    }
    else if (weaponSlot == 2) {
        secondWeapon.draw(window);
    } 
    else if (weaponSlot == 3) {
        thirdWeapon.draw(window);
    }
    else if (weaponSlot == 4) {
        fourthWeapon.draw(window);
    }
    else if (weaponSlot == 5) {
        fifthWeapon.draw(window);
    }
    window->draw(this->shape);
}
void Player::setWeaponsPosition(){
    mainWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    secondWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    thirdWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    fourthWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    fifthWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
}
void Player::setWeaponSize(){
    mainWeapon.getShape().scale({ 1.f,1 });
    secondWeapon.getShape().scale({ 1.f,1.f });
    thirdWeapon.getShape().scale({ 2.f,2.f });
    fourthWeapon.getShape().scale({ 1.75,1.75 });
    fifthWeapon.getShape().scale({ 2.f,2.f });
}
void Player::rotateWeapons(sf::Angle rotation){
    mainWeapon.getShape().setRotation(rotation);
    secondWeapon.getShape().setRotation(rotation);
    thirdWeapon.getShape().setRotation(rotation);
    fourthWeapon.getShape().setRotation(rotation);
    fifthWeapon.getShape().setRotation(rotation);

}






void Player::shootGun(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (weaponSlot == 1) {
           // std::cout << "cannon 1" << std::endl;
        }
        else if (weaponSlot == 2) {
           // std::cout << "cannon 2" << std::endl;
        }
        else if (weaponSlot == 3) {
            //std::cout << "cannon 3" << std::endl;
        }
        else if (weaponSlot == 4) {
           // std::cout << "cannon 4" << std::endl;
        }
        else if (weaponSlot == 5) {
           // std::cout << "cannon 5" << std::endl;
        }
    }
}







float Player::getInvincalbeDuration(){
    return invincalbeDuration;
}
void Player::resetInvincalbeDuration(){
    invincalbeDuration = 2;
}
void Player::invincableCountDown(const float deltaTime){
    invincalbeDuration = invincalbeDuration - deltaTime;
}
