#pragma once
#include "ChessPiece.h"

class GameBoard
{
public :
	explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
	GameBoard(const GameBoard& src); 
	virtual ~GameBoard() = default;
	GameBoard& operator=(const GameBoard & rhs); 
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard && src) = default;
	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;
	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }
	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };
	void swap(GameBoard & other) noexcept;
private:
	void verifyCoordinate(size_t x, size_t y) const;
	std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
	size_t m_width{ 0 }, m_height{ 0 };
};
export void swap(GameBoard& first, GameBoard& second) noexcept;

