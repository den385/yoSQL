#pragma once

#include <cstdint>
#include <array>

#include "page/page.h"



const uint32_t COLUMN_USERNAME_SIZE = 32;
const uint32_t COLUMN_EMAIL_SIZE = 256;

struct Row
{
	Row() = default;
	Row(uint32_t row_id, std::string&& user_name, std::string&& user_email);

	uint32_t id {0};
	char username[COLUMN_USERNAME_SIZE] {0};
	char email[COLUMN_EMAIL_SIZE] {0};
};



// HARDCODED TABLE'S LAYOUT
//
// column       size (bytes)    offset
// id           4	            0
// username	    32	            4
// email        255             36
// total        291

const uint32_t ID_SIZE          = sizeof(Row::id);
const uint32_t USERNAME_SIZE    = sizeof(Row::username);
const uint32_t EMAIL_SIZE       = sizeof(Row::email);

const uint32_t ROW_SIZE         = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

const uint32_t ID_OFFSET        = 0;
const uint32_t USERNAME_OFFSET  = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET     = USERNAME_OFFSET + USERNAME_SIZE;



void serialize_row(const Row& source, Page& destination, size_t offset);
void deserialize_row(Page& source, size_t offset, Row& destination);

void print_row(const Row& row);