import gameboard;
import spreadsheet_cell;
import function;
import <vector>;

#include <memory>
import <string>;

using namespace std;

class ChessPiece
{
};

int main()
{
	const char* word{ "two" };
	const char* words[]{ "one", "two", "three", "four" };
	const size_t sizeWords{ size(words) };
	size_t res{ Find(word, words, sizeWords) };
	return 0;
}

// Explicit class template instantiation.