#include<stdio.h>
#include<string.h>
typedef struct Movie
{
    char MovieName[100];
    char Category[20];
    int duration;
    int ticketCost;
}Movie ;
Movie GetMovieDetails();
char* GetCircleDetails();
int CalculateTicketCost(Movie *m, char circle[]);
int main() {
    
    Movie movie = GetMovieDetails();
    
    
    char *circle = GetCircleDetails();
    
    
    int result = CalculateTicketCost(&movie, circle);
    
   
    if (result == 0) {
        printf("The ticket cost is %d\n", movie.ticketCost);
    } else if (result == -1) {
        printf("Sorry there is no %s type of category in the theatre\n", movie.Category);
    } else if (result == -2) {
        printf("Sorry the circle is invalid\n");
    } else if (result == -3) {
        printf("Sorry both circle and category are invalid\n");
    }
    
    return 0;
}
Movie GetMovieDetails() {
    Movie m;
    printf("Enter movie name: ");
    fgets(m.MovieName, 100, stdin);
    printf("Enter duration: ");
    scanf("%d", &m.duration);
    printf("Enter category (2D/3D): ");
    scanf("%2s", m.Category);  
    
    return m;
}
char* GetCircleDetails() {
   static char circle[10]; 
    
    printf("Enter circle (gold/silver): ");
    scanf("%6s", circle); 
    
    return circle;
}
int CalculateTicketCost(Movie *m, char circle[]) {
   
    if ((strcmp(m->Category, "2D") != 0 && strcmp(m->Category, "3D") != 0) &&
        (strcmp(circle, "gold") != 0 && strcmp(circle, "silver") != 0)) {
        return -3; 
    } 
    else if (strcmp(m->Category, "2D") != 0 && strcmp(m->Category, "3D") != 0) {
        return -1; 
    } 
    else if (strcmp(circle, "gold") != 0 && strcmp(circle, "silver") != 0) {
        return -2; 
    } 
    else if (strcmp(circle, "gold") == 0 && strcmp(m->Category, "2D") == 0) {
        m->ticketCost = 300;
    } 
    else if (strcmp(circle, "gold") == 0 && strcmp(m->Category, "3D") == 0) {
        m->ticketCost = 500;
    } 
    else if (strcmp(circle, "silver") == 0 && strcmp(m->Category, "2D") == 0) {
        m->ticketCost = 250;
    } 
    else if (strcmp(circle, "silver") == 0 && strcmp(m->Category, "3D") == 0) {
        m->ticketCost = 450;
    }

    return 0; 
}
