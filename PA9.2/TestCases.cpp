#include "TestCases.hpp"


bool testCases::testProjectileBecomesInactive()
{
    // place projectile outside window bounds to make it inactive
    Projectile p(3, 5.f, sf::Color::Black, { -10.f, -10.f }, { -1.f, -1.f }, 1.f);
    p.update();
    return !p.isActive();
}

bool testCases::testWeaponClassShootAddsProjectile()
{
    WeaponClass w;
    sf::Vector2f start(100.f, 100.f);
    sf::Vector2f target(200.f, 200.f);
    w.shoot(start, target, 1.f, 0.016f, 3, 5.f);
    return !w.getProjectiles().empty();
}

bool testCases::testWeaponSetPositionUpdatesShape()
{
    basicWeapon b;
    b.setObjectPosition(123.f, 234.f);
    auto pos = b.getShape().getPosition();
    return (std::abs(pos.x - 123.f) < 0.001f && std::abs(pos.y - 234.f) < 0.001f);
}

bool testCases::testBasicWeaponNoseCoordinate()
{
    basicWeapon b( -30, 15, sf::Color::Black, 300, 300);
    b.setObjectPosition(300.f, 300.f);
    b.update(); // updates nose
    auto nose = b.getNose();
    // nose should be near the weapon position (y differs by height)
    return (nose.x > 0.f && nose.y > 0.f);
}

bool testCases::testPlayerPropertiesAndInvincibility()
{
    Player p;
    p.setBodyDamage(7);
    if (p.getBodyDamage() != 7) return false;
    p.resetInvincalbeDuration();
    float before = p.getInvincalbeDuration();
    p.invincableCountDown(0.5f);
    return (p.getInvincalbeDuration() < before);
}


void testCases::runAllTests()
{
    int failed = 0;
    std::cout << "Running test cases...\n";

    if (!testProjectileBecomesInactive()) { std::cout << "testProjectileBecomesInactive FAILED\n"; ++failed; }
    else std::cout << "testProjectileBecomesInactive PASSED\n";

    if (!testWeaponClassShootAddsProjectile()) { std::cout << "testWeaponClassShootAddsProjectile FAILED\n"; ++failed; }
    else std::cout << "testWeaponClassShootAddsProjectile PASSED\n";

    if (!testWeaponSetPositionUpdatesShape()) { std::cout << "testWeaponSetPositionUpdatesShape FAILED\n"; ++failed; }
    else std::cout << "testWeaponSetPositionUpdatesShape PASSED\n";

    if (!testBasicWeaponNoseCoordinate()) { std::cout << "testBasicWeaponNoseCoordinate FAILED\n"; ++failed; }
    else std::cout << "testBasicWeaponNoseCoordinate PASSED\n";

    if (!testPlayerPropertiesAndInvincibility()) { std::cout << "testPlayerPropertiesAndInvincibility FAILED\n"; ++failed; }
    else std::cout << "testPlayerPropertiesAndInvincibility PASSED\n";

    std::cout << failed << " tests failed.\n";
}
