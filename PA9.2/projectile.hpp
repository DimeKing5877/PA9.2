
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
    Projectile(sf::Vector2f startPos, sf::Vector2f direction)
    {
        bullet.setRadius(6.f);
        bullet.setFillColor(sf::Color::Yellow);
        bullet.setOrigin({ 6.f, 6.f });
        bullet.setPosition(startPos);

        float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));

        if (length != 0)
        {
            direction.x = direction.x / length;
            direction.y = direction.y / length;
        }

        velocity = direction * 10.f;
        active = true;
    }

    void update()
    {
        bullet.move(velocity);

        sf::Vector2f pos = bullet.getPosition();

        if (pos.x < 0 || pos.x > 1000 || pos.y < 0 || pos.y > 800)
        {
            active = false;
        }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(bullet);
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

class Weapon
{
private:
    std::vector<Projectile> projectiles;

public:
    void shoot(sf::Vector2f startPos, sf::Vector2f targetPos)
    {
        sf::Vector2f direction;

        direction.x = targetPos.x - startPos.x;
        direction.y = targetPos.y - startPos.y;

        projectiles.push_back(Projectile(startPos, direction));
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

    void draw(sf::RenderWindow& window)
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