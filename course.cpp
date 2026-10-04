#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


// ======================================================
// EXCEPTION CLASSES
// ======================================================

class InvalidLogin
{
public:
    string message;

    InvalidLogin(string msg)
    {
        message = msg;
    }
};

class DuplicateUsername
{
public:
    string message;

    DuplicateUsername(string msg)
    {
        message = msg;
    }
};


class CourseNotFound
{
public:
    string message;

    CourseNotFound(string msg)
    {
        message = msg;
    }
};


class AlreadyRegistered
{
public:
    string message;

    AlreadyRegistered(string msg)
    {
        message = msg;
    }
};


// ======================================================
// COMMON FUNCTIONS
// ======================================================

void centerText(string text)
{
    const int WIDTH = 70;

    int spaces = (WIDTH - text.length()) / 2;

    if (spaces < 0)
        spaces = 0;

    cout << string(spaces, ' ') << text << endl;
}


void line()
{
    cout << "\t\t===================================================================" << endl;
}


// ======================================================
// COURSE CLASS
// ======================================================

class Course
{
private:
    string courseID;
    string courseName;
    int semester;
    int creditHours;

public:

    Course()
    {
        courseID = "";
        courseName = "";
        semester = 0;
        creditHours = 0;
    }


    Course(string id, string name, int sem, int credit)
    {
        courseID = id;
        courseName = name;
        semester = sem;
        creditHours = credit;
    }


    string getCode()
    {
        return courseID;
    }


    string getName()
    {
        return courseName;
    }


    int getSemester()
    {
        return semester;
    }


    int getCreditHours()
    {
        return creditHours;
    }


    void display()
    {
        cout << "\t\t" << courseID
             << "\t"
             << courseName
             << "\t"
             << creditHours << endl;
    }


    // Display all semester courses
    static void displayCourses()
    {
        int choice;

        while (true)
        {
            cout << endl;

            line();
            centerText("AVAILABLE COURSES");
            line();

            cout << endl;

            cout << "\t\t\t1. Semester 1";
            cout << "\n\t\t\t2. Semester 2";
            cout << "\n\t\t\t3. Semester 3";
            cout << "\n\t\t\t4. Semester 4";
            cout << "\n\t\t\t5. Semester 5";
            cout << "\n\t\t\t6. Semester 6";
            cout << "\n\t\t\t7. Semester 7";
            cout << "\n\t\t\t8. Semester 8";
            cout << "\n\t\t\t9. Back";

            cout << endl;

            cout << "\n\t\tEnter your choice: ";
            cin >> choice;


            if (choice == 9)
            {
                return;
            }


            if (choice < 1 || choice > 8)
            {
                centerText("Invalid choice!");
                continue;
            }


            showSemester(choice);
        }
    }


    // Display courses of selected semester
    static void showSemester(int semester)
    {
        Course courses[] =
        {
            // ================= SEMESTER 1 =================

            Course("BIT101CO",
                   "Fundamentals of IT",
                   1, 3),

            Course("BIT102HS",
                   "Mathematics-I",
                   1, 3),

            Course("BIT103HS",
                   "Technical Communication",
                   1, 3),

            Course("BIT104HS",
                   "Society and Ethics in IT",
                   1, 3),

            Course("BIT105CO",
                   "Computer Programming in C",
                   1, 3),

            Course("BIT106CO",
                   "Project-I",
                   1, 3),


            // ================= SEMESTER 2 =================

            Course("BIT151HS",
                   "Mathematics-II",
                   2, 3),

            Course("BIT152CO",
                   "Digital Logic",
                   2, 3),

            Course("BIT153HS",
                   "Discrete Structure",
                   2, 3),

            Course("BIT154CO",
                   "OOP in C++",
                   2, 3),

            Course("BIT155MS",
                   "Financial Management and Accounting",
                   2, 3),

            Course("BIT156CO",
                   "Project-II",
                   2, 3),


            // ================= SEMESTER 3 =================

            Course("BIT201HS",
                   "Numerical Methods",
                   3, 3),

            Course("BIT202CO",
                   "Microcontroller",
                   3, 3),

            Course("BIT203CO",
                   "Data Structure and Algorithm",
                   3, 3),

            Course("BIT204CO",
                   "Computer Network and Data Communication",
                   3, 3),

            Course("BIT205CO",
                   "System Analysis and Design",
                   3, 3),

            Course("BIT206CO",
                   "Project-III",
                   3, 3),


            // ================= SEMESTER 4 =================

            Course("BIT251CO",
                   "Computer Organization and Architecture",
                   4, 3),

            Course("BIT252HS",
                   "Probability and Statistics",
                   4, 3),

            Course("BIT253CO",
                   "Operating System",
                   4, 3),

            Course("BIT254CO",
                   "Database Management System",
                   4, 3),

            Course("BIT255CO",
                   "Programming in JAVA",
                   4, 3),

            Course("BIT256CO",
                   "Project-IV",
                   4, 3),


            // ================= SEMESTER 5 =================

            Course("BIT301HS",
                   "Research Methodology",
                   5, 3),

            Course("BIT302CO",
                   "Computer Graphics",
                   5, 3),

            Course("BIT303CO",
                   "Cryptography and Network Security",
                   5, 3),

            Course("BIT304CO",
                   "Web Technology",
                   5, 3),

            Course("BIT305CO",
                   "Internet of Things",
                   5, 3),

            Course("BIT306CO",
                   "Project-V",
                   5, 3),


            // ================= SEMESTER 6 =================

            Course("BIT351CO",
                   "Artificial Intelligence",
                   6, 3),

            Course("BIT352CO",
                   "Management Information System",
                   6, 3),

            Course("BIT353CO",
                   "Data Warehousing and Data Mining",
                   6, 3),

            Course("BIT354CO",
                   "Simulation and Modeling",
                   6, 3),

            Course("BIT355CO",
                   "Software Engineering",
                   6, 3),

            Course("BIT356CO",
                   "Project-VI",
                   6, 3),


            // ================= SEMESTER 7 =================

            Course("BIT401CO",
                   "Network Programming",
                   7, 3),

            Course("BIT402CO",
                   "Digital Governance",
                   7, 3),

            Course("SP701",
                   "Specialization-I",
                   7, 3),

            Course("SP702",
                   "Specialization-II",
                   7, 3),


            // ================= SEMESTER 8 =================

            Course("SP801",
                   "Specialization-III",
                   8, 3),

            Course("BIT801",
                   "Final Project / Internship",
                   8, 3)
        };


        int totalCourses = sizeof(courses) / sizeof(courses[0]);


        cout << endl;

        line();

        cout << "\t\t\t\tSEMESTER "
             << semester
             << " COURSES"
             << endl;

        line();

        cout << endl;

        cout << "\t\tCourse Code\tCourse Name\t\tCredit Hours"
             << endl;

        cout << "\t\t---------------------------------------------------------------"
             << endl;


        for (int i = 0; i < totalCourses; i++)
        {
            if (courses[i].getSemester() == semester)
            {
                courses[i].display();
            }
        }


        cout << endl;

        cout << "\t\tPress Enter to go back...";

        cin.ignore();
        cin.get();
    }
};


// ======================================================
// USER BASE CLASS
// ======================================================

class User
{
protected:
    string username;
    string password;

public:

    User()
    {
        username = "";
        password = "";
    }


    User(string u, string p)
    {
        username = u;
        password = p;
    }


    string getUsername()
    {
        return username;
    }


    bool validUsername(string username)
    {
        if (username.length() < 5)
            return false;


        for (int i = 0; i < username.length(); i++)
        {
            if (!isalnum(username[i]) &&
                username[i] != '_')
            {
                return false;
            }
        }

        return true;
    }


    bool validPassword(string password)
    {
        bool upper = false;
        bool lower = false;
        bool digit = false;
        bool special = false;


        if (password.length() < 8)
            return false;


        for (int i = 0; i < password.length(); i++)
        {
            if (isupper(password[i]))
                upper = true;

            else if (islower(password[i]))
                lower = true;

            else if (isdigit(password[i]))
                digit = true;

            else
                special = true;
        }


        return upper && lower && digit && special;
    }
};


// ======================================================
// STUDENT CLASS
// ======================================================

class Student : public User
{
private:

    int studentID;

    static int totalStudents;


    bool usernameExists(string username)
    {
        string savedUsername;
        string savedPassword;


        ifstream file("students.txt");


        if (!file.is_open())
        {
            return false;
        }


        while (file >> savedUsername >> savedPassword)
        {
            if (username == savedUsername)
            {
                file.close();

                return true;
            }
        }


        file.close();

        return false;
    }


public:

    Student()
    {
        studentID = 0;
    }


    Student(int id)
    {
        studentID = id;
        totalStudents++;
    }


    // ==================================================
    // SIGNUP
    // ==================================================

    void signUp()
    {
        string newUsername;
        string newPassword;


        cout << endl;

        line();
        centerText("STUDENT SIGNUP");
        line();


        // Username

        while (true)
        {
            cout << "\n\t\tCreate Username: ";
            cin >> newUsername;


            if (!validUsername(newUsername))
            {
                cout << "\n\t\tInvalid username!";
                cout << "\n\t\tUsername must contain at least 5 characters";
                cout << "\n\t\tand only letters, numbers or underscore.\n";

                continue;
            }


            if (usernameExists(newUsername))
            {
                cout << "\n\t\tUsername already exists!";
                cout << "\n\t\tPlease choose another username.\n";

                continue;
            }


            break;
        }


        // Password

        while (true)
        {
            cout << "\n\t\tCreate Password: ";
            cin >> newPassword;


            if (!validPassword(newPassword))
            {
                cout << "\n\t\tInvalid password!";
                cout << "\n\t\tPassword must contain:\n";
                cout << "\t\t- At least 8 characters\n";
                cout << "\t\t- Uppercase letter\n";
                cout << "\t\t- Lowercase letter\n";
                cout << "\t\t- Number\n";
                cout << "\t\t- Special character\n";

                continue;
            }


            break;
        }


        // Save account

        ofstream file("students.txt", ios::app);


        if (!file.is_open())
        {
            centerText("Error opening student file!");

            return;
        }


        file << newUsername << " "
             << newPassword << endl;


        file.close();


        username = newUsername;
        password = newPassword;


        totalStudents++;


        cout << endl;

        centerText("Signup successful!");
        centerText("You can now login.");
    }


    // ==================================================
    // LOGIN
    // ==================================================

    bool login()
    {
        string inputUsername;
        string inputPassword;

        string savedUsername;
        string savedPassword;


        cout << endl;

        line();
        centerText("STUDENT LOGIN");
        line();


        cout << "\n\t\tUsername: ";
        cin >> inputUsername;


        cout << "\t\tPassword: ";
        cin >> inputPassword;


        ifstream file("students.txt");


        if (!file.is_open())
        {
            centerText("No student account found.");
            centerText("Please signup first.");

            return false;
        }


        while (file >> savedUsername >> savedPassword)
        {
            if (inputUsername == savedUsername &&
                inputPassword == savedPassword)
            {
                username = inputUsername;
                password = inputPassword;


                file.close();


                cout << endl;

                centerText("Login Successful!");

                cout << "\t\tWelcome, "
                     << username
                     << "!"
                     << endl;


                return true;
            }
        }


        file.close();
        throw InvalidLogin("Invalid Username or Password!");
    }


    // ==================================================
    // STUDENT DASHBOARD
    // ==================================================

    void dashboard()
    {
        int choice;


        while (true)
        {
            cout << endl;

            line();
            centerText("STUDENT DASHBOARD");
            line();


            cout << endl;

            cout << "\t\t\t1. View Courses";
            cout << "\n\t\t\t2. Register Course";
            cout << "\n\t\t\t3. View Profile";
            cout << "\n\t\t\t4. Logout";


            cout << endl;


            cout << "\n\t\tEnter your choice: ";
            cin >> choice;


            switch (choice)
            {
                case 1:

                    Course::displayCourses();

                    break;


                case 2:

                    registerCourse();

                    break;


                case 3:

                    displayStudent(*this);

                    break;


                case 4:

                    centerText("Logging out...");

                    return;


                default:

                    centerText("Invalid choice!");
            }
        }
    }


    // ==================================================
    // REGISTER COURSE
    // ==================================================

    void registerCourse()
    {
        string code;

        cout << endl;

        line();
        centerText("COURSE REGISTRATION");
        line();


        cout << "\n\t\tEnter Course Code: ";
        cin >> code;


        // List of courses

        Course courses[] =
        {
            Course("BIT101CO", "Fundamentals of IT", 1, 3),
            Course("BIT102HS", "Mathematics-I", 1, 3),
            Course("BIT103HS", "Technical Communication", 1, 3),
            Course("BIT104HS", "Society and Ethics in IT", 1, 3),
            Course("BIT105CO", "Computer Programming in C", 1, 3),
            Course("BIT106CO", "Project-I", 1, 3),

            Course("BIT151HS", "Mathematics-II", 2, 3),
            Course("BIT152CO", "Digital Logic", 2, 3),
            Course("BIT153HS", "Discrete Structure", 2, 3),
            Course("BIT154CO", "OOP in C++", 2, 3),
            Course("BIT155MS", "Financial Management and Accounting", 2, 3),
            Course("BIT156CO", "Project-II", 2, 3),

            Course("BIT201HS", "Numerical Methods", 3, 3),
            Course("BIT202CO", "Microcontroller", 3, 3),
            Course("BIT203CO", "Data Structure and Algorithm", 3, 3),
            Course("BIT204CO", "Computer Network and Data Communication", 3, 3),
            Course("BIT205CO", "System Analysis and Design", 3, 3),
            Course("BIT206CO", "Project-III", 3, 3),

            Course("BIT251CO", "Computer Organization and Architecture", 4, 3),
            Course("BIT252HS", "Probability and Statistics", 4, 3),
            Course("BIT253CO", "Operating System", 4, 3),
            Course("BIT254CO", "Database Management System", 4, 3),
            Course("BIT255CO", "Programming in JAVA", 4, 3),
            Course("BIT256CO", "Project-IV", 4, 3),

            Course("BIT301HS", "Research Methodology", 5, 3),
            Course("BIT302CO", "Computer Graphics", 5, 3),
            Course("BIT303CO", "Cryptography and Network Security", 5, 3),
            Course("BIT304CO", "Web Technology", 5, 3),
            Course("BIT305CO", "Internet of Things", 5, 3),
            Course("BIT306CO", "Project-V", 5, 3),

            Course("BIT351CO", "Artificial Intelligence", 6, 3),
            Course("BIT352CO", "Management Information System", 6, 3),
            Course("BIT353CO", "Data Warehousing and Data Mining", 6, 3),
            Course("BIT354CO", "Simulation and Modeling", 6, 3),
            Course("BIT355CO", "Software Engineering", 6, 3),
            Course("BIT356CO", "Project-VI", 6, 3),

            Course("BIT401CO", "Network Programming", 7, 3),
            Course("BIT402CO", "Digital Governance", 7, 3),
            Course("SP701", "Specialization-I", 7, 3),
            Course("SP702", "Specialization-II", 7, 3),

            Course("SP801", "Specialization-III", 8, 3),
            Course("BIT801", "Final Project / Internship", 8, 3)
        };


        int totalCourses =
            sizeof(courses) / sizeof(courses[0]);


        bool found = false;


        for (int i = 0; i < totalCourses; i++)
        {
            if (courses[i].getCode() == code)
            {
                found = true;


                // Check previous registration

                ifstream checkFile("registrations.txt");

                string savedUser;
                string savedCourse;


                if (checkFile.is_open())
                {
                    while (checkFile >> savedUser >> savedCourse)
                    {
                        if (savedUser == username &&
                            savedCourse == code)
                        {
                            checkFile.close();

                            throw AlreadyRegistered(
                                "You are already registered for this course!"
                            );
                        }
                    }


                    checkFile.close();
                }


                // Save registration

                ofstream file(
                    "registrations.txt",
                    ios::app
                );


                if (!file.is_open())
                {
                    centerText(
                        "Error opening registration file!"
                    );

                    return;
                }


                file << username << " "
                     << code << endl;


                file.close();


                cout << endl;

                centerText(
                    "Course registered successfully!"
                );


                cout << "\t\tCourse: "
                     << courses[i].getName()
                     << endl;


                break;
            }
        }


        if (!found)
        {
            throw CourseNotFound(
                "Course code does not exist!"
            );
        }
    }


    // ==================================================
    // STATIC FUNCTION
    // ==================================================

    static void showTotalStudents()
    {
        cout << "\n\t\tTotal Students: "
             << totalStudents
             << endl;
    }


    // ==================================================
    // FRIEND FUNCTION
    // ==================================================

    friend void displayStudent(Student s);
};


// Static variable

int Student::totalStudents = 0;


// ======================================================
// FRIEND FUNCTION
// ======================================================

void displayStudent(Student s)
{
    cout << endl;

    line();
    centerText("STUDENT PROFILE");
    line();


    cout << endl;

    cout << "\t\tUsername: "
         << s.username
         << endl;


    cout << "\t\tStudent ID: "
         << s.studentID
         << endl;


    Student::showTotalStudents();
}


// ======================================================
// ADMIN CLASS
// ======================================================

class Admin : public User
{
private:

    string correctUsername;
    string correctPassword;


public:

    Admin()
    {
        correctUsername = "admin@143";
        correctPassword = "adminlogins@123";
    }


    // ==================================================
    // ADMIN LOGIN
    // ==================================================

    bool login()
    {
        string inputUsername;
        string inputPassword;


        cout << endl;

        line();
        centerText("ADMIN LOGIN");
        line();


        cout << "\n\t\tUsername: ";
        cin >> inputUsername;


        cout << "\t\tPassword: ";
        cin >> inputPassword;


        if (inputUsername != correctUsername ||
            inputPassword != correctPassword)
        {
            throw InvalidLogin("Invalid Admin Username or Password!"); // exception;
        }

        username = inputUsername;
        password = inputPassword;
        cout << endl;
        centerText("Login Successful!");
        centerText("Welcome, Admin!");


        return true;
    }


    // ==================================================
    // ADMIN MENU
    // ==================================================

    void menu()
    {
        int choice;


        while (true)
        {
            cout << endl;

            line();
            centerText("ADMIN MENU");
            line();


            cout << endl;

            cout << "\t\t\t1. Manage Students";
            cout << "\n\t\t\t2. Manage Courses";
            cout << "\n\t\t\t3. Manage Faculty";
            cout << "\n\t\t\t4. View Enrollments";
            cout << "\n\t\t\t5. Logout";


            cout << endl;


            cout << "\n\t\tEnter your choice: ";
            cin >> choice;


            switch (choice)
            {
                case 1:

                    cout << endl;

                    centerText(
                        "STUDENT MANAGEMENT"
                    );

                    Student::showTotalStudents();

                    break;


                case 2:

                    Course::displayCourses();

                    break;


                case 3:

                    cout << endl;

                    centerText(
                        "FACULTY MANAGEMENT"
                    );

                    cout << "\n\t\tFaculty:";
                    cout << "\n\t\t1. Information Technology";
                    cout << "\n\t\t2. Engineering";
                    cout << "\n\t\t3. Business";
                    cout << "\n\t\t4. Medicine";

                    cout << endl;

                    break;


                case 4:

                    viewEnrollments();

                    break;


                case 5:

                    centerText(
                        "Admin logged out successfully."
                    );

                    return;


                default:

                    centerText(
                        "Invalid choice!"
                    );
            }
        }
    }


    // ==================================================
    // VIEW ENROLLMENTS
    // ==================================================

    void viewEnrollments()
    {
        ifstream file("registrations.txt");


        if (!file.is_open())
        {
            centerText(
                "No enrollment records found."
            );

            return;
        }


        string studentUsername;
        string courseCode;


        cout << endl;

        line();
        centerText("STUDENT ENROLLMENTS");
        line();


        cout << endl;


        while (file >> studentUsername >> courseCode)
        {
            cout << "\t\tStudent: "
                 << studentUsername
                 << endl;


            cout << "\t\tCourse Code: "
                 << courseCode
                 << endl;


            cout << "\t\t-----------------------------------"
                 << endl;
        }


        file.close();
    }
};


// ======================================================
// STUDENT PORTAL
// ======================================================

void studentPortal(Student &student)
{
    int choice;


    while (true)
    {
        cout << endl;

        line();
        centerText("STUDENT PORTAL");
        line();


        cout << endl;

        cout << "\t\t\t1. Signup";
        cout << "\n\t\t\t2. Login";
        cout << "\n\t\t\t3. Exit";


        cout << endl;


        cout << "\n\t\tEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:

                try
                {
                    student.signUp();
                }

                catch (DuplicateUsername e)
                {
                    centerText(e.message);
                }

                break;


            case 2:

                try
                {
                    if (student.login())
                    {
                        student.dashboard();
                    }
                }

                catch (InvalidLogin e)
                {
                    cout << endl;

                    centerText(e.message);
                }

                break;


            case 3:

                centerText(
                    "Returning to main menu..."
                );

                return;


            default:

                centerText(
                    "Invalid choice. Try again!"
                );
        }
    }
}


// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    Student student;
    Admin admin;


    int choice;
    int attempts = 3;


    while (attempts > 0)
    {
        cout << endl;

        line();

        centerText(
            "UNIVERSITY COURSE REGISTRATION SYSTEM"
        );

        line();


        cout << endl;

        cout << "\t\t\t1. View Courses";
        cout << "\n\t\t\t2. Student Login";
        cout << "\n\t\t\t3. Admin Login";
        cout << "\n\t\t\t4. Exit";


        cout << endl;


        cout << "\n\t\tEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:

                Course::displayCourses();

                break;


            case 2:

                studentPortal(student);

                break;


            case 3:

                try
                {
                    if (admin.login())
                    {
                        admin.menu();
                    }
                }

                catch (InvalidLogin e)
                {
                    cout << endl;

                    centerText(e.message);
                }

                break;


            case 4:

                cout << endl;

                centerText(
                    "Thank you for using the system!"
                );

                return 0;


            default:

                attempts--;

                cout <<"\n\t\tAttempts left: "<< attempts<< endl;
                centerText("Invalid choice. Please try again.");

                break;
        }
    }
    cout << endl;
    centerText("Program exiting due to invalid attempts." );
    centerText("Please reopen the program.");
    return 0;
}