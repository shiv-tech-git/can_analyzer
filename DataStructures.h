#pragma once
#include <vector>

#define LEADING_EDGE 0
#define TRAILING_EDGE 1

typedef uint32_t MSG_ID_T;
typedef uint32_t MSG_TIME_T;
typedef uint8_t MSG_BYTE_T;
typedef std::vector<MSG_BYTE_T> MSG_DATA_T;
typedef uint32_t MSG_DATA_SIZE_T;
typedef uint8_t MSG_CAN_NUM_T;


typedef uint32_t CHANGES_COUNTER_T;

struct msg_data
{
    MSG_ID_T id;
    MSG_DATA_T data;
    MSG_TIME_T time;
    MSG_DATA_SIZE_T data_size;
    MSG_CAN_NUM_T can_number;
};

struct change_point
{
    uint32_t time;
    uint8_t b_data;
    bool edge;
};