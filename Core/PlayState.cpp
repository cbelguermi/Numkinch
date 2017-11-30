//
// Created on 07/11/2017.
//

#include "PlayState.h"
#include "../GUI/GUIConstants.h"
#include "../WorldLogic/Entities.h"
#include "../PlayerLogic/Skills.h"
#include "../WorldLogic/Trap.h"
#include "../WorldLogic/Treasure.h"
#include "../WorldLogic/Monster.h"
#include "../PlayerLogic/PlayerLogicConstants.h"
#include "../PlayerLogic/CharacterFactory.h"
#include <cstdio>
#include <random>



#define STAT_CARD_PATH_INACTIVE "./res/StatCardInactive.png"
#define STAT_CARD_PATH_ACTIVE "./res/StatCardActive.png"

PlayState::PlayState(vector<unique_ptr<Race>> players) : _inGameBg(IN_GAME_DEFAULT_BG_PATH), _playerStats(NB_PLAYERS),
                                                         _players(move(players))
{
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformIntDistribution(1, 4); // between 1 and 4 included
    int randNb = uniformIntDistribution(randomEngine);
    switch (randNb)
    {
        case 1:
            _inGameBg = Background(IN_GAME_BG_1_PATH);
            break;
        case 2:
            _inGameBg = Background(IN_GAME_BG_2_PATH);
            break;
        case 3:
            _inGameBg = Background(IN_GAME_BG_3_PATH);
            break;
        case 4:
            _inGameBg = Background(IN_GAME_BG_4_PATH);
            break;
        default:
            break;
    }
    _currentPlayer = 0;
}

void PlayState::onEnter()
{
    _inGameBg.init();

    _dungeon.generate();
    _dungeon.init();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        auto * playerIdentity = new char(60);
        sprintf(playerIdentity, "%s (%s, %s)", _players[i]->getName(), _players[i]->RaceToString(), _players[i]->ClassToString());
        auto * attack = new char(10);
        sprintf(attack, "%d / %d", _players[i]->getAttack()->getValue(), _players[i]->getAttack()->getMaxValue());
        auto * defense = new char(10);
        sprintf(defense, "%d / %d", _players[i]->getDefense()->getValue(), _players[i]->getDefense()->getMaxValue());
        auto * agility = new char(10);
        sprintf(agility, "%d / %d", _players[i]->getAgility()->getValue(), _players[i]->getAgility()->getMaxValue());
        auto * life = new char(10);
        sprintf(life, "%d / %d", _players[i]->getLife()->getValue(), _players[i]->getLife()->getMaxValue());

        _playerStats[i] = new StatCard(STAT_CARD_PATH_INACTIVE, WINDOW_WIDTH - STAT_CARD_WIDTH,
                                       350 + STAT_CARD_HEIGHT * i, STAT_CARD_WIDTH, STAT_CARD_HEIGHT, playerIdentity,
                                       attack, defense, agility, life);
        _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_ACTIVE);
        delete playerIdentity;
        delete attack;
        delete defense;
        delete agility;
        delete life;
        _playerStats[i]->init();
    }
}

void PlayState::onExit()
{
    _dungeon.cleanup();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->cleanup();
    }
    _inGameBg.cleanup();
}

void PlayState::handleEvents()
{
    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            _dungeon.handleEvent(& event);
        }
    }
}

void PlayState::update()
{
    _dungeon.update();
}

void PlayState::updateCurrentPlayer(Room * room, bool accept)
{
    if (room->getType() == MONSTER && accept)
    {
        auto monster = (Monster*) room;
        while (monster->getLife() > 0 && _players[_currentPlayer]->getLife()->getValue() > 0)
        {
            int pAttackValue = _players[_currentPlayer]->getAttack()->getValue() - monster->getDefense();
            if (pAttackValue < 0) {pAttackValue = 0;}
            monster->alterLife(- pAttackValue );
            printf("Player attack : %d\nMonster have %d life points.\n", pAttackValue, monster->getLife() );
            if (monster->getLife() > 0)
            {
                random_device r;
                default_random_engine randomEngine(r());
                uniform_int_distribution<int> uniformIntDistribution(1, 100); // between 1 and 4 included
                int randNb = uniformIntDistribution(randomEngine);

                if (randNb > _players[_currentPlayer]->getAgility()->getValue())
                {
                    int mAttackValue = monster->getAttack() - _players[_currentPlayer]->getDefense()->getValue();
                    if (mAttackValue < 0) {mAttackValue = 0;}
                    _players[_currentPlayer]->getLife()->alterPoints(- mAttackValue);
                    printf("Monster attack : %d\nPlayer have %d life points.\n", mAttackValue, _players[_currentPlayer]->getLife()->getValue());
                } else
                {
                    printf("Dodge !!\n");
                }
            }
        }
        if (monster->getLife() <= 0)
        {
            random_device r;
            default_random_engine randomEngine(r());
            uniform_int_distribution<int> uniformIntDistribution(1, 3); // between 1 and 4 included
            int randNb = uniformIntDistribution(randomEngine);
            switch (randNb)
            {
                case 1:
                    _players[_currentPlayer]->getAttack()->alterPoints(ATTACK_INCREASE);
                    break;
                case 2:
                    _players[_currentPlayer]->getDefense()->alterPoints(DEFENSE_INCREASE);
                    break;
                case 3:
                    _players[_currentPlayer]->getAgility()->alterPoints(AGILITY_INCREASE);
                    break;
                default:
                    break;
            }
            if (monster->isBoss())
            {
                printf("%s WINS !!\n", _players[_currentPlayer]->getName());
                exit(0);
            }
        }
    }
    else if (room->getType() == MONSTER && !accept)
    {
        random_device r;
        default_random_engine randomEngine(r());
        uniform_int_distribution<int> uniformIntDistribution(1, 4); // between 1 and 4 included
        int randNb = uniformIntDistribution(randomEngine);

        if (randNb == 1)
        {
            _players[_currentPlayer]->getLife()->alterPoints(- (_players[_currentPlayer]->getLife()->getValue()/2));
        }
    }
    else if (room->getType() == TRAP)
    {
        auto * trap = (Trap *) room;
        switch (room->getTargetSkill())
        {
            case ATTACK:
                _players[_currentPlayer]->getAttack()->alterPoints(- trap->getDamage());
                break;
            case DEFENSE:
                _players[_currentPlayer]->getDefense()->alterPoints(- trap->getDamage());
                break;
            case AGILITY:
                _players[_currentPlayer]->getAgility()->alterPoints(- trap->getDamage());
                break;
            case LIFE:
                _players[_currentPlayer]->getLife()->alterPoints(- trap->getDamage());
                break;
            default:
                break;
        }
    }
    else if (room->getType() == TREASURE)
    {
        auto * treasure = (Treasure *) room;
        switch (room->getTargetSkill())
        {
            case ATTACK:
                _players[_currentPlayer]->getAttack()->alterPoints(treasure->getBonus());
                break;
            case DEFENSE:
                _players[_currentPlayer]->getDefense()->alterPoints(treasure->getBonus());
                break;
            case AGILITY:
                _players[_currentPlayer]->getAgility()->alterPoints(treasure->getBonus());
                break;
            case LIFE:
                _players[_currentPlayer]->getLife()->alterPoints(treasure->getBonus());
                break;
            default:
                break;
        }
    }

    if (_players[_currentPlayer]->getLife()->getValue() <= 0)
    {
        Race* newPlayer = CharacterFactory::get().createCharacter(_players[_currentPlayer]->getRace(), _players[_currentPlayer]->getClass(), _players[_currentPlayer]->getName());
        _players[_currentPlayer].reset(newPlayer);
    } else {
        _players[_currentPlayer]->getLife()->alterPoints(LIFE_INCREASE);
    }



    auto * attack = new char(10);
    sprintf(attack, "%d / %d", _players[_currentPlayer]->getAttack()->getValue(),
            _players[_currentPlayer]->getAttack()->getMaxValue());
    auto * defense = new char(10);
    sprintf(defense, "%d / %d", _players[_currentPlayer]->getDefense()->getValue(),
            _players[_currentPlayer]->getDefense()->getMaxValue());
    auto * agility = new char(10);
    sprintf(agility, "%d / %d", _players[_currentPlayer]->getAgility()->getValue(),
            _players[_currentPlayer]->getAgility()->getMaxValue());
    auto * life = new char(10);
    sprintf(life, "%d / %d", _players[_currentPlayer]->getLife()->getValue(),
            _players[_currentPlayer]->getLife()->getMaxValue());

    _playerStats[_currentPlayer]->update(attack, defense, agility, life);
    delete attack;
    delete defense;
    delete agility;
    delete life;

    _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_INACTIVE);
    _currentPlayer = (_currentPlayer + 1) % NB_PLAYERS;
    _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_ACTIVE);
    printf("Player changed: now %d\n", _currentPlayer);
}

void PlayState::render()
{
    _inGameBg.render();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->render();
    }
    _dungeon.render();
}

PlayState::~PlayState()
{
    for (auto statCard : _playerStats)
    {
        delete statCard;
    }
}
