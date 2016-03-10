/*
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * http://www.cplusplus.com
 * http://stackoverflow.com/questions/7352099/stdstring-to-char
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 1
 */

#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;

unsigned long countWords(const string& s, set<string>& wl) {
  char * word;
  unsigned long num = 0;
  char * str_s = strdup(s.c_str());
  word = strtok(str_s, " ,.'\";:-+/?!@#$%^&*()[]{}<>\t");
  while (word != NULL) {
    num += 1;
    wl.insert(word);
    word = strtok(NULL, " ,.'\";:-+/?!@#$%^&*()[]{}<>\t");
  }
  return num;
}

int main()
{
	unsigned long numLines=0;
	unsigned long numWords=0;
	unsigned long numChar=0;
	set <string> uniqueWordList, uniqueLineList;
	string line;
	//initalizing line for while
	while(getline(cin, line)){
		numChar++;
		//accounting for \n as one character
		//start after first line because no \n before first line
		numLines++;
		//if this is running at all there is a line
		numChar+=line.size();
		//quick way

		numWords+=countWords(line, uniqueWordList);
		uniqueLineList.insert(line);
	}

	cout << "\t" << numLines;
	cout << "\t" << numWords;
	cout << "\t" << numChar;
	cout << "\t" << uniqueLineList.size();
	cout << "\t" << uniqueWordList.size() << "\n";
	return 0;
}
