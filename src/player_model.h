/*!
 * \file player_model.h
 * \class PlayerModel
 * \brief Partie modele du joueur, contient l'ensemble des calculs le concernant
 * \author Jérémie
 */

#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <iostream>
#include "movable.h"
#include "utils.h"
#include "timer.h"
#include "effect.h"
#include <list>


class PlayerModel : public Movable
{
public:
    /*!
     * \brief constructeur de PlayerModel
     * \param string nom du PlayerModel
     */
    PlayerModel();
    ~PlayerModel();

    unsigned short getLife() const;
    void setLife(unsigned short value);

    std::pair<int, int> getVelocity() const;
    void setVelocity(std::pair<int, int> v);

    /*!
     * \brief eventHandler s'occupe de la gestion des déplacement à droite et à gauche en incrémentant la vélocité
     */
    void eventHandler();

    /*!
     * \brief chekCollision verifie les collisions avec l'environnement(sol, limite pour avancement du chunk..).
     */
    void checkCollision();

    /*!
     * \brief applyForces applique la velocité et la gravité au playerModel à chaque tour de boucle
     */
    void applyForces();

    bool leftPressed, rightPressed, spacePressed, shiftPressed;

    std::pair<float, float> getGravity() const;
    void setGravity(const std::pair<float, float> &value);

    bool needMoveBackground() const;
    void setMoveBackground(bool value);
    int getSavedVelocityX() const;

    void setVelocityX(float value);
    void setVelocityY(float value);

    bool isDead() const;

    int getDeadLine() const;
    void setDeadLine(int value);

    void addEffect(Effect *effect, unsigned long time_effect);
    void processEffects();

    void setAttractCoins(bool value);

    bool getAttractCoins() const;

private:
    unsigned short life;/*!< Utilisé pour stocker la vie du joueur*/

    float walk_acc;/*!< Vitesse d'accéleration du playerModel losqu'il marche*/
    float run_acc;/*!< Vitesse d'accéleration du playerModel lorqu'il court*/
    float max_walk;/*!< Vitesse maximale du playerModel en mode marche*/
    float max_run;/*!< Vitesse maximale du playerModel en mode course*/
    float jump_acc;/*!< Vitesse d'accéleration du playerModel pour le saut*/
    float max_fall;/*!< Vitesse maximale du playerModel pour le saut*/

    float decelaration;/*!< Valeur qui assure la deceleration du playerModel*/

    int jumpframe;/*!< Nombre de frame max durant lequel le joueur peut sauter*/
    int jump_counter;/*!< Permet de compter le nombre de frame afin de ne pas depasser la valeur de jumpframe*/

    std::pair<float, float> gravity;/*!< pair representant une gravité(non réaliste) qui s'applique à chaque tour de boucle au playerModel*/
    std::pair<float, float> velocity;/*!< pair representant la velocité du joueur, c'est elle qui incrémente la position du playerModel a chaque tour de boucle et permet donc le déplacement*/

    bool move_background; /*!< utilisé lorsque le joueur essaye d'aller au delà de la limite imposée afin de faire "avancer" le background */
    int dead_line; /*!< Utilisé pour savoir où se situe le feu et tuer le joueur si celui-ci est dedans */

    std::vector<Effect *> active_effects;
    std::vector<Timer> timer_effects; /*!< Timer pour chacun des effets */

    bool attractCoins;
};
/*!
 * \brief Surchage de l'opérateur += de pair afin d'additionner plus facilement les pairs que nous utilisons
 * \param les 2 pairs que l'on veut additionner
 */
std::pair<float, float> operator+=(std::pair<float, float>& a, const std::pair<float, float>& b);

#endif // PLAYERMODEL_H
