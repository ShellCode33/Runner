#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ModelsTest

#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <iostream>

#include "game_model.h"
#include "chunk_model.h"
#include "saw_model.h"
#include "timer.h"

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
}


