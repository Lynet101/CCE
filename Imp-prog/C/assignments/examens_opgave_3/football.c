/*  A program to display football teams based on points granted in 90 matches
    football.c v0.1 | 19/11/24 @ 08:38
    Sebastian Lindau-Skands | slinda24@student.aau.dk
*/

/* DEVELOPER NOTS:
#### Implementation Requirements
1. **Data Parsing**:
   - Process and store match data in the match array.
   - Update team stats in the team array based on match outcomes.

2. **Point System**:
   - **Win**: 3 points.
   - **Draw**: 1 point.
   - **Loss**: 0 points.

3. **Sorting Criteria**:
   - Primary: Points.
   - Secondary: Goal difference (goals scored - goals conceded).

4. **Output Format**:
   - Print the league standings with four aligned columns:
     ```
     Holdnavn    Point    Mål-af-hold    Mål-mod-hold
     ```

- Assumptions:
  - Fixed number of 90 matches and 12 teams.
  - Teams can be placed in pre-programmed array slots.
- Goal: Display a well-formatted and readable table summarizing the standings.
*/

typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} weekdays;

struct match {
    int weekday;
    int *date[4];//[ddmm]
    int time;// %60 = minutes, /60 = hours
    char *teams;
    int *score[2]; //[Team A, Team B]
    int audience;
};

struct team {
    char *name;
    int points;
    int goals_scored;
    int goals_conceded;
};

#include <stdio.h>
#include <stdlib.h>

int main() {
    return 0;
}
