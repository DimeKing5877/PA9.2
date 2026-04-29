#include "Game.hpp"
#include "BackGroundClass.hpp"

void Game::playerIsDamaged() {
    if (player.checkHit(grunt.shape.getGlobalBounds())) {//code for the grunt that exists
        player.updateHealth(1);//gunt.Damage()

        if (player.isDead()) {
            window->close();
        }
        else {
            player.setVulnrabile(false);
        }
        grunt.updateHealth(player.getBodyDamage());
        if (grunt.isDead()) {//enemy is dead
            grunt.setMoveSpeed(0);
        }

    }
    /*loop through all enemies and projectiles
    while () {//not end of enemy list
        //get one enemy
        if (player.vulnrable()) {//player is vulnrable to damage
            //hit detection for player
            if (player.checkHit(grunt.shape.getGlobalBounds())) {
                //player.updateHealth();//gunt.Damage()
                if (player.isDead()) {
                    //end game
                }
                else{
                    player.setVulnrabile(false);
                }
            }
            //get first projectile from enemy//not needed of enemys do not shoot
            while () {
                if (player.vulnrable()) {//player is vulnrable to damage
                    if (player.checkHit(.shape.getGlobalBounds())) {
                        //player.updateHealth();//projectile.Damage()
                        if (player.isDead()) {
                            //end game
                        }
                        else{
                            player.setVulnrable(false);
                        }
                    }
                }
                //loop till end of projectiles
            }
        }
        //loop till next enemy
    }
    */
}

void Game::damagedAnEnemy() {
    /*
    //get the projectiles from player
    while () {//not end of player projectile list
        while () {//not end of enemy list
            if () {//projectile hit by enemy
                //delete player projectile
                //update enemy health
                if (.isDead()) {//enemy is dead
                    //delete enemy
                }
            }
        }
       //get next projectile
    }

    */
}

void Game::generateEnemy()
{
}
