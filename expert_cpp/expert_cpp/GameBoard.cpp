#include "pch.h"
#include "GameBoard.h"

GameBoard::GameBoard(size_t width, size_t height)
	:m_width{width}
	,m_height{height}
{
	m_cells.resize(m_width);
	for (auto& elem : m_cells)
	{
		elem.resize(m_height);
	}
}

GameBoard::GameBoard(const GameBoard& src)
{
	for (size_t i{ 0 }; i < m_width; i++)
	{
		for (size_t j{ 0 }; j < m_height; j++)
		{
			if (src.m_cells[i][j])
				m_cells[i][j] = src.m_cells[i][j]->clone();
		}
	}
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	GameBoard temp{ rhs };
	::swap(*this, temp);
	return *this;

}

void GameBoard::swap(GameBoard& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw out_of_range{ format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw out_of_range{ format("{} must be less than {}.", y, m_height) };
	}
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	swap(first, second);
}

int main()
{
	GameBoard chessBoard{ 8,8 };
	auto pwan{ make_unique<ChessPiece>() };
	chessBoard.at(0, 0) = std::move(pwan);
	chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;
	return 0;
}