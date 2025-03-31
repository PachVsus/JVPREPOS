#include <stdio.h>
#include <stdlib.h>

struct signature {
    char sign;
    char version;
};

struct id {
    char id;
    char platform;
};

struct data {
    struct signature sign;
    struct id idv;
    char data[100];
};

// function prototype
void receive_data(struct data* d);
struct signature* extractsignature(struct data* d);
struct id* extractid(struct data* d);

// function implementations
void receive_data(struct data* d) {
    d->sign.sign = 'A';
    d->sign.version = '1';
    d->idv.id = 'B';
    d->idv.platform = 'C';
    snprintf(d->data, sizeof(d->data), "Sample data");
}

struct signature* extractsignature(struct data* d) {
    return &d->sign;
}

struct id* extractid(struct data* d) {
    return &d->idv;
}

int main(void) {
    struct data d;
    receive_data(&d);
    struct signature* s = extractsignature(&d);
    struct id* i = extractid(&d);
    printf("Signature: %c\n", s->sign);
    printf("Version: %c\n", s->version);
    printf("ID: %c\n", i->id);
    printf("Platform: %c\n", i->platform);
    return 0;
}