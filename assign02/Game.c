// The implementation for functions in Game.h
//
// By Zexin Lin(z5217017)
// Written in October 2018
//
// Elizabeth Willer (Tue17-kora)

#include "Card.h"
#include "Game.h"

#include <assert.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>

#define STARTING_HAND_SIZE 7

static struct node *lastCard(struct node *head);
static struct node *addToLast(struct node *head, Card card);
static struct node *addToFront(struct node *head, Card card);
static struct node *createDeck(struct node *head, int deckSize, value values[], color colors[], suit suits[]);
static void createHands(Game game);
static Card removeTopDeckCard(Game game);
static struct node *removeHandCard(Game game, Card card);
static void destroyCardPile(struct node *head);
static int getNumOfCards(struct node *head);
static int isValidCard(Game game, Card card);
static int isCardInHand(Game game, Card card);
static struct node *turnDiscardToDraw(Game game);
static struct node *reverseDiscard(Game game);

typedef struct node {
    struct node *next;
    Card card;
} node;

typedef struct _game {  
    struct node *initial_deck;
    struct node *deck;
    struct node *discard_pile;
    struct node *hand[NUM_PLAYERS];
    int deck_size;
    int turn_num;
    int current_player;
    int previous_player;
    int top_discard_pile_turn_num;
    int active_draw_two_num;
    int card_draw_in_one_turn;
    int card_played_in_one_turn;
    int current_turn_move_num;
    int times_of_skip;
    color current_color;
    value current_value;
    suit current_suit;
    Card first_discard;    
} game;
// Create a new game engine.
//
// This creates a game with a deck of the given size
// and the value, color, and suit of each card to be taken from
// each of the arrays in order.
//
// Your game will always have 4 players. Each player starts with a hand
// of 7 cards. The first card from the deck is given to player 0, the
// second to player 1, the third to player 2, the fourth to player 3,
// the fifth to player 0, and so on until each player has 7 cards.
Game newGame(int deckSize, value values[], color colors[], suit suits[]) {
    Game game = malloc(sizeof(struct _game));    
    if (game == NULL) {
        err(EXIT_FAILURE, "Could not allocate memory for Game");
    }    
    game->deck_size = deckSize;
    game->turn_num = 0;
    game->current_player = 0;
    game->previous_player = -1;
    game->top_discard_pile_turn_num = -1;
    game->current_turn_move_num = 0;
    game->card_draw_in_one_turn = 0;
    game->card_played_in_one_turn = 0;
    game->times_of_skip = 0;
    // Create linked list of deck and initial deck
    game->initial_deck = NULL;
    game->deck = NULL;
    game->initial_deck = createDeck(game->initial_deck, deckSize, values, colors, suits);
    game->deck = createDeck(game->deck, deckSize, values, colors, suits);        
    // Create linked list for each player 
    createHands(game);        
    // Create linked list for discard pile
    game->discard_pile = NULL; 
    game->first_discard = removeTopDeckCard(game);    
    game->discard_pile = addToFront(game->discard_pile, game->first_discard);
    game->current_color = cardColor(game->first_discard);
    game->current_value = cardValue(game->first_discard);
    game->current_suit = cardSuit(game->first_discard);
    
    if (game->current_value == DRAW_TWO) {    
        game->active_draw_two_num = 1;
    }
    else {
        game->active_draw_two_num = 0;
    }
    return game;
}

// Destroy an existing game.
//
// This should free all existing memory used in the game including
// allocations for players and cards.
void destroyGame(Game game) {    
    destroyCardPile(game->deck);
    destroyCardPile(game->initial_deck);
    destroyCardPile(game->discard_pile);
    
    for (int player_num = 0; player_num < NUM_PLAYERS; player_num++) {
        destroyCardPile(game->hand[player_num]);
    }
    free(game);
}

// The following functions can be used by players to discover
// information about the state of the game.

// Get the number of cards that were in the initial deck.
int numCards(Game game) {

    return game->deck_size;
}

// Get the number of cards in the initial deck of a particular
// suit.
int numOfSuit(Game game, suit suit) {    
    int suit_count = 0;
    for (struct node *n = game->initial_deck; n != NULL; n = n->next) {
        if (cardSuit(n->card) == suit) {
            suit_count++;
        }
    }    
    return suit_count;
}

// Get the number of cards in the initial deck of a particular color.
int numOfColor(Game game, color color) {    
    int color_count = 0;
    for (struct node *n = game->initial_deck; n != NULL; n = n->next) {
        if (cardColor(n->card) == color) {
            color_count++;
        }
    }   
    return color_count;
}

// Get the number of cards in the initial deck of a particular value.
int numOfValue(Game game, value value) {    
    int value_count = 0;
    for (struct node *n = game->initial_deck; n != NULL; n = n->next) {
        if (cardValue(n->card) == value) {
            value_count++;
        }
    }    
    return value_count;    
}

// Get the number of the player whose turn it is.
int currentPlayer(Game game) {
        
    return game->current_player;
}

// Get the current turn number.
//
// The turn number increases after a player ends their turn.
// The turn number should start at 0 once the game has started.
int currentTurn(Game game) {
    
    return game->turn_num;
}

// Get the card that is on the top of the discard pile.
Card topDiscard(Game game) {

    return game->discard_pile->card;
}

// This function returns the number of turns that have occurred in the
// game so far including the current turn.
// (i.e. on turn 0 of the game, this should return 1, as there has been
//       1 turn so far including the current turn.)
int numTurns(Game game) { 
    
    return currentTurn(game) + 1;
}

// Get the number of moves (actions) that happened on the current turn.
//
// A turn may consist of multiple moves (actions) such as drawing cards,
// playing cards, and ending the turn.
int currentTurnMoves(Game game) {
   
    return game->current_turn_move_num;
}


// Get the number of consecutive cards with value "2" at the top of the 
// discard pile.
// If the value of the top of the discard pile is not "2", the function will 
// return zero. 
int getNumberOfTwoCardsAtTop(Game game) {          
    int num_of_two = 0;
    struct node *n = game->discard_pile;
    while (n != NULL && cardValue(n->card) == DRAW_TWO) {
        num_of_two++;
        n = n->next;
    }    
    return num_of_two;
}


// If the last player played a card with value "D" and declared a color, 
// the following function returns that  declared color as the current color. 
// For all other cases, the function returns the color of the card at 
// the top of the discard pile. 
int getCurrentColor(Game game) {
    
    return game->current_color;
}

// The function returns the player who played the previous turn.
// For example, if player 1 plays "A" in turn 12, player 3 will 
// play next turn 13. During turn 13, the following function will 
// return 1 (for player 1 who played the previous turn 12).
// If the current turn is the first turn (turn 0), the function should 
// return -1.
int getPreviousTurnPlayer(Game game) {

    return game->previous_player;
}


// Get the turn number that played the card that is on the top of 
// the discard pile.
int getTopDiscardTurnNumber(Game game) {

    return game->top_discard_pile_turn_num;
}

// Get the number of "active" cards with value "2" at the top of the 
// discard pile. 
// For example, say in turn-5 player-1 plays "2", as a result of this, 
// the function should return 1. Let's say in turn-6 player-2 
// draws two cards and is unable to play a card. 
// At the start of turn-7, the function should return zero.
// If the value of the top of the discard pile is not "2", the function
// should return zero.
int getActiveDrawTwos(Game game) {
    
    return game->active_draw_two_num;
}

// Get the number of cards in the current player's hand.
int handCardCount(Game game) {    

    return getNumOfCards(game->hand[game->current_player]);
}

// View a card from the current player's own hand.
//
// The player should not need to free() this card,
// so you should not allocate or clone an existing card
// but give a reference to an existing card.
Card handCard(Game game, int card) {
    
    return getHandCard(game, game->current_player, card);
}

// Check if a given move is valid.
//
// If the last player played a 2 (DRAW_TWO),
// the next player must either play a 2
// or draw 2 cards.

// If the last player has NOT played a 2, 
// the player must play a card that is either a ZERO
// or that has the same color, value, or suit as the card on the top
// of the discard pile (adjust color for a case where the 
//   previous player has played a "D").
//
// If the player plays an "A", the next player's turn is skipped.
// If the player plays a "D", they must also state which color
// the next player's discarded card should be.
//
// A player can only play cards from their hand.
// A player may choose to draw a card instead of discarding a card.
// A player must draw a card if they are unable to discard a card.
//
// This check should verify that:
// * If a card is played, that card is from the player's hand, and matches 
//   the top card on the discard pile (adjust color for a case where the 
//   previous player has played a "D"), AND the player has not already
//   played a card during their turn.
// * If a DRAW_TWO was played, the player drew the appropriate number of cards.
// * If the player draws a card, either they have not yet drawn a card
//   during this turn OR a DRAW_TWO was played in the previous turn,
//   AND the player has not yet drawn the required number of cards.
//
// * The player has either played at least one card, or drawn at least
//   one card, before playing the END_TURN action.   

int isValidMove(Game game, playerMove move) {
    if (move.action == PLAY_CARD) {
        if (isCardInHand(game, move.card)) { 
            if (game->card_played_in_one_turn < 1) {
                if (isValidCard(game, move.card) &&
                    game->active_draw_two_num == 0) {
                    return 1;
                }
                if (game->active_draw_two_num != 0 && 
                    cardValue(move.card) == DRAW_TWO) {
                    return 1;
                }
            }
        }
    }
    if (move.action == DRAW_CARD) {
        if (game->current_value == DRAW_TWO) {
            if (game->card_draw_in_one_turn < game->active_draw_two_num * 2) {               
                return 1;
            }
        }
        else {
            if (game->card_draw_in_one_turn < 1) {
                return 1;
            }            
        }
    }
    if (move.action == END_TURN) {
        if (game->card_played_in_one_turn == 1) {            
            return 1;
        }
        else if (game->current_value != DRAW_TWO 
                 && game->card_draw_in_one_turn == 1) {
            return 1;         
        }
        else if(game->card_draw_in_one_turn != 0
                && game->card_draw_in_one_turn == 
                game->active_draw_two_num * 2) {
            return 1;
        }    
    }
    return 0;
}

// Play the given action for the current player
//
// If the player makes the END_TURN move, their turn ends,
// and it becomes the turn of the next player.
//
// This should _not_ be called by the player AI.
void playMove(Game game, playerMove move) {        
        if (move.action == DRAW_CARD) {            
            Card top = removeTopDeckCard(game);
            game->hand[game->current_player] = addToLast(game->hand[game->current_player], top);
            if (game->deck == NULL) {                
                game->deck = turnDiscardToDraw(game);
            }            
            game->card_draw_in_one_turn++;
            game->current_turn_move_num++;
        }
        if (move.action == PLAY_CARD) {        
            game->top_discard_pile_turn_num = game->turn_num;
            game->current_turn_move_num++;
            game->card_played_in_one_turn++;
            game->hand[game->current_player] = removeHandCard(game, move.card);
            game->discard_pile = addToFront(game->discard_pile, move.card); 
            game->current_suit = cardSuit(move.card);
            game->current_value = cardValue(move.card);           
            if (cardValue(move.card) == DRAW_TWO) {
                game->active_draw_two_num++;
            }
            if (cardValue(move.card) == D) {
                game->current_color = move.nextColor;
            }
            else {
                game->current_color = cardColor(move.card);
            } 
            if (cardValue(move.card) == A) {
                game->times_of_skip = 1;
            }                   
        }
        if (move.action == END_TURN) {
            if (game->card_draw_in_one_turn == 
                game->active_draw_two_num * 2) {
                game->active_draw_two_num = 0;    
            }
            
            if (game->current_value == A && 
                game->times_of_skip == 1) {
                game->previous_player = game->current_player;
                game->current_player = (game->current_player + 2) % NUM_PLAYERS;
                game->times_of_skip = 0;
            }
            else {
                game->previous_player = game->current_player;
                game->current_player = (game->current_player + 1) % NUM_PLAYERS;
            }
            game->turn_num++;
            game->current_turn_move_num = 0;
            game->card_played_in_one_turn = 0;
            game->card_draw_in_one_turn = 0;
        }
}

// Check the game winner.
//
// Returns NOT_FINISHED if the game has not yet finished,
// 0-3, representing which player has won the game, or
// NO_WINNER if the game has ended but there was no winner.
int gameWinner(Game game) {
    if (game->deck == NULL && game->discard_pile == NULL) {
        return NO_WINNER;
    }
    int player_num = 0;
    while (player_num < NUM_PLAYERS) {
        if (playerCardCount(game, player_num) == 0) {
            return player_num;
        }
        player_num++;
    }
    return NOT_FINISHED;
}

// Get nth card from the deck, n=0 means top card from deck
Card getDeckCard (Game game, int n) {
    if (getNumOfCards(game->deck) > n) {
        int count = 0;    
        struct node *tmp = game->deck;
        while (count < n) {
            count++;
            tmp = tmp->next;
        }
        return tmp->card;
    }
    else {
        return NULL;
    }
}

// Get nth card from the discard pile, n=0 means top card from discard pile
Card getDiscardPileCard (Game game, int n) {
    if (getNumOfCards(game->discard_pile) > n) {        
        int count = 0;    
        struct node *tmp = game->discard_pile;
        while (count < n) {
            count++;
            tmp = tmp->next;
        }
        return tmp->card;
    }
    else {
        return NULL;
    }
}

// Get nth card from the hand of a player p.
Card getHandCard (Game game, int player, int n) {
    if (getNumOfCards(game->hand[player]) > n) {
        int count = 0;    
        struct node *tmp = game->hand[player];
        while (count < n) {
            count++;
            tmp = tmp->next;
        }
        return tmp->card;
    }
    else {
        return NULL;
    }
}

// Get the number of cards in a given player's hand.
int playerCardCount(Game game, int player) {

    return getNumOfCards(game->hand[player]);
}

// Get the number of points for a given player.
// Player should be between 0 and 3.
//
// The number of points is always equal to
// the sum of the values for all the cards in a player's hand.
// This should return this number of points at any point in the game.
int playerPoints(Game game, int player) {
    
    int player_point = 0;
    struct node *n = game->hand[player];
    while (n != NULL) {
        player_point = player_point + cardValue(n->card);
        n = n->next;
    }
    
    return player_point;
}

/*  ----------------------------------------
        ... Helper functions below ...
    ----------------------------------------*/

// Find the last node in the list and return it
static struct node *lastCard(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

// Add the card to the last and return head
static struct node *addToLast(struct node *head, Card card) {
    struct node *last = malloc(sizeof(struct node));
    last->card = card;
    last->next = NULL;    
    if (head == NULL) {
        head = last;
        return head;
    }
    else {
        lastCard(head)->next = last; 
        return head;
    }    
}

// Add the card to the front return the new head
static struct node *addToFront(struct node *head, Card card) {
    struct node *front = malloc(sizeof(struct node));
    front->card = card;
    front->next = head;
    head = front;
    return head;
}

// Remove top card from the deck and return it
static Card removeTopDeckCard(Game game) {
    if (game->deck != NULL) {
        struct node *tmp = game->deck;
        Card new = game->deck->card; 
        game->deck = game->deck->next;    
        free(tmp);
        return new;
    }
    return NULL;
}

// Remove the card from player's hand when PLAY_CARD
static struct node *removeHandCard(Game game, Card card) {
    struct node *curr = game->hand[game->current_player];
    if (curr->card == card) {
        game->hand[game->current_player] = game->hand[game->current_player]->next;
        free(curr);
    }
    else {
        struct node *prev;        
        while (curr != NULL && curr->card != card) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);        
    }
    return game->hand[game->current_player];
}

// Create initial deck
static struct node *createDeck(struct node *head, int deckSize, value values[], color colors[], suit suits[]) {
    int numCard = 0;    
    while (numCard < deckSize) {    
        Card new_card = newCard(values[numCard], colors[numCard], suits[numCard]); 
        head = addToLast(head, new_card);
        numCard++;       
    }
    return head;
}

// Create initial hands for 4 players
static void createHands(Game game) {
    int numPlayer, numCard;    
    for (numPlayer = 0; numPlayer < NUM_PLAYERS; numPlayer++) {
        game->hand[numPlayer] = NULL;
    }
    for (numCard = 0; numCard < STARTING_HAND_SIZE; numCard++) {
        for (numPlayer = 0; numPlayer < NUM_PLAYERS; numPlayer++) {
            Card top = removeTopDeckCard(game);
            game->hand[numPlayer] = addToLast(game->hand[numPlayer], top);        
        }
    }
}

// Destroy linked list of cards
static void destroyCardPile(struct node *head) {
    struct node *tmp;
    while (head != NULL) {
        tmp = head->next;
        destroyCard(head->card);
        free(head);
        head = tmp;
    }
}

// Get number of cards in a linked list
static int getNumOfCards(struct node *head) {
    int card_count = 0;
    struct node *n = head; 
    while (n != NULL) {
        n = n->next;
        card_count++;
    }
    return card_count;
}

// Check whether playing the card is valid
static int isValidCard(Game game, Card card) {    
    if (cardValue(card) == ZERO) {
        return 1;
    }
    if (game->turn_num == 0 && game->current_value == D) {
        return 1;
    }
    if (game->current_value != D) {
        if (cardValue(card) == game->current_value ||
            cardColor(card) == game->current_color ||
            cardSuit(card) == game->current_suit) {
            return 1;
        }
    }
    else {
        if (cardColor(card) == game->current_color ||
            cardValue(card) == D) {
            return 1;
        }
    }
    return 0; 
}

// Check if the card is in current player's hand
static int isCardInHand(Game game, Card card) {
    struct node *n =game->hand[game->current_player];
    while (n != NULL) {
        if (n->card == card) {
            return 1;
        }
        n = n->next;
    }
    return 0;
}

// When draw pile is NULL, turn discard pile to draw pile
static struct node *turnDiscardToDraw(Game game) {
    game->discard_pile = reverseDiscard(game);
    game->deck = game->discard_pile;
    game->discard_pile = NULL;
    return game->deck;
}

// Reverse the discard pile so the bottom card becomes the head
static struct node *reverseDiscard(Game game) {
    struct node *prev = NULL;
    struct node *curr = game->discard_pile;
    struct node *next;   
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;    
    }
    game->discard_pile = prev;
    return game->discard_pile;
}
