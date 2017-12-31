/*!
 * \file game_model.h
 * \class GameModel
 * \brief Classe chargée de répartir les taches, de gérer le fonctionnement logique du jeu
 * \author J3ry, ShellCode
 */

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "utils.h"
#include "timer.h"
#include "chunk.h"
#include "entity.h"
#include "chunk_saw.h"
#include "chunk_special.h"
#include "chunk_spike.h"
#include "police.h"
#include "platform.h"

class GameModel
{
private:
    unsigned long score;
    unsigned long bonus_score; /*!< Pièces ou autre... */
    int difficulty_level; /*!< Utilisé pour incrémenter fire_speed en fonction de la difficulté choisie dans les options */
    int fire_offset; /*!< correspond à l'avancement du feu dans la partie */
    int fire_speed; /*!< Nombre de pixel d'avancement du feu */
    int time_per_move; /*!< Vitesse d'approche du feu, évolue avec le temps */
    Timer game_begin; /*!< Mesure le temps depuis le début du jeu afin de calculer le score */
    Timer timer; /*!< Timer utilisé pour l'avancement du feu */
    Timer difficulty_timer; /*!< Timer utilisé pour la vitesse du jeu au fil du temps */

    Player &player;
    std::string pseudo; /*! Pseudo utilisé lors du gameover */
    std::list<Chunk *> &chunks;
    std::list<Entity *> &entities;

    /*!
     * \brief randomChunk
     * \param pos_x_default
     * \return un Chunk aléatoire
     */
    Chunk *randomChunk(int pos_x_default) const;
    Police *police;


public:
    GameModel(Player &player, std::list<Chunk *> &chunks, std::list<Entity *> &entities);
    ~GameModel();

    void update();
    unsigned long getScore() const;
    int getFireOffset() const;
    void setFireOffset(int value);

    /*!
     * \brief getVisibleChunks
     * \return une liste de chunks qui sont actuellement visibles à l'ecran
     */
    std::list<Chunk *> getVisibleChunks() const;
    void setScore(unsigned long value);

    std::string getPseudo() const;
    void setPseudo(const std::string &value);
    Police *getPolice() const;
    void addBonusScore(unsigned long value);
    Player &getPlayer() const;
};

#endif // GAMEMODEL_H
