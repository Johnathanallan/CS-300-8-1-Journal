# CS-300-8-1-Journal

-What was the problem you were solving in the projects for this course?

The problem I was trying to solve in each of the projects is the first project I had to write Pseudocode that loaded users course data. You can also search for specific courses. The challenge I had faced was being able to efficiently store, retrieve, and manage this course information, especially as the data set grows.

-How did you approach the problem? Consider why data structures are important to understand.

I approached the problem by looking at the requirements and making sure all of them are met. These were course lookup, validation of prerequisites, and displaying courses in alphanumeric order. To address this I implementing multiple data structures—vectors, hash tables, and binary search trees in pseudocode for Project One to analyze their strengths and trade-offs. In project 2 I had a fully functional version using a hash table. It provided constant-time access for lookups and validation. 

-How did you overcome any roadblocks you encountered while going through the activities or project?

I overcame roadblocks by managing user input and file reading. An example of this would be invalid user inputs like typing letters instead of menu numbers which caused the program to crash or loop unexpectedly. I resolved this by incorporating cin.fail(), clearing the input buffer with cin.clear() and cin.ignore(), and adding robust input validation logic. I also had a problem with incomplete lines in the CSV file. I solved this with validating token count before processing a line and skipping invalid entries with an error message.

-How has your work on this project expanded your approach to designing software and developing programs?

It has expanded my approach by teaching me how to design flexible and modular systems. It has taught me how to build systems that are easy to test. I also started viewing data processing from a more performance-aware perspective. 

-How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

My work has evolved because it has pushed my to write better coding practices. I write comments, descriptive variable names, and more organized code. I also learned to keep input/output separate from core logic so that each part of the program has a clear responsibility. I used utility functions like toUpper() to ensure consistent formatting and relied on reusable patterns for parsing, printing, and error handling. I mainly focus on readable and adaptable code from the start. 


