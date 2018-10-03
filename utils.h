#pragma once



#define DECLARE_NONCOPYABLE(TypeName)           \
    TypeName(const TypeName&) = delete;         \
    void operator=(const TypeName&) = delete;
