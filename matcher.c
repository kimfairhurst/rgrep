/**
 * The contents of this file are only a suggestion.
 * Feel free to change anything.
 */
 
#include "matcher.h"

int matches_leading_two(char *partial_line, char *pattern);

int matches_leading(char *partial_line, char *pattern) {
  // You can use this recommended helper function, or not.
   
   // if reach end of pattern without failing -> PASS
    if (!*pattern){
        return 1;
    }

    // if reach end of line without reaching end of pattern -> FAIL
    if (!*partial_line || *partial_line == '\n'){
        return 0;
    }
   

   char next = *(pattern + 1);

   if (*pattern == '\\'){
   		return matches_leading_two(partial_line, pattern+1);
   	}

   	if (*pattern == '.'){
   		if (next == '+'){
    		return (matches_leading(partial_line+1, pattern) || matches_leading(partial_line+1, pattern+2));
    	}
    	return matches_leading(partial_line + 1, pattern + 1);
   	}

	switch (next){
    	case ('?') :	        			
    		if (*partial_line!=*pattern) {
           		return matches_leading(partial_line, pattern + 2);
           	}
	        return matches_leading(partial_line, pattern+2) || matches_leading(partial_line+1, pattern+2);
	    case ('+') :
	    	if (*partial_line != *pattern){
	    		return 0;
	    	}
	    	return matches_leading(partial_line+1, pattern) || matches_leading(partial_line+1, pattern+2);
	    default :   
			if (*partial_line == *pattern){
				return matches_leading(partial_line + 1, pattern + 1);
			    }
			else {
			  	return 0;
			}		
    	}     
   
}


int matches_leading_two(char *partial_line, char *pattern) {
  // You can use this recommended helper function, or not.
   
   // if reach end of pattern without failing -> PASS
    if (!*pattern){
        return 1;
    }

    // if reach end of line without reaching end of pattern -> FAIL
    if (!*partial_line || *partial_line == '\n'){
        return 0;
    }

   char next = *(pattern + 1);

	switch (next){
    	case ('?') :	        			
    		if (*partial_line!=*pattern) {
           		return matches_leading(partial_line, pattern + 2);
           	}
	        return matches_leading(partial_line, pattern+2) || matches_leading(partial_line+1, pattern+2);
	    case ('+') :
	    	if (*partial_line != *pattern){
	    		return 0;
	    	}
	    	return matches_leading(partial_line+1, pattern) || matches_leading(partial_line+1, pattern+2);
	    default :   
			if (*partial_line == *pattern){
				return matches_leading(partial_line + 1, pattern + 1);
			    }
			else {
			  	return 0;
			}		
    	}     
   
}




 
/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {
     while (*line) {
         if (matches_leading(line, pattern)) {
             return 1;
         }
         line++;
     }
     return 0;
 }
