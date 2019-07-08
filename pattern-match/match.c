#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef int bool;
#define false 0
#define true !false
#define null false

#define SKIP(text, c) while((int)*text == c && *text != null) text++;
#define SKIP_UNTIL(text, c) while((int)*text != c && (int)*text != null) text++;
#define CLONE(a, b) a=calloc(strlen(b), sizeof(char)); { char *p=b; while(*p != null) { *(char *)(a + (p - b))=tolower(*p); p++; }}
#define COMPARE_WORD(a, b, equal) while (*a != null && *b != null && equal && *b != '?' && *b != '*' && *a == *b) { a++; b++; } equal=(*a == *b || *b == '?' || *b == '*');

bool matches(char * text, char * pattern, bool ignoreCase) {
	bool areEqual = true;
	bool anyChar = false;

	/* No string to compare */
	if (*text == null && *pattern == null)
		return true;
	/* No pattern is an error */
	if (*pattern == null)
		return false;

	char * current;
	char * challenge;
	char * a;
	char * b;
	if (ignoreCase) {
		/* make a lowercase copy to ignore case */
		CLONE(a, text);
		CLONE(b, pattern);
		current = a;
		challenge = b;
	} else {
		current = text;
		challenge = pattern;
	}
	
	char * next;
	do {
		next = (char *)(challenge + 1);
		switch( *challenge ) {
			case '*':
				/* Skip redundant characters */
				SKIP(challenge, '*');
				anyChar = true;
				break;
			case '?':
				while (*challenge == '?' && *current != null) {
					if(anyChar && (*next == null)) {
						SKIP_UNTIL(current, null);
						current--;
						anyChar = false;
					}
					challenge++;
					current++;
					next = (char *)(challenge + 1);
				}
				areEqual = ((*current == null && *challenge == null) ||
							(*current != null && *challenge != null));
				break;
			default:
				if (anyChar) {
					/* Is it the last character? */
					if (*next == null) {
						SKIP_UNTIL(current, null);
						current--;
					} else {
						/* Find a potential matching word */
						SKIP_UNTIL(current, *challenge);
					}
				}
				/* Compare the whole word */
				COMPARE_WORD(current, challenge, areEqual);
				if (areEqual) {
					/* The next char is a * or ? or we finished */
					anyChar = false;
				} else {
					if (anyChar) {
						/* 
						* If the previous challenge char was an asterisk,
						* then we found a similar word, but not the exact one 
						* that we were looking for.
						*/
						int wordSize = challenge - (next - 1);
						/* Rewind + 1 and keep searching if there's text left. */
						if (wordSize > 0) {
							current = (char *)(current - wordSize + 1);
							challenge = (next - 1);
							if (*current == null) {
								anyChar = false;
							} else {
								areEqual = true;
							}
						}
					}
				}
				break;
		}
	} while (areEqual && *current != null && *challenge != null);

	if (ignoreCase) {
		free(a);
		free(b);
	}

	return areEqual;

}

// Function that matches input str with 
// given wildcard pattern 
// https://www.geeksforgeeks.org/wildcard-pattern-matching/
int strmatch(char str[], char pattern[], 
              int n, int m) 
{ 
    // empty pattern can only match with 
    // empty string 
    if (m == 0) 
        return (n == 0); 
  
    // lookup table for storing results of 
    // subproblems 
    int lookup[n + 1][m + 1]; 
  
    // initailze lookup table to false 
    memset(lookup, false, sizeof(lookup)); 
  
    // empty pattern can match with empty string 
    lookup[0][0] = true;
  
    // Only '*' can match with empty string 
    for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            lookup[0][j] = lookup[0][j - 1]; 
  
    // fill the table in bottom-up fashion 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            // Two cases if we see a '*' 
            // a) We ignore ‘*’ character and move 
            //    to next  character in the pattern, 
            //     i.e., ‘*’ indicates an empty sequence. 
            // b) '*' character matches with ith 
            //     character in input 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || 
                               lookup[i - 1][j]; 
  
            // Current characters are considered as 
            // matching in two cases 
            // (a) current character of pattern is '?' 
            // (b) characters actually match 
            else if (pattern[j - 1] == '?' || 
                    str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 
  
            // If characters don't match 
            else lookup[i][j] = false; 
        } 
    } 
  
    return lookup[n][m]; 
} 

// call this function to start a nanosecond-resolution timer
struct timespec timer_start(){
    struct timespec start_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
    struct timespec end_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
    long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
    return diffInNanos;
}

#define EXPECT(a, b, ignoreCase, result) \
	printf("Testing '%s' against '%s' pattern %s, expecting it to %s: %s\n", a, b, \
						(ignoreCase) ? "(Case insensitive)" : "(Case sensitive)", \
						(result) ? "match" : "differ", \
						(matches(a, b, ignoreCase) == result) ? "OK" : "FAIL");

/*
#define EXPECT(a, b, ignoreCase, result) \
	printf("Testing '%s' against '%s' pattern %s, expecting it to %s: %s\n", a, b, \
						(ignoreCase) ? "(Case insensitive)" : "(Case sensitive)", \
						(result) ? "match" : "differ", \
						(strmatch(a, b, strlen(a), strlen(b)) == result) ? "OK" : "FAIL");
 */

int main(int argc, char * argv[]) {
	char * text = "Endless fortune text.[2019].[2AC03F11]_tune.";

	EXPECT(text, text, false, true);
	EXPECT(text, text, true, true);
	EXPECT(text, "asdf", false, false);
	EXPECT(text, "asdf", false, false);
	EXPECT(text, "\0", false, false);
	EXPECT("\0", "\0", false, true);
	EXPECT("\0", "*", false, true);
	
	EXPECT(text, "End*tune.", false, true);
	EXPECT(text, "*ort*", false, true);
	EXPECT(text, "E*", false, true);
	EXPECT(text, "*.", false, true);
	EXPECT(text, "*[2AC*", false, true);
	EXPECT(text, "****", false, true);
	EXPECT(text, "*z", false, false);
	EXPECT(text, "e*", false, false);
	EXPECT(text, "e*", true, true);
	EXPECT(text, "*ORT*", true, true);

	EXPECT(text, "*?*", false, true);
	EXPECT(text, "*? *", false, true);
	EXPECT(text, "* *", false, true);
	EXPECT(text, "*  *", false, false);
	EXPECT(text, "*u*", false, true);
	EXPECT(text, "*uu*", false, false);
	EXPECT(text, "*s? *", false, true);
	EXPECT(text, "*z? *", false, false);
	EXPECT(text, "?*", false, true);
	EXPECT(text, "*?", false, true);
	EXPECT(text, "End??****??", false, true);
	EXPECT(text, "End??****?.", false, true);
	EXPECT(text, "?*?*?tune.", false, true);
	EXPECT(text, "Endless fortune*?.", false, true);
	EXPECT(text, "????????*????????", false, true);
	EXPECT(text, "????", false, false);
	
	char * longText = "This is a quite long string that needs to be checked against a proper pattern expression.";
	char * longPattern = "T*?* ???? * *ed*?*prop*tt*? p*?";

	struct timespec start = timer_start();
	matches(longText, longPattern, false);
	long elapsed = timer_end(start);

	printf("Testing speed, elapsed time: %ld nanoseconds.\n", elapsed);

	start = timer_start();
	strmatch(longText, longPattern, strlen(longText), strlen(longPattern));
	elapsed = timer_end(start);

	printf("Testing challenger speed, elapsed time: %ld nanoseconds.\n", elapsed);

	return 0;
}
