#include <algorithm>
#include <cstring>
#include <iostream>

#include "row.h"
#include "page.h"



Row::Row(uint32_t row_id, std::string&& user_name, std::string&& user_email)
: id(row_id)
{
	std::move(user_name.begin(), user_name.end(), username);
	std::move(user_email.begin(), user_email.end(), email);
}


void serialize_row(const Row& source, Page& destination, size_t offset)
{
	std::memcpy(&destination.data[0] + ID_OFFSET, &(source.id), ID_SIZE);
	std::memcpy(&destination.data[0] + USERNAME_OFFSET, &(source.username), USERNAME_SIZE);
	std::memcpy(&destination.data[0] + EMAIL_OFFSET, &(source.email), EMAIL_SIZE);
}

void deserialize_row(Page& source, size_t offset, Row& destination)
{
	std::memcpy(&(destination.id), &source.data[0] + ID_OFFSET, ID_SIZE);
	std::memcpy(&(destination.username), &source.data[0] + USERNAME_OFFSET, USERNAME_SIZE);
	std::memcpy(&(destination.email), &source.data[0] + EMAIL_OFFSET, EMAIL_SIZE);
}

void print_row(const Row& row)
{
	std::cout << row.id << " " << row.username << " " << row.email << std::endl;
}