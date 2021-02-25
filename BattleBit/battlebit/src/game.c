//
// Created by carson on 5/20/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

// STEP 10 - Synchronization: the GAME structure will be accessed by both players interacting
// asynchronously with the server.  Therefore the data must be protected to avoid race conditions.
// Add the appropriate synchronization needed to ensure a clean battle.

static game * GAME = NULL;

void game_init() {
    if (GAME) {
        free(GAME);
    }
    GAME = malloc(sizeof(game));
    GAME->status = CREATED;
    game_init_player_info(&GAME->players[0]);
    game_init_player_info(&GAME->players[1]);
}

void game_init_player_info(player_info *player_info) {
    player_info->ships = 0;
    player_info->hits = 0;
    player_info->shots = 0;
}

int game_fire(game *game, int player, int x, int y) {
    // Step 5 - This is the crux of the game.  You are going to take a shot from the given player and
    // update all the bit values that store our game state.
    //
    //  - You will need up update the players 'shots' value
    //  - you You will need to see if the shot hits a ship in the opponents ships value.  If so, record a hit in the
    //    current players hits field
    //  - If the shot was a hit, you need to flip the ships value to 0 at that position for the opponents ships field
    //
    //  If the opponents ships value is 0, they have no remaining ships, and you should set the game state to
    //  PLAYER_1_WINS or PLAYER_2_WINS depending on who won.


    player_info *current_player = &game->players[player];
    int opponent = (player + 1) % 2;
    player_info *opp_player = &game->players[opponent];

    // Take shot
    // Update current player's shots
    current_player->shots |= xy_to_bitval(x, y);
    // Update current player's hits
    if (opp_player->ships & xy_to_bitval(x, y)) {
        current_player->hits |= xy_to_bitval(x, y);
        // Update opponent's ships
        opp_player->ships &= ~(xy_to_bitval(x, y));
        // Test Game Over otherwise update turn
        if (opp_player->ships == 0) {
            if (player == 0) {
                game->status = PLAYER_0_WINS;
            } else {
                game->status = PLAYER_1_WINS;
            }
        } else if (player == 0) {
            game->status = PLAYER_1_TURN;
        } else {
            game->status = PLAYER_0_TURN;
        }
        // Player hits
        return 1;
    }
    // Player misses
    return 0;
}

unsigned long long int xy_to_bitval(int x, int y) {
    // Step 1 - implement this function.  We are taking an x, y position
    // and using bitwise operators, converting that to an unsigned long long
    // with a 1 in the position corresponding to that x, y
    //
    // x:0, y:0 == 0b00000...0001 (the one is in the first position)
    // x:1, y: 0 == 0b00000...10 (the one is in the second position)
    // ....
    // x:0, y: 1 == 0b100000000 (the one is in the eighth position)
    //
    // you will need to use bitwise operators and some math to produce the right
    // value.

    // will be returned as converted ull
    unsigned long long value;
    unsigned long long shift = (y + 1) * 8 - (8 - x);

    // Check if x or y values out of bounds
    if (x < 0 || y < 0 || x > 7 || y > 7) {
        // Out of bounds error returns 0
        return 0;
    } else {
        value = 1ull << shift;
        return value;
    }
}

struct game * game_get_current() {
    return GAME;
}

int game_load_board(struct game *game, int player, char * spec) {
    // Step 2 - implement this function.  Here you are taking a C
    // string that represents a layout of ships, then testing
    // to see if it is a valid layout (no off-the-board positions
    // and no overlapping ships)
    //

    // if it is valid, you should write the corresponding unsigned
    // long long value into the Game->players[player].ships data
    // slot and return 1
    //
    // if it is invalid, you should return -1

    // size of the specification string
    int spec_size = 15;
    player_info *current_player = &game->players[player];

    // Stores int (boolean) used to determine if a ship type has been used.
    // indexed by size: Carrier: 0, Battleship: 1, Destroyer: 2, Sub: 3, Patrol Boat: 4
    int ships_used[6] = {0};
    // Other helper vars
    char ship_type;
    char x_start;
    char y_start;

    // Check input is not NULL
    if (spec == NULL) {
        return -1;
    }

    // Handle shortcut
    if (spec[0] == 'Z') {
        game->players[player].ships |= xy_to_bitval(0, 0);
        return 1;
    }

    // Loop through spec 3 chars at a time
    // store relevant values and call appropriate add function
    for (int i = 0; i < spec_size; i += 3) {
        ship_type = spec[i];
        x_start = spec[i + 1] - '0';
        y_start = spec[i + 2] - '0';
        int length = get_ship_info(ship_type, ships_used);

        // Error Handling
        // If ship has been used already signal error
        if (length == -1) {
            return -1;
        }
        // Check size of input string
        if (strlen(spec) != spec_size) {
            return -1;
        }
        // Check for horizontal orientation
		if (spec[i] < 91 && spec[i] > 64) {
			// place ship on game board
			int err = add_ship_horizontal(current_player, x_start, y_start, length);
			// if invalid placement, signal an error
			if (err == -1) {
				return err;
			}
		// Check for vertical orientation
		} else if (spec[i] < 123 && spec[i] > 97) {
			// place ship on game board
			int err = add_ship_vertical(current_player, x_start, y_start, length);
			// if invalid placement, signal an error
			if (err == -1) {
				return err;
			}
		}
    }
    // set appropriate game statuses
    if (!game->players[player].ships || !game->players[(player + 1) % 2].ships) {
        game->status = CREATED;
    } else if (player == 0) {
        game->status = PLAYER_1_TURN;
    } else {
        game->status = PLAYER_0_TURN;
    }
    return 1;
}

int add_ship_horizontal(player_info *player, int x, int y, int length) {
    // implement this as part of Step 2
    // returns 1 if the ship can be added, -1 if not
    // hint: this can be defined recursively

    // base case: ship has been successfully placed
    if (length == 0) {
        return 1;
    } else {
        // Check for ship overlap
        if(xy_to_bitval(x, y) & player->ships) {
            return -1;
        }
        player->ships |= xy_to_bitval(x, y);
        return add_ship_horizontal(player, ++x, y, --length);
    }
}

int add_ship_vertical(player_info *player, int x, int y, int length) {
    // implement this as part of Step 2
    // returns 1 if the ship can be added, -1 if not
    // hint: this can be defined recursively

    // base case: ship has been successfully placed
    if (length == 0) {
        return 1;
    } else {
        // Check for ship overlap
        if(xy_to_bitval(x, y) & player->ships) {
            return -1;
        }
        player->ships |= xy_to_bitval(x, y);
        return add_ship_vertical(player, x, ++y, --length);
    }
}

int get_ship_info(char type, int ships_used[]) {
    switch (type) {
    case 'C': case 'c':
        if (ships_used[0] == 1) {
            // error ship has already been used
            return -1;
        } else {
            ships_used[0] = 1;
        }
        return 5;
	case 'B': case 'b':
        if (ships_used[1] == 1) {
            return -1;
        } else {
            ships_used[1] = 1;
        }
		return 4;
	case 'D': case 'd':
        if (ships_used[2] == 1) {
            return -1;
        } else {
            ships_used[2] = 1;
        }
        return 3;
	case 'S': case 's':
        if (ships_used[3] == 1) {
            return -1;
        } else {
            ships_used[3] = 1;
        }
        return 3;
	case 'P': case 'p':
        if (ships_used[4] == 1) {
            return -1;
        } else {
            ships_used[4] = 1;
        }
    	return 2;
    // Z is only used for shortcut command - does not have error checking.
    case 'Z':
        return 1;
	default:
		// error
		return -1;
    }
}
