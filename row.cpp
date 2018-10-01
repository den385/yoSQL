#include <algorithm>
#include <cstring>

#include "row.h"
#include "page.h"



void serialize_row(const Row& source, Page& destination, size_t offset)
{
	char* dest = &destination.data.front() + offset;

	std::memcpy(dest + ID_OFFSET, &(source.id), ID_SIZE);
	std::memcpy(dest + USERNAME_OFFSET, &(source.username), USERNAME_SIZE);
	std::memcpy(dest + EMAIL_OFFSET, &(source.email), EMAIL_SIZE);
}

void deserialize_row(Page& source, size_t offset, Row& destination)
{
	char* src = &source.data.front() + offset;

	memcpy(&(destination.id), src + ID_OFFSET, ID_SIZE);
	memcpy(&(destination.username), src + USERNAME_OFFSET, USERNAME_SIZE);
	memcpy(&(destination.email), src + EMAIL_OFFSET, EMAIL_SIZE);
}