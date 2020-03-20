Author: Gianmarco Natuzzi
Matric: 40439919

HOW TO USE FIND APPLICATION 

The tool chain used for building is the Microsoft Compiler.
In the developer command prompt, change the directory to the folder in which you have all the .c files. 
After that, type in "nmake all" and the program will be compiled and linked. 

Now that we compiled and linked everything, type into the console "find" followed by the word that you want to find.

E.g. "Find hello" 

After that, put the command line argument "-i" and after that, type in the text file in which you want to search for the word. 

E.g. "Find hello -i single_words_test.txt" (Keep in mind that the program needs the .txt extention and it will only work with the two given text files).

Next, we're going to put the command line argument "-r" followed by the new word that we want to replace. 

E.g. "Find hello -i single_words_test.txt -r goodbye" 

Now the program will work if you press enter, but there is one more command line argument, which is "-c" 
You can use -c if you want to give the program case sensitivity. 

E.g. "Find hello -i single_words_test.txt -r goodbye -c" 

The entire modified text file will be outputted in another text file called "output.txt". 