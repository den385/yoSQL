#pragma once

#include <array>



const uint32_t PAGE_SIZE = 4096;



struct Page
{
	std::array<char, PAGE_SIZE> data;
};