rgrep
========

<b>Creates a simplified version of grep, a UNIX utility that searches for patterns in text files (C). </b>

Uses the following special rules: <br>
* . (period):	Matches any character (including newlines or spaces). <br>
* + (plus sign):	The preceding character may appear 1 or more times (in other words, the preceding character can be repeated several times in a row). Note that this means the pattern ".+" can match any non-empty string. <br>
* ? (question mark):	The preceding character may appear between 0 and 1 times (in other words, the preceding character is optional). <br>
* \ (backslash):	"Escapes" the following character, nullifying any special meaning it has.

For more details/specs, see:
<br> http://inst.eecs.berkeley.edu/~cs61c/fa14/hw/02/hw2.html
