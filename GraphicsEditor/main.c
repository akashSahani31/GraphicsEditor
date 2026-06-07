#include <stdio.h>

#define ROWS 10
#define COLS 20

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle()
{
    int row, col, width, height;

    printf("Enter starting row: ");
    scanf("%d", &row);

    printf("Enter starting column: ");
    scanf("%d", &col);

    printf("Enter width: ");
    scanf("%d", &width);

    printf("Enter height: ");
    scanf("%d", &height);

    for(int i = col; i < col + width; i++)
    {
        canvas[row][i] = '*';
        canvas[row + height - 1][i] = '*';
    }

    for(int i = row; i < row + height; i++)
    {
        canvas[i][col] = '*';
        canvas[i][col + width - 1] = '*';
    }
}

void drawLine()
{
    int row, startCol, endCol;

    printf("Enter row number: ");
    scanf("%d", &row);

    printf("Enter starting column: ");
    scanf("%d", &startCol);

    printf("Enter ending column: ");
    scanf("%d", &endCol);

    for(int i = startCol; i <= endCol; i++)
    {
        canvas[row][i] = '*';
    }
}

void drawTriangle()
{
    int row, col, height;

    printf("Enter top row: ");
    scanf("%d", &row);

    printf("Enter center column: ");
    scanf("%d", &col);

    printf("Enter height: ");
    scanf("%d", &height);

    for(int i = 0; i < height; i++)
    {
        canvas[row + i][col - i] = '*';
        canvas[row + i][col + i] = '*';
    }

    for(int i = col - height + 1; i <= col + height - 1; i++)
    {
        canvas[row + height - 1][i] = '*';
    }
}
void drawCircle()
{
    int centerRow, centerCol, radius;

    printf("Enter center row: ");
    scanf("%d", &centerRow);

    printf("Enter center column: ");
    scanf("%d", &centerCol);

    printf("Enter radius: ");
    scanf("%d", &radius);

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            int distance =
                (i - centerRow) * (i - centerRow) +
                (j - centerCol) * (j - centerCol);

            int rSquared = radius * radius;

            if(distance >= rSquared - radius &&
               distance <= rSquared + radius)
            {
                canvas[i][j] = '*';
            }
        }
    }
}
void clearCanvas()
{
    initializeCanvas();
    printf("Canvas cleared successfully!\n");
}
void modifyObject()
{
    printf("\n=== Modify Object ===\n");
    printf("To modify an object:\n");
    printf("1. Clear the canvas\n");
    printf("2. Draw the object again with new dimensions\n");
}
int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
       printf("1. Draw Rectangle\n");
       printf("2. Draw Line\n");
       printf("3. Draw Triangle\n");
       printf("4. Draw Circle\n");
       printf("5. Display Canvas\n");
       printf("6. Clear Canvas\n");
       printf("7. Modify Object\n");
       printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 8)
         {
            printf("Invalid choice!\n");
            continue;
      }
        switch(choice)
        {
            case 1:
                drawRectangle();
                break;

            case 2:
                drawLine();
                break;

            case 3:
                drawTriangle();
                break;

            case 4:
                drawCircle();
                break;

            case 5:
                 displayCanvas();
                 break;

            case 6:
                 clearCanvas();
                 break;

            case 7:
                 modifyObject();
                 break;

            case 8:
                 printf("Exiting program...\n");
                 return 0;

            default:
                 printf("Invalid choice!\n");
        }
    }

    return 0;
}