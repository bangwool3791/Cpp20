#pragma once
#include "GamePiece.h"
class ChessPiece :
    public GamePiece
{
public :
    unique_ptr<GamePiece> clone() const override
    {
        return make_unique<ChessPiece>(*this);
    }
};

class TicTacToePiece : public GamePiece
{
public:
    std::unique_ptr<GamePiece> clone() const override
    {
        // Call the copy constructor to copy this instance
        return std::make_unique<TicTacToePiece>(*this);
    }
};