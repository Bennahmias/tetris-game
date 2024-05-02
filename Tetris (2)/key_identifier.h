#ifndef _KEY_IDENTIFIER_H
#define _KEY_IDENTIFIER_H


enum class charkeys {
    ESC = 27,
    RIGHT = 0,
    LEFT = 1,
    DOWN = 2,
    CLOCKWISE = 3,
    COUNTERCLOCKWISE = 4,
    NO_CHAR = -1 
};
enum class difficulty {

    BEST = '0',
    GOOD = '1',
    NOVICE = '2'

};
enum class borders {
    RIGHT_BORDER = -1,
    LEFT_BORDER = 12,
    FLOOR_BORDER = 18
};

enum class matrix
{
    ROW = 18,
    COL = 12
};

enum class shapeTypes
{
    //shapes type
    S_SHAPE = 0,
    PLUS_SHAPE = 1,
    Z_SHAPE = 2,
    I_SHAPE = 3,
    J_SHAPE = 4,
    L_SHAPE = 5,
    O_SHAPE = 6,
    BOMB_SHAPE = 7
};

enum class gameOption
{
    TIE = 0,
    BOARD1 = -1,
    BOARD2 = -2,
    NO_BOARD = -3,
    STARTGAME = 0,
    MIDDLEGAME = 1,
    NUM_OF_BOARDS = 2, //START FROM 0 SO ITS 2 
    SHAPE_SIZE = 4,
    KYES_PER_PLAYER = 5,
    NUM_OF_SHAPES= 7,
    BOMB_CAHNCE = 20,
    NOVICE_RAND = 10,
    GOOD_RAND = 40

};

#endif  _KEY_IDENTIFIER_H 