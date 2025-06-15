// ProjectTwo.cpp
// Johnathan Dumke - CS 300 - 06/9/2025

#include <iostream>     
#include <fstream>    
#include <sstream>     
#include <vector>      
#include <algorithm>    
#include <string>      
#include <cctype>      

using namespace std;

// Struct to hold course details: ID, name, and list of prerequisites
struct Course {
    string courseID;              // Unique identifier for the course
    string courseName;            // Full name/title of the course
    vector<string> preList;       // List of prerequisites 
};

// Utility function to convert a string to uppercase for consistent comparisons
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Function to load courses from a CSV file into the courseList vector
void loadCoursesFromFile(const string& filePath, vector<Course>& courseList) {
    ifstream file(filePath);
    string line;

    // Handle error if file cannot be opened
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    // Read each line of the CSV file
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        // Split line by commas and store tokens
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Validate that the line has at least a course ID and name
        if (tokens.size() < 2) {
            cout << "Formatting error: invalid line.\n";
            continue;
        }

        // Create a Course object from parsed tokens
        Course course;
        course.courseID = toUpper(tokens[0]);   // Convert course ID to uppercase
        course.courseName = tokens[1];          // Store course name

        // Store remaining tokens as prerequisites
        for (size_t i = 2; i < tokens.size(); ++i) {
            course.preList.push_back(toUpper(tokens[i]));
        }

        // Add course to the list
        courseList.push_back(course);
    }

    // Close file and report number of courses loaded
    file.close();
    cout << courseList.size() << " courses loaded successfully.\n";
}

// Function to sort the course list and print it in alphanumeric order
void sortAndPrintCourses(vector<Course>& courseList) {
    // Sort courses by courseID using a lambda function
    sort(courseList.begin(), courseList.end(), [](Course a, Course b) {
        return a.courseID < b.courseID;
        });

    cout << "Here is a sample schedule:\n";
    for (auto& course : courseList) {
        cout << course.courseID << ", " << course.courseName << endl;
    }
}

// Function to print detailed info about a specific course by its ID
void printCourseDetails(const string& searchID, const vector<Course>& courseList) {
    string id = toUpper(searchID);  // Normalize user input

    // Search through the course list
    for (const auto& course : courseList) {
        if (course.courseID == id) {
            cout << course.courseID << ", " << course.courseName << endl;
            if (!course.preList.empty()) {
                cout << "Prerequisites: ";
                for (size_t i = 0; i < course.preList.size(); ++i) {
                    cout << course.preList[i];
                    if (i < course.preList.size() - 1) cout << ", ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "Course not found.\n";
}

int main(int argc, char* argv[]) {
    vector<Course> courseList;  // Container for storing all course data

    // Get the file path from command-line or default to sample filename
    string filePath = (argc > 1) ? argv[1] : "CS 300 ABCU_Advising_Program_Input.csv";
    int choice = 0;

    cout << "Welcome to the course planner.\n";

    // Main loop for menu-driven interface
    while (choice != 9) {
        // Display menu options
        cout << "\n1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n";
        cout << "What would you like to do? ";
        cin >> choice;

        // Validate input and handle invalid options
        if (cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 9)) {
            cin.clear();                   // Clear error state
            cin.ignore(1000, '\n');       // Ignore invalid input
            cout << choice << " is not a valid option.\n";
            continue;
        }

        // Option 1: Load course data from CSV
        if (choice == 1) {
            loadCoursesFromFile(filePath, courseList);
        }
        // Option 2: Print the sorted course list
        else if (choice == 2) {
            if (courseList.empty()) {
                cout << "Please load data first.\n";
            }
            else {
                sortAndPrintCourses(courseList);
            }
        }
        // Option 3: Search and print details for a specific course
        else if (choice == 3) {
            if (courseList.empty()) {
                cout << "Please load data first.\n";
            }
            else {
                string userInput;
                cout << "What course do you want to know about? ";
                cin >> userInput;
                printCourseDetails(userInput, courseList);
            }
        }
        // Option 9: Exit program
        else if (choice == 9) {
            cout << "Thank you for using the course planner!\n";
        }
    }

    return 0;
}
