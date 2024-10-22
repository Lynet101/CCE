#include <stdio.h>
#include <stdlib.h>

enum Pre_course {guacamole, tartelleter, lakserulle, greaskarsuppe};
enum Main_course {gyldenkål, hakkebøf, gullsh, forloren_hare};
enum Desert {pkager_m_is, gulerodskage, chokolademouse, citronfromage};

void menu_selector(enum Pre_course * pre_course, enum Main_course * main_course, enum Desert * dessert);
void print_menu(enum Pre_course pre_course, enum Main_course main_course, enum Desert dessert);

int main() {
	enum Pre_course pre_course;
	enum Main_course main_course;
	enum Desert dessert;

	for (int i = 0; i<25; i++) {
		menu_selector(&pre_course, &main_course, &dessert);
		print_menu(pre_course, main_course, dessert);
	}
}

void menu_selector(enum Pre_course * pre_course, enum Main_course * main_course, enum Desert * dessert) {
    *pre_course = rand() % 4;
    *main_course = rand() % 4;
    *dessert = rand() % 4;
}

void print_menu(enum Pre_course pre_course, enum Main_course main_course, enum Desert dessert) {
    const char *pre_courses[] = {"Guacamole", "Tartelleter", "Lakserulle", "Greaskarsuppe"};
    const char *main_courses[] = {"Gyldenkål", "Hakkebøf", "Gullsh", "Forloren hare"};
    const char *desserts[] = {"Pandekager med is", "Gulerodskage", "Chokolademouse", "Citronfromage"};

    printf("TODAYS MENU\n-----------\n");
    printf("Pre-course: %s\n", pre_courses[pre_course]);
    printf("Main course: %s\n", main_courses[main_course]);
    printf("Desert: %s\n", desserts[dessert]);
    printf("\n\n");
}