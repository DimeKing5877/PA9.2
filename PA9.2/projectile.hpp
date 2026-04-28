
#include "MainHeader.hpp"
#include "BasicShapes.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

class Projectile : public Shape {
private:
    sf::CircleShape bullet;
    sf::Vector2f velocity;
    bool active;

public:
    Projectile(const int newNumOfSides, const double newRad, const sf::Color& newColor, sf::Vector2f startPos, sf::Vector2f direction, float volocity) : Shape(newNumOfSides, newRad, newColor)
    {
        bullet.setRadius(newRad);
        bullet.setFillColor(newColor);
        bullet.setOrigin({ 0, 0 });
        bullet.setPosition(startPos);

        float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));

        if (length != 0)
        {
            direction.x = direction.x / length;
            direction.y = direction.y / length;
        }

        velocity = direction * volocity;
        active = true;
    }

    void update()
    {
        bullet.move(velocity);

        sf::Vector2f pos = bullet.getPosition();

        if (pos.x < 0 || pos.x > WINDOW_WIDTH || pos.y < 0 || pos.y > WINDOW_LENGTH)
        {
            active = false;
        }
    }

    void draw(sf::RenderWindow*& window)
    {
        window->draw(bullet);
    }

    bool isActive() const
    {
        return active;
    }

    sf::FloatRect getBounds() const
    {
        return bullet.getGlobalBounds();
    }
};

//weapon class
class WeaponClass
{
private:
    std::vector<Projectile> projectiles;

public:
    void shoot(sf::Vector2f startPos, sf::Vector2f targetPos, float volocity, float deltaTime, int newNumOfSides, double newRad)
    {
        sf::Vector2f direction;

        direction.x = targetPos.x - startPos.x;
        direction.y = targetPos.y - startPos.y;

        projectiles.push_back(Projectile(newNumOfSides, newRad, sf::Color::Black, startPos, direction , (volocity * deltaTime)));
    }

    void update()
    {
        for (int i = 0; i < projectiles.size(); i++)
        {
            projectiles[i].update();
        }

        projectiles.erase(
            std::remove_if(projectiles.begin(), projectiles.end(),
                [](const Projectile& projectile)
                {
                    return !projectile.isActive();
                }),
            projectiles.end()
        );
    }

    void draw(sf::RenderWindow*& window)
    {
        for (int i = 0; i < projectiles.size(); i++)
        {
            projectiles[i].draw(window);
        }
    }

    std::vector<Projectile>& getProjectiles()
    {
        return projectiles;
    }
};

//example: pewpew.shoot({ 300,300 }, { 800, 800 }, 30, time.getDeltaTime(), 1, 10);