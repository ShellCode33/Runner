#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ModelsTest

#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <iostream>

#include "game_model.h"
#include "chunk_model.h"
#include "saw_model.h"
#include "timer.h"
#include "missile_model.h"
#include "coin_model.h"

using namespace std;


BOOST_AUTO_TEST_CASE(ChunkModelTest)
{
    ChunkModel model(0);
    SawModel *saw = new SawModel(0, 0, 0, 0); //Le destructeur de ChunkModel est chargé de delete
    SawModel *saw2 = new SawModel(0, 0, 0, 0);
    SawModel *saw3 = new SawModel(0, 0, 0, 0);

    BOOST_CHECK(model.getObstacles().size() == 0);

    model.addObstacle(saw);
    BOOST_CHECK(model.getObstacles().size() == 1);

    model.addObstacle(saw2);
    BOOST_CHECK(model.getObstacles().size() == 2);

    model.addObstacle(saw3);
    BOOST_CHECK(model.getObstacles().size() == 3);
}

BOOST_AUTO_TEST_CASE(GameModelTest)
{
    Player player;
    list<Chunk *> chunks;
    list<Entity *> entities;
    GameModel model(player, chunks, entities);

    //Le score évolue t'il avec le temps ?
    int last_score = model.getScore();
    //Le feu avance t'il correctement ?
    int last_fire_offset = model.getFireOffset();

    int i;
    for(i = 0; i < 10; i++)
    {
        cout << "score: " << last_score << endl;
        model.update();

        BOOST_CHECK(last_score <= model.getScore());
        last_score = model.getScore();

        BOOST_CHECK(last_fire_offset <= model.getFireOffset());
        last_fire_offset = model.getFireOffset();

        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }

    list<Chunk *> visible_chunks = model.getVisibleChunks();
    list<Chunk *>::const_iterator it1 = chunks.begin();
    list<Chunk *>::const_iterator it2 = visible_chunks.begin();

    for(i = 0; i < visible_chunks.size(); i++)
        BOOST_CHECK(*it1++ == *it2++);
}

BOOST_AUTO_TEST_CASE(PlayerModelTest)
{
    //Tests sur la vie du joueur

    PlayerModel player;
    cout << "Life: " << player.getLife() << endl;
    cout << "isDead: " << player.isDead() << endl;
    BOOST_CHECK(!player.isDead());
    player.setLife(1);

    cout << "Life: " << player.getLife() << endl;
    cout << "isDead: " << player.isDead() << endl;
    BOOST_CHECK(!player.isDead());
    player.setLife(0);

    cout << "Life: " << player.getLife() << endl;
    cout << "isDead: " << player.isDead() << endl;
    BOOST_CHECK(player.isDead());
    player.setLife(-1);

    cout << "Life: " << player.getLife() << endl;
    cout << "isDead: " << player.isDead() << endl;
    BOOST_CHECK(player.isDead());

    //Tests sur les mouvements du playermodel

    player.setPosition(make_pair(700., VIEW_HEIGHT - player.getHeight() - GROUND_DEFAULT));

    float last_position_x = player.getPosition().first;
    float last_position_y = player.getPosition().second;

    cout << "\nPosition initiale(x, y) : " << player.getPosition().first << " : " << player.getPosition().second << endl;

    //**Test du déplacement à droite**//

    player.rightPressed = true;

    cout << "\nTest du deplacement a droite :\n\n";

    for(unsigned int i = 0; i < 10; i++)
    {
        player.applyForces();
        player.eventHandler();
        player.checkCollision();
        cout << "Position après " << i+1 << " tours de boucle : " << player.getPosition().first << " : " << player.getPosition().second << endl;
    }
    BOOST_CHECK(player.getPosition().second > last_position_x);

    player.rightPressed = false;

    //**Test du déplacement à gauche**//

    last_position_x = player.getPosition().first;

    player.leftPressed = true;

    cout << "\nTest du deplacement a gauche :\n\n";

    for(unsigned int i = 0; i < 10; i++)
    {
        player.applyForces();
        player.eventHandler();
        player.checkCollision();
        cout << "Position après " << i+1 << " tours de boucle : " << player.getPosition().first << " : " << player.getPosition().second << endl;
    }
    BOOST_CHECK(player.getPosition().first < last_position_x);

    player.leftPressed = false;

        //**Test du saut**//

    player.spacePressed = true;

    cout << "\nTest du saut :\n\n";

    for(unsigned int i = 0; i < 26; i++)
    {
        player.applyForces();
        player.eventHandler();
        player.checkCollision();
        cout << "Position après " << i+1 << " tours de boucle : " << player.getPosition().first << " : " << player.getPosition().second << endl;
    }
    BOOST_CHECK(player.getPosition().second < last_position_y);

    player.spacePressed = false;

        //**Test de l'application de la gravite après le saut**//

    last_position_y = player.getPosition().second;

    cout << "\nTest de l'application de la gravite après le saut\n\n";

    for(unsigned int i = 0; i < 10; i++)
    {
        player.applyForces();
        player.checkCollision();
        cout << "Position après " << i+1 << " tours de boucle : " << player.getPosition().first << " : " << player.getPosition().second << endl;
    }

    BOOST_CHECK(player.getPosition().second > last_position_y);
}

BOOST_AUTO_TEST_CASE(CollisionTest)
{
    //Initialisation du player et de son rectangle qui le contient
    PlayerModel player_model;

    AABB playerRect;

    playerRect.x = player_model.getX();
    playerRect.y = player_model.getY();
    playerRect.w = player_model.getWidth();
    playerRect.h = player_model.getHeight();

    //Initialisation d'un rectangle quelconque pour tester la collision rectangle/rectangle (il servira aussi de rectangle entourant le cercle, car nous en utilisons un pour optimiser les calculs dans la collision cercle et rectangle
    AABB rect;

    rect.x = VIEW_WIDTH / 6; // on l'initialise a ce x car par défaut le playermodel est a ce x
    rect.y = 0;
    rect.w = 50;
    rect.h = 50;

    BOOST_CHECK(Collision::AABBintersectAABB(playerRect, rect));

    //On change la position du rectangle pour tester si la collision n'est pas effective lorsque celui-ci n'est pas en collision avec avec le player

    rect.x = 100;
    rect.y = 100;

    BOOST_CHECK(!Collision::AABBintersectAABB(playerRect, rect));

    //Initialisation d'un cercle quelconque pour tester la collision cercle / rectangle
    Circle circle;

    rect.x = VIEW_WIDTH / 6; // on l'initialise a ce x car par défaut le playermodel est a ce x
    rect.y = 0;

    circle.radius = rect.w / 2;
    circle.x = rect.x + circle.radius;
    circle.y = rect.y + circle.radius;

    BOOST_CHECK(Collision::AABBintersectCircle(rect, playerRect, circle));

    //second test lorsque le cercle n'est plus en collision avec le rectangle
    rect.x = 100;
    rect.y = 100;

    circle.x = rect.x + circle.radius;
    circle.y = rect.y + circle.radius;

    BOOST_CHECK(!Collision::AABBintersectCircle(rect, playerRect, circle));
}


BOOST_AUTO_TEST_CASE(TimerTest)
{
    Timer timer(1000);
    timer.begin();
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    BOOST_CHECK(timer.isFinish());

    Timer timer2;
    timer2.begin();
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    BOOST_CHECK(timer2.getDuration() > 900 && timer2.getDuration() < 1100);
}

BOOST_AUTO_TEST_CASE(MissileModelTest)
{
    PlayerModel player;
    player.setPosition(make_pair(0, 0));

    MissileModel missile(player);
    missile.setPosition(make_pair(MISSILE_DETECTION - 1, 0));

    cout << "missile x: " << missile.getPosition().first << endl;
    missile.update();
    cout << "missile x: " << missile.getPosition().first << endl;
    BOOST_CHECK(missile.getPosition().first < MISSILE_DETECTION - 1);

    player.setPosition(make_pair(0, MISSILE_DETECTION - 1));
    missile.setPosition(make_pair(0, 0));

    cout << "missile y: " << missile.getPosition().second << endl;
    missile.update();
    cout << "missile y: " << missile.getPosition().second << endl;
    BOOST_CHECK(missile.getPosition().second > 0);
}

BOOST_AUTO_TEST_CASE(CoinModelTest)
{
    Player player;
    list<Chunk *> chunks;
    list<Entity *> entities;
    GameModel game(player, chunks, entities);

    CoinModel coin(0, 0, 0, 0);
    coin.action(game);
    BOOST_CHECK(game.getScore() == 100);
}
