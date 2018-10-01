#pragma once

#include <cstdint>
#include <array>
#include <memory>

#include "page.h"
#include "row.h"




const uint32_t TABLE_MAX_PAGES = 100;
const uint32_t ROWS_PER_PAGE = sizeof(Page) / sizeof(Row);
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

struct Table
{
	std::array<std::shared_ptr<Page>, TABLE_MAX_PAGES> pages;
	uint32_t num_rows;
};



std::pair<std::shared_ptr<Page>, size_t> row_slot(Table& table, uint32_t row_num);