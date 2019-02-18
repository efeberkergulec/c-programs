#include <stdio.h>
#include <string.h>
#define MAXCHAR 12
#define LINELENGTH 10

typedef struct
{
    int day;
    int month;
    int year;
}date_t;

typedef struct
{
    char type;
    date_t packaging_date;
}p;

typedef struct
{
    char type;
    date_t expiration_date;
}m;

typedef struct
{
    date_t expiration_date;
    int aisle_number;
    char aisle_side;
}c;

typedef struct
{
    int aisle_number;
    char aisle_side;
}s;

union category_t
{
    p perfumery;
    m makeup;
    c cleanser;
    s shampoo;
};

typedef struct
{
    char name[30];
    int unit_cost;
    char product_category;
    union category_t actual;
}cosmetic_item_t;


void print_item(const cosmetic_item_t type)
{
    for(;;)
    {
        printf("**%s**",name);
        printf(" Unit cost:%dTL--Type:%c--");
    }
}

void loadItems(cosmetic_item_t type[])
{
    char file_data[MAXCHAR];
    char whole_line[LINELENGTH];
    FILE *inp;

    printf("Enter the name(max. 12 characters) of the file whose data should be read ==> ");
    scanf("%s",file_data);

    inp = fopen(file_data,"r");
    int status;
    int count = 0;

    while(status != EOF)
    {
        status = fscanf(inp,"%s%d%c",type[count].name,type[count].unit_cost,type[count].product_category);
        switch(type[count].product_category)
        {
        case 'p':
        case 'P':
            fscanf(" %c %d %d %d",type[count].actual.perfumery.type,type[count].actual.perfumery.packaging_date.day,type[count].actual.perfumery.packaging_date.month,type[count].actual.perfumery.packaging_date.year);
            break;
        case 'm':
        case 'M':
            fscanf(" %c %d %d %d",type[count].actual.makeup.type,type[count].actual.makeup.expiration_date.day,type[count].actual.makeup.expiration_date.month,type[count].actual.makeup.expiration_date.year);
            break;
        case 'c':
        case 'C':
            fscanf(" %d %d %d %d %c",type[count].actual.cleanser.expiration_date.day,type[count].actual.cleanser.expiration_date.month,type[count].actual.cleanser.expiration_date.year,type[count].actual.cleanser.aisle_number,type[count].actual.cleanser.aisle_side);
            break;
        case 's':
        case 'S':
            fscanf("%d %c",type[count].actual.shampoo.aisle_number,type[count].actual.shampoo.aisle_side);
            break;
        }
    count++;
    }

    fclose(inp);
}

int main(void)
{
    struct cosmetic_item_t items[MAXCHAR];
    loadItems(items);
    return 0;
}

