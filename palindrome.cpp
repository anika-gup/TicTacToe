#include <iostream>
#include <cstring>
#include <cwctype>
#include <typeinfo>
using namespace std;

// Checking for Palindromes
// Anika Gupta 9/1/23

int main()
{
  char original[80];
  cin.get(original, 80);
  cin.get();

  
  int orig_len = strlen(original);
 
  
  char original_copy[orig_len];
  int index_count = 0;

  // First edit the original string:
  
  for (int i=0; i<orig_len; i++) { 
    original[i] = tolower(original[i]); // making everything lowercase

    
    // check if they are alphanumerical -- source: https://www.geeksforgeeks.org/iswalnum-function-in-c-stl/
    
    if (iswalnum(original[i])) {
      original_copy[index_count] = original[i];
      index_count++;
    }
  }
  
  // this results in a String that is too long, so another for loop to only extract necessary values

  char newstr[index_count];

  for (int x=0; x<index_count; x++) {
    newstr[x] = original_copy[x];
  }


  // reversing the string
  char backwards[strlen(original_copy)];
  int count = 0;
  for (int i=(strlen(original_copy)-1); i>=0; i--) {
    backwards[count] = original_copy[i];
    count++;
  }

  cout << "backwards: " << backwards << endl;
  cout << "original: " << original_copy << endl;
  // check if the backwards str is identical to original str
  if (strcmp(original_copy, backwards)==0) {
    cout << "they are palindromes!" << endl;
    // this means they are palindromes
  }
  else {
    cout << "Not palindromes" << endl;
  }
  
  return 0;
}
