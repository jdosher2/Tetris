//
//  Tetromino.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Tetromino.hpp"


// TODO: replace manual entries with rotation algorithm

const bool shape_null[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
};

const bool shape_I[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, true},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {true, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    }
};

const bool shape_J[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, false, false, true, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, true, true, false, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, true, false, false, false},
        {false, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false},
    }
};

const bool shape_L[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, true, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, true, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, false, true, false},
        {false, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    }
};

const bool shape_O[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    }
};

const bool shape_S[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, true, true, false, false},
        {false, false, false, false, false}
    }
};

const bool shape_T[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    }
};

const bool shape_Z[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, false, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    }
};


void Tetromino::Move(int direction) {
    Tetromino::SetX(Tetromino::GetX() + direction);
}

int Tetromino::GetX() {
    return Tetromino::x;
}

int Tetromino::GetY() {
    return Tetromino::y;
}

Tetromino::State Tetromino::GetState() {
    return Tetromino::current_state;
}

void Tetromino::SetX(int x_pos) {
    Tetromino::x = x_pos;
}

void Tetromino::SetY(int y_pos) {
    Tetromino::y = y_pos;
}

void Tetromino::SetState(Tetromino::State state) {
    Tetromino::current_state = state;
}
