
//--------------------PLAY_CARD

printf("\n======= Player 0's Turn =======\n");

    printf("Checking the game state\n");
    checkGameState(game, 0, 0, 0, -1, -1);

    printf("Checking player 0 has ");
    printCardByComponents(THREE, RED, SPADES);
    printf("\n");
    card = findCardInHand(game, 0, THREE, RED, SPADES);
    assert(card != NULL);

    printf("Checking it is valid for player 0 to play this card\n");
    move.action = PLAY_CARD;
    move.card = card;  // card (Three, RED, SPADES) 
    assert(isValidMove(game, move) == TRUE);  // isValidMove should return TRUE 
    printf("Checking the game state\n");
    checkGameState(game, 0, 0, 0, -1, -1);

    printf("Playing the card\n");
    playMove(game, move);

    printf("Checking played card is at the top of the discard pile\n");
    checkTopDiscard(game, card);

    printf("Checking player 0 no longer has ");
    printCardByComponents(THREE, RED, SPADES);
    printf("\n");
    card = findCardInHand(game, 0, THREE, RED, SPADES);
    assert(card == NULL);
    

//----------------------DRAW_CARD

    printf("\n======= Player 2's Turn =======\n");
    checkGameState(game, 2, 6, 0, 1, 5);   

    printf("Checking player 2 can pick up a card\n");
    move.action = DRAW_CARD;
    assert(isValidMove(game, move) == TRUE);

    printf("Checking the top of the deck is ");
    printCardByComponents(D, YELLOW, CLUBS);
    printf("\n");
    card = getDeckCard(game, 0);
    assert(cardMatchesComponents(card, D, YELLOW, CLUBS));

    printf("Player 2 picks up the card\n");
    playMove(game, move);

    printf("Checking the card is now in player 2's hand\n");
    Card cardInHand = findCardInHand(game, 2, D, YELLOW, CLUBS);
    assert(cardInHand == card);


//-----------------------END_TURN


    printf("Checking the game state\n");

    checkGameState(game, 1, 5, 1, 0, 5);

    printf("Checking player 1 can end their turn\n");

    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 1's turn\n");

    playMove(game, move);

    printf("Checking the game state\n");

    checkGameState(game, 2, 6, 0, 1, 5);
    
    
    
    
//------------------player function

/* All the required information regarding the current state of the game 
   is available via "Game.h" functions. We can retrive  information using all 
   the functions in "Game.h" above the comment "The following functions 
   must NOT be called by a player". 
   
   Some of the functions a payer can call are listed below, 
   see the latest Game.h for the updated list.*/

    int handCardCount(Game game);
    Card handCard(Game game, int card);
    
    int currentPlayer(Game game);
    int getPreviousTurnPlayer(Game game);
        
    int currentTurn(Game game);
    int numTurns(Game game);
    int getTopDiscardTurnNumber(Game game);    
    int currentTurnMoves(Game game);
            
    Card topDiscard(Game game);
    int getCurrentColor(Game game);

    int getNumberOfTwoCardsAtTop(Game game);
    int getActiveDrawTwos(Game game);

    int isValidMove(Game game, playerMove move);

    int numCards(Game game, suit suit);
    int numOfSuit(Game game, suit suit);
    int numOfColor(Game game, suit suit);
    int numOfValue(Game game, suit suit);
    

    // see the latest Game.h for the updated list ... 
