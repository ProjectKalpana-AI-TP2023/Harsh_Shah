#include <bits/stdc++.h>

using namespace std;

class TextEditor{                                 
  public:

    TextEditor(){                                //Initializes the object with empty text

    }

    void addText(string text){                   //Appends text to where the cursor is. The cursor ends to the right of text
      main_str = main_str + text; 
    }

    void deleteText(int k){                      //Deletes k characters to the left of the cursor
       while(k>0 && sizeof(main_str)>0){
        main_str.pop_back();
        k--;
       }
    }

    void backspace(){                            //Deletes 1 character to the left of the cursor
        deleteText(1);
    }

    int findCursor(){                            //Returns the index position of the cursor
      return sizeof(main_str) ;
    }                                             

    void cursorLeft(int k){                      //Moves the cursor to the left k times. 
      while(k>0 && sizeof(main_str)>0 ){         //Equivalent to pressing the left arrow key on a keyboard
         char c = main_str.back();
         main_str.pop_back();
         other_str = other_str + c;
         k--;
      }
    }                                              
                                                  

    void cursorRight(int k){                     //Moves the cursor to the right k times.
      while(k>0 && sizeof(other_str)>0){         //Equivalent to pressing the right arrow key on a keyboard
         char c = other_str.front();
         other_str.erase(other_str.begin());
         main_str = main_str + c;
         k--;
      }                                             

    }                      
                                                  

    string fullText(){                            //Returns all the text from the start to the finish 
      return main_str + other_str;
    }

    string showText(int k){                        //Returns the next k characters to the right of the cursor
        return other_str;
    }                                            

  private:
    string main_str  ; 
    string other_str ;
   
};


int main(){
  

    return 0;
}

/*

TextEditor(); //Initializes, full string is [ "^" ]
addText("Hello"); //full string is [ "Hello^" ]
backspace(); //full string is [ "Hell^" ]
cursorLeft(2); //full string is [ "He^ll" ]
deleteText(3); //deletes only 2 characters as 3 are not available. full string is [ "^ll" ]
addText("fa"); //full string is [ "fa^ll" ]
cursorRight(3); //Goes only 2 to the right as further is not legal. full string is [ "fall^" ]
cout<<fullText(); //Prints "fall" (Do not print the cursor)

*/
