#pragma once
class GamePiece
{
public :
	virtual ~GamePiece() = default;
	virtual unique_ptr<GamePiece> clone() const = 0;
};

