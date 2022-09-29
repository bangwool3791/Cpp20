#pragma once

#include "pch.h"

class Hasher
{
public:
	using is_transparent = void;
	size_t operator() (string_view sv)const { return hash<string_view>{}(sv); }
};

