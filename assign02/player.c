// Implements a player using the function described in player.h.
//
// By Zexin Lin(z5217017)
// Written in October 2018
//
// Elizabeth Willer (Tue17-kora)

#include "Card.h"
#include "Game.h"
#include "player.h"

#include <assert.h>
#include <stdlib.h>
#include <err.h>

static Card findValueInHand(Game game, value v);

// This function is to be implemented by the AI.
// It will be called when the player can take an action on their turn.
// The function is called repeatedly until they make the action
// END_TURN.
// If the player's turn is skipped, this funciton is not called for that
// player.
playerMove decideMove(Game game){
    playerMove move;
    move.action = END_TURN;
    
    if (isValidMove(game, move)) {
        return move;
    }
    
    else {
        if (getActiveDrawTwos(game) != 0) {
            if (findValueInHand(game, DRAW_TWO) != NULL) {
                move.card = findValueInHand(game, DRAW_TWO);
                move.action = PLAY_CARD;
            }
            else {
                move.action = DRAW_CARD;            
            }
            if (isValidMove(game, move)) {
                return move;
            }
        }
        if (findValueInHand(game, D) != NULL) {
            move.card = findValueInHand(game, D);
            move.action = PLAY_CARD;
            move.nextColor = getCurrentColor(game);
            if (isValidMove(game, move)) {
                return move;
            }
        }
        else if (findValueInHand(game, A) != NULL) {
            move.card = findValueInHand(game, A);
            move.action = PLAY_CARD;
            if (isValidMove(game, move)) {
                return move;
            } 
        }
        else {
            int i = 0;
            Card card = handCard(game, i);
            while (card != NULL){
                move.card = card;
                move.action = PLAY_CARD;
                if (isValidMove(game, move)){
                    return move;
                }
                i++;
                card = handCard(game, i);
            }
        }
    }
    move.action = DRAW_CARD;
    return move;
}


/*   Helper functions below ... 
*/

static Card findValueInHand(Game game, value v){
    int i = 0;
    Card card = handCard(game, i);
    while (card != NULL){
        if (cardValue(card) == v){
            return card;
        }
        i++;
        card = handCard(game, i);
    }
    return NULL;
}

