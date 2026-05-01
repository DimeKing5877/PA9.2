#pragma once
#include <iostream>
#include "MainHeader.hpp"
#include "projectile.hpp"
#include "WeaponEntityClass.hpp"
#include "Player.hpp"

// Run all test cases and return number of failed tests
class testCases {
public:
	void runAllTests();
private:
	bool testProjectileBecomesInactive();
	bool testWeaponClassShootAddsProjectile();
	bool testWeaponSetPositionUpdatesShape();
	bool testBasicWeaponNoseCoordinate();
	bool testPlayerPropertiesAndInvincibility();
};
