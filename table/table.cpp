#include "table.h"



std::pair<std::shared_ptr<Page>, size_t> row_slot(Table& table, uint32_t row_num)
{
	uint32_t page_num = row_num / ROWS_PER_PAGE;
	std::shared_ptr<Page> page = table.pages[page_num];

	if (!page)
	{
		// Allocate memory only when we try to access page
		page = std::make_shared<Page>();
		table.pages[page_num] = page;
	}

	uint32_t row_offset = row_num % ROWS_PER_PAGE;
	uint32_t byte_offset = row_offset * ROW_SIZE;

	return std::make_pair(page, byte_offset);
}