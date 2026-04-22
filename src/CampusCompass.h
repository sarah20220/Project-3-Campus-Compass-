#pragma once
#include <string>

using namespace std;

class CampusCompass {
private:
    // Think about what member variables you need to initialize
    // perhaps some graph representation?

// ------------------------------------

    bool insert(string STUDENT_NAME, int STUDENT_ID, int RESIDENCE_LOCATION_ID, N CLASSCODE_1 CLASSCODE_2 … CLASSCODE_N);
    // Adds a student to the class(es) with the specified name: STUDENT_NAME, STUDENT_ID,   RESIDENCE_LOCATION_ID, and N classes with Class Codes: CLASSCODE_1 CLASSCODE_2  … CLASSCODE_N
    // The STUDENT_ID must be unique.
    // The STUDENT_ID and STUDENT_NAME must satisfy the constraints stated below.
    // There must be N classes after reading N; otherwise, the entry is invalid.
    // Also, prints “successful” if insertion is successful and prints “unsuccessful” otherwise.
    // NAME identifier will be separated by quotes for parsing, e.g., "Josh Smith."
    // CLASSCODE identifiers will always be a single word, e.g., COP3530
    
// ------------------------------------
    
    bool remove(int STUDENT_ID);
    // Find and remove a specific student with UFID number: STUDENT_ID from the data structure.
    // If deletion is successful, print “successful.”
    // If the STUDENT_ID does not exist, print “unsuccessful.”

// ------------------------------------
    
    bool dropClass(int STUDENT_ID, int CLASSCODE);
    // Find and drop the class, CLASSCODE, for a given student.
    // Note: If we remove a CLASSCODE from a student with only that CLASSCODE, the student has 0 classes and should be dropped from the data structure.
    // Still prints “successful” in this case
    // Fails if a student with STUDENT_ID does not exist or if CLASSCODE does not exist.
    // Fails if a student with STUDENT_ID does not have CLASSCODE
    // prints “successful” if dropping is successful and prints “unsuccessful” otherwise.

// ------------------------------------

    bool replaceClass(int STUDENT_ID, int CLASSCODE_1, int CLASSCODE_2);
    // Find a student with UFID number: ID and replace CLASSCODE_1 with CLASSCODE_2 
    // Should fail if the student does not exist, does not have CLASSCODE_1, or already has CLASSCODE_2; or if there is no class with code CLASSCODE_2
    // prints “successful” if the replacement is successful and prints “unsuccessful” otherwise.

// ------------------------------------

    bool removeClass(int CLASSCODE);
    // Removes a class CLASSCODE from the schedule for all students.
    // Note: If we remove a CLASSCODE from a student with only that CLASSCODE and the student has 0 classes, then the student should be dropped from the data structure.
    // Prints the number of students the class was dropped from.
    // E.g., if 4 students were enrolled in COP3530 then “removeClass COP3530” would print "4".
    // Prints "unsuccessful" if the CLASSCODE is in an invalid format, the CLASSCODE does not exist, or no students have a given CLASSCODE.

// ------------------------------------

    bool toggleEdgesClose(N LOCATION_ID_X LOCATION_ID_Y ... LOCATION_ID_A LOCATION_ID_B);
    // Toggles the closure (soft delete) of N different edges.
    // Note: These edges are not being removed from the graph. It is simply closed until toggled back on.
    // Consecutive LOCATION_IDs will correspond to the same edges in this command:
    // E.g., "toggleEdgesClosure 2 5 6 9 10" would close 2 edges, the edge between 5 to 6 and 9 to 10.
    // If a given edge is already closed, this should open it, and if a given edge is open, this should close it.
    // You will always be given valid edges in this method.
    // prints  “successful” on completion.

// ------------------------------------

    bool checkEdgeState(LOCATION_ID_X LOCATION_ID_Y);
    // Checks whether a given edge is open, closed, or does not exist.
    // Prints “open” “closed” or “DNE” accordingly.

// ------------------------------------

    bool isConnected(LOCATION_ID_1 LOCATION_ID_2);
    // Checks if it's possible to travel between LOCATION_ID_1 and LOCATION_ID_2 using any of the available edges.
    // Prints “successful” if there is a path and “unsuccessful” if not.


// ------------------------------------

    bool printShortestEdges(int ID);
    // Prints the shortest walking time from a student's residence to each of their classes using only currently available edges.
    // You will be given a valid student ID
    // Note: This does not take into account the start/end time of the classes. Just the time it takes to get to them using available edges.
    // Output should include the route for each class:
    // Time For Shortest Edges: [Student Name]
    // [ClassCode1]: [Time]
    // [ClassCode2]: [Time]
    // If a class is currently unable to be reached, then total time should equal -1.
    // Time For Shortest Edges: Manav Sanghvi
    // COP3530: -1
    // The classes should be sorted in lexographical order. (E.g., COP3502 would come before COP3503).


// ------------------------------------

    bool printStudentZone(int ID);
    // A student’s “zone” is the minimum-cost set of edges required to connect their residence and all their classes' locations, based on their shortest-path routes.
    // You will be given a valid student ID
    // To calculate this, you must:
    // First: find the shortest path from the student’s residence to each of their classes using only currently accessible edges (Note: this is the same functionality as your printShortestEdges command). 
    // Second, create a sub-graph that contains all the vertices from all of those paths. Remaining edges must connect two nodes within this set of vertices.
    // Third, get the minimum spanning tree of this sub-graph. This is the “Student Zone.”
    // The output should be the total cost of this MST.
    // We will only test this on a valid subgraph (i.e., we will not test this when a student has no reachable classes).
    // Output Format:
    // Student Zone Cost For [Student Name]: X



// ------------Extra-Credit------------

    bool verifySchedule(int ID);
    // A student's schedule is only feasible if they can physically get from one class to the next in the allotted time.
    // For example, if COP3530 is from 10:40-11:30 and CDA3101 is from 11:45-12:35, but the shortest path from COP3530 to CDA3101 takes longer than 15 minutes, then the schedule is not feasible.
    // Note: the shortest path must use only available edges.
    // If the Time Gap between the classes is longer than or equal to the shortest path, we output “successful”
    // If the Time Gap between the classes is shorter than the shortest path, we print “unsuccessful”
    // In the output, the classes should be organized from the earliest start time to the latest start time, and you are checking the Time Gap between consecutive classes.
    // If you cannot make it from ClassCode1 to ClassCode2, still calculate for ClassCode2 to ClassCode3.
    // If a student has only 1 class, print “unsuccessful” otherwise, print:
    // Schedule Check for [Student Name]:
    // [ClassCode1] - [ClassCode2]: successful
    // [ClassCode2] - [ClassCode3]: unsuccessful


public:
    // Think about what helper functions you will need in the algorithm
    CampusCompass(); // constructor
    bool ParseCSV(const string &edges_filepath, const string &classes_filepath);
    bool ParseCommand(const string &command);
};