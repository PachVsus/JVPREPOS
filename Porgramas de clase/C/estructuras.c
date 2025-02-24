#include <stdio.h>
#include <stdlib.h>

struct header
{
    int header_version;
    char tagid;
    char signature[4];
    int data_offset;
};