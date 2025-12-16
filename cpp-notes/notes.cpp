// TODO: classes, operator overloading, inline function, function pointers,
//       preprocessor arithmetic, ways to recieve multidimensional arrays to functions.
// Straight Review: errors, enum, structs, strings, casting.

// ------------------------------------------------------------------------------------------------------------------------
// Section: File Structure
// ------------------------------------------------------------------------------------------------------------------------

// --Preprocessor Directives--
// Description: Lines marked by a hashtag are resolved before the compilation process begins. The
//              include directive replaces itself with the file specified.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "class.h"

// --"using" Keyword--
// Description: The "using" keyword makes specified facilities available throughout the execution
//              of the program. Below, the "cout" entity from the standard library is specified.
using std::cout;
using std::endl;
using std::string;

// ------------------------------------------------------------------------------------------------------------------------
// Section: Namespace
// ------------------------------------------------------------------------------------------------------------------------

// --Namespaces--
// Description: Variables, functions, and classes can be declared within a namespace. They can be accessed
//              with the namespace identifier and scope resolution operator.
namespace TestSpace {
    
    // Declare a variable.
    int testSpaceNum = 0;

    // Declare a function.
    int TestFunc() {
        return 0;
    }
}

// --Extending a Namespace--
// Description: A namespace can be extended by redeclaring it. The declarations within the redeclared namespace are
//              added to the original. This is how "include" statements add items to std.
namespace TestSpace {

    // Declare a class.
    class TestClass {
        private:
            int _testNum;
        public:
            TestClass(int userNum = 0);
            int GetNum() const;
    };

    // Define the class functions.
    TestClass::TestClass(int userNum): _testNum(userNum) {};
    int TestClass::GetNum() const { return _testNum; };
}

// --Using Namespaces--
// Description: You can use the "using" keyword to make all variables within a namespace accessable without the
//              scope resolution operator.
// Making a Specific Identifier Accessable: To make a single identifier accessable use "using Name::identifier"
using namespace TestSpace;

// ------------------------------------------------------------------------------------------------------------------------
// Section: Functions
// ------------------------------------------------------------------------------------------------------------------------

// --Basic Functions--
// Description: Basic functions start with a return type. Next, a name for the function is specified. Finally,
//              a list of type-name parameters to be used within the function are specified. A function header
//              or definition must be placed above any called function in a program or else it will not be visible.
// Parameters vs. Arguments: Parameters are variables within the function definition. Arguments are the actual values 
//                           passed to a function when it is invoked.
bool Intersects(double x1, double y1, double r1,
                double x2, double y2, double r2);

// --Passing By Reference--
// Description: Parameters within a function can be passed by reference using the & operator. This means that the value
//              passed to that parameter will remain modified outside of the function.
void ForLoop(int& retVal);

// --Const Parameters--
// Description: Parameters in a function definition declared as const undergo a contract. The compiler will not allow const
//              parameters to be modified within the function. This is useful to avoid copying complex objects.
string WhileLoop(const string& charVal);

// --Passing By Pointer--
// Description: Parameters within a function can be passed by pointer. This means that the value passed to that
//              parameter will remain modified outside of the function when that value is dereferenced. Passing by
//              reference is safer.
void IfSwitch(int* retVal);

// --Passing an Array--
// Description: An array can be passed to a function using a pointer to the type it holds and the size of the array.
//              Additionally, if the size of the array is fixed, an alternatve single parameter syntax can be used.
// Function Overloading: Functions can be overloaded by specifying functions with the same name but different parameter
//                       types and numbers.
// Prevent Modification: Add const to the array identifier to prevent modification.
void TestNamespace(int* arr, int arrSize);
void TestNamespace(int (&arr)[5]);


//Function pointer

// --The Main Function--
// Description: A function which serves as the entry point for a C++ program. The argument argc is the number of
//              command line arguments supplied to the function. The argument argv is an array of C style strings
//              representing the arguments provided.
int main(int argc, char* argv[]) {

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Types
    // ------------------------------------------------------------------------------------------------------------------------

    // --Variables--
    // General Rules: A variable name must begin with a digit or an underscore and contain no illegal characters.
    {
        int tempVar100 = 0;
        int _tempVar = 0;
    }

    // --The Integer Type--
    // Description: A type which represents a whole number.
    // Base Ten: Specified normally. Example: int hundred = 100.
    // Base Eight: Specified by appending a zero to the front of a number. In this case, the number
    //             can only contain digits zero through seven. Example: int hundred = 0144.
    // Base Sixteen: Specified by appending "0x" to the front of a number. Contains alphabetical
    //               characters to represent numbers past ten. Example: int hundred = 0x64.
    // Scientific Notation: You can write scientific notation by baseEzeros. Example: int hundred = 1E2.
    // Long: An integer type that can hold larger values.
    // Short: An integer type that holds smaller values.
    unsigned int testNum = 0;
    cout << "Test " << testNum << ": testNum Initilization [" << testNum << "]." << endl;
    testNum++;

    // --Floating Point Types--
    // Description: A type which represents a number with a fractional component.
    // Float vs. Double: The double type has double the precicion compared to the float type.
    cout << std::setprecision(50);
    cout << "Test " << testNum << ": Floating Point Numbers [" << 5.0 / 3.0 << "," << (float)(5.0 / 3.0) << "]." << endl;
    testNum++;

    // --The Bool Type--
    // Description: A type which contains two distinct values representing true and false.
    {
        bool truthVar = true;
        cout << "Test " << testNum << ": Bool Data Type [" << truthVar << "]." << endl;
        testNum++;
    }

    // --The Char Type--
    // Description: A type which represents ASCII characters. Specified using an integer or a character with single quotes.
    {
        char char1 = 'A';
        char char2 = ' ';
        char char3 = char1 + char2;
        char char4 = 63;
        cout << "Test " << testNum << ": Char Data Type [";
        cout << char1 << ", " << char3 << ", " << char4 << "]." << endl;
        testNum++;
    }

    // --Custom Struct Types--
    // Description: Structs are like classes without public and private data members, and functions.
    // Declaration Example: struct MyStruct { int num; };
    // Anonamous Structs Example: struct { int num; } var1, var2;
    {
        struct StructOne {
            int num;
        };
        StructOne myStructOne;
        myStructOne.num = 0;

        struct {
            int numOne;
            int numTwo;
        }
        myStructTwo = {0, 1};

        cout << "Test " << testNum << ": Struct Data Type [";
        cout << myStructOne.num << ", " << myStructTwo.numOne << ", " << myStructTwo.numTwo << "]." << endl;
        testNum++;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Arrays
    // ------------------------------------------------------------------------------------------------------------------------

    // --Array Declarations--
    // Bracket Syntax: Declare the array name as name[]. You can also declare the number of elements within the brackets.
    // Initializing Elements: Elements are initialized within braces on the right side of the assignment operator.
    // Two Dimentional Arrays: Initialized with two sets of brackets.
    {
        int arr1[] = {0, 1, 2};
        int arr2[3];
        arr2[0] = 0; arr2[1] = 1; arr2[2] = 2;
        int arr3[3][3] = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
        cout << "Test " << testNum << ": Arrays [";
        cout << arr1[0] + arr1[1] + arr1[2] << ", ";
        cout << arr2[0] + arr2[1] + arr2[2] << ", ";
        cout << arr3[0][0] + arr3[0][1] + arr3[0][2] << "]." << endl;
        testNum++;
    }

    // --Array Type--
    // Pointer: An array's variable name is a pointer to the first element of the array.
    {
        int arr1[3] = {0, 1, 2};
        cout << "Test " << testNum << ": Array Pointer Syntax [";
        cout << *(arr1) << ", " << *(arr1 + 1) << ", " << *(arr1 + 2) << "]." << endl;
        testNum++;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Operators
    // ------------------------------------------------------------------------------------------------------------------------

    // --Top Level Operators--
    // Postfix Increment and Decrement: The symbols used are ++ and --. Placed after a variable. (->)
    // Not: The symbol used is !. Resolves to the opposite of a boolean expression. (<-)
    // Bitwise Not: The symbol used is ~. Resolves each bit of an integer to its opposite. (<-)
    {
        unsigned short allOnes = 0xffff;
        allOnes = ~allOnes;
        cout << "Test " << testNum << ": Bitwise Not [" << allOnes << ", " << !allOnes << "]." << endl;
        testNum++;
    }
    // C-Style Cast: Cast a type to a different type with (type). Primitive numeric types are truncated toward zero. (<-)
    {
        float floatCast = 5.5;
        int intCast = (int)floatCast;
        cout << "Test " << testNum << ": Float Casted To Int [" << floatCast << ", " << intCast << "]." << endl;
        testNum++;
    }
    // Prefix Increment and Decrement: The symbols used are ++ and --. Placed before a variable. (<-)
    {
        // Prefix: The value of i is incremented immediately and and used to evaluate the expression that it is in.
        int testVar = 0;
        int i = 1;
        while (--i) {
            testVar++;
        }
        cout << "Test " << testNum << ": Prefix Vs. Postfix Incrementation [" << testVar << ", ";
        // Postfix: The value of i is incremented following the expression that it is in.
        testVar = 0;
        i = 1;
         while (i--) {
            testVar++;
        }
        cout << testVar << "]." << endl;
        testNum++;
    }
    // Unary Plus and Minus: The symbols are + and -. Place before a type to apply the proper sign.
    // Sizeof Operator: The symbol used is sizeof(). Place a variable or type inside of the parenthesis to get its size.
    {
        int numArr[] = {0, 1, 2, 3};
        cout << "Test " << testNum << ": Sizeof Operator [" << numArr << ", ";
        cout << (numArr + 1) << ", " << sizeof(numArr[0]) << "]." << endl;
        testNum++;
    }

    // --Tier Two Operators--
    // Multiplication: The symbol used is *. Multiplies two numbers together. (->)
    // Division: The symbol used is /. Divides two numbers. Division between floating point numbers is precise.
    //           Division between integers is truncated toward zero. (->)
    // Modulo: The symbol used is %. Modulo only works with integer types. Returns the remainder of division. (->)
    cout << "Test " << testNum << ": Multiplication, Division, Modulo [";
    cout << 5 * 2 << ", " << 5 / 2 << ", " << 5 / 2.0 << ", " << 5.0 / 2.0 << ", " << 5 % 2 << "]." << endl;
    testNum++;

    // --Tier Three Operators--
    // Binary Plus: The symbol used is +. Adds two numbers together. (->)
    // Binary Minus: The symbol used is -. Subtracts two numbers. (->)
    cout << "Test " << testNum << ": Binary Plus and Minus [";
    cout << 5.5 + 1 << ", " << 10 - 2.5 << "]." << endl;
    testNum++;

    // --Tier Four Operators--
    // Left Bitshift: The symobl used is <<. Shifts the bits within a type left by the specified ammount. (->)
    // Right Bitshift: The symobl used is >>. Shifts the bits within a type right by the specified ammount. (->)
    {
        unsigned short testVar = 0x0001;
        testVar = testVar << 1;
        cout << "Test " << testNum << ": Bitshift Operation [";
        cout << testVar << "]." << endl;
        testNum++;
    }

    // --Tier Five Operators--
    // Less Than: The symbol used is <. Resolves to true if lhs is less than rhs. (->)
    // Greater Than: The symbol used is >. Resolves to true if lhs is greater than rhs. (->)
    // Less Than or Equal: The symbol used is <=. Resolves to true if lhs is less than or equal to rhs. (->)
    // Greater Than: The symbol used is >=. Resolves to true if lhs is greater than or equal to rhs. (->)
    cout << "Test " << testNum << ": LT, GT, LTE, GTE [";
    cout << (5 < 10) << ", " << (5 > 10) << ", " << (5 <= 5) << ", " << (5 >= 5) << "]." << endl;
    testNum++;

    // --Tier Six Operators--
    // Equal: The symbol used is ==. Resolves to true if lhs is equal to rhs. (->)
    // Not Equal: the symbol used is !=. Resolves to true if lhs does not equal rhs. (->)
    cout << "Test " << testNum << ": Equal and Not Equal [";
    cout << (5 == 10) << ", " << (5 != 10) << "]." << endl;
    testNum++;

    // --Tier Seven Operators--
    // Bitwise And: The symbol used is &. If both bits are one, the result is one. Else the result is zero. (->)
    {
        unsigned short allOnes = 0xffff;
        unsigned short compNum = 0x000f;
        cout << "Test " << testNum << ": Bitwise And [" << (allOnes & compNum) << "]." << endl;
        testNum++;
    }

    // --Tier Eight Operators--
    // Bitwise Xor: The symbol used is ^. If only one bit is one, thr result is one. (->)
    {
        unsigned short allZeros = 0x0000;
        unsigned short compNum = 0x0005;
        cout << "Test " << testNum << ": Bitwise Xor [" << (allZeros ^ compNum) << "]." << endl;
        testNum++;
    }

    // --Tier Nine Operators--
    // Bitwise Or: The symbol used is |. If at least one bit is one, the result is one. Eles the result is zero. (->)
    {
        unsigned short allZeros = 0x0000;
        unsigned short compNum = 0x000f;
        cout << "Test " << testNum << ": Bitwise Or [" << (allZeros | compNum) << "]." << endl;
        testNum++;
    }

    // --Tier Ten Operators--
    // And: The symbol used is &&. Resolves to true if both sides of the expression are one. (->)
    cout << "Test " << testNum << ": Logical And [" << (true && true) << ", " << (true && false) <<  "]." << endl;
    testNum++;

    // --Tier Eleven Operators--
    // Or: The symbol used is ||. Resolves to true if one side of the expression is one. (->)
    cout << "Test " << testNum << ": Logical Or [" << (true || true) << ", " << (true || false) <<  "]." << endl;
    testNum++;
    
    // --Tier Twelve Operators--
    // Assignment Operator: The symbol used is =. Sets lhs equal to a copy of rhs. (<-)
    // Shorthand Addition Operator: The symbol used is +=. Sets lhs equal to itself plus rhs. (<-)
    // Shorthand Subtraction Operator: The symbol used is -=. Sets lhs equal to itself minus rhs. (<-)
    // Shorthand Multiplication Operator: The symbol used is *=. Sets lhs equal to itself times rhs. (<-)
    // Shorthand Division Operator: The symbol used is /=. Sets lhs equal to itself divided by rhs. (<-)
    // Shorthand Modulo Operator: The symbol used is %=. Sets lhs equal to itself mod rhs. (<-)
    // Shorthand Bitwise And Operator: The symbol used is &=. Sets lhs equal to itself operated on by bitwise and with rhs. (<-)
    // Shorthand Bitwise Xor Operator: The symbol used is ^=. Sets lhs equal to itself operated on by bitwise xor with rhs. (<-)
    // Shorthand Bitwise Or Operator: The symbol used is |=. Sets lhs equal to itself operated on by bitwise or with rhs. (<-)
    // Shorthand Bitshift Operator: The symbols used are <<= and >>=. Shifts the bits in lhs by rhs in the given direction. (<-)
    {
        int num1 = 1, num2 = 2, num3 = 3;
        cout << "Test " << testNum << ": Assignment Shenanigans [" << (num1 *= num2 += num3) << ", ";
        cout << (num3 += (num2 <<= 1)) << ", " << num1 << ", " << num2 << ", " << num3 <<  "]." << endl;
        testNum++;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Dynamic Memory
    // ------------------------------------------------------------------------------------------------------------------------

    // --New Operator--
    // Description: Used to dynamically alocate memory during program runtime.
    // new[] Operator: Used to dynamically alocate memory for an array durring program runtime. The brackets go to the right
    //                 of the variable name.
    {
        int* m1 = new int;
        int* m2 = new int[3];
        *m1 = 0;
        m2[0] = 0; m2[1] = 1; m2[2] = 2;
        cout << "Test " << testNum << ": New Operator [" << *m1 <<  ", ";
        cout << m2[0] << ", " << m2[1] << ", " << m2[2] << "]." << endl;
        testNum++;

        // --Delete Operator--
        // Description: Frees memory that was allocated durring program runtime.
        // delete[] Operator: This verson must be used when contiguous memory was alocated.
        delete m1;
        delete[] m2;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: String Operations
    // ------------------------------------------------------------------------------------------------------------------------

    // --String Compare Method--
    // Description: Returns zero if strings are equal. Returns positive if caller is greater. Returns negative if
    //              caller is smaller. Think of it as caller - other.
    // Lovercase vs. Uppercase: Lowercase is greater than uppercase.
    {
        string str = "Bob";
        cout << "Test " << testNum << ": String Compare [" << str.compare("Bob") << ", ";
        cout << str.compare("Aob") << ", " << str.compare("Bobs") << "]." << endl;
        testNum++;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Function Tests
    // ------------------------------------------------------------------------------------------------------------------------

    // --Intersects Function Test--
    cout << "Test " << testNum << ": Intersects Function [";
    cout << Intersects(0,0,5, 4,0,3) << ", ";
    cout << Intersects(0,0,3, 2,2,3) << ", ";
    cout << !Intersects(0,0,1, 5,0,1) << ", ";
    cout << !Intersects(0,0,5, 1,0,1) << ", ";
    cout << Intersects(0,0,2, 4,0,2) << ", ";
    cout << Intersects(0,0,5, 3,0,2) << "]." << endl;
    testNum++;

    // --ForLoop Function Test--
    {
        int retVal = 0;
        ForLoop(retVal);
        cout << "Test " << testNum << ": ForLoop Function [" << retVal << "]." << endl;
        testNum++;
    }

    // --WhileLoop Function Test--
    cout << "Test " << testNum << ": WhileLoop Function [" << WhileLoop("0").length() << "]." << endl;
    testNum++;

    // --IfSwitch Function Test--
    {
        int num1 = 1; int num2 = 2; int num3 = 3;
        IfSwitch(&num1); IfSwitch(&num2); IfSwitch(&num3);
        cout << "Test " << testNum << ": IfSwitch Function [" << num1 << ", " << num2 << ", " << num3 << "]." << endl;
        testNum++;
    }

    // --TestNamespacs Function Test--
    {
        int testArr1[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        int testArr2[5] = {1, 1, 1, 1, 1};
        TestNamespace(testArr1, 10); // 7
        TestNamespace(testArr2); // -3
        cout << "Test " << testNum << ": testNamespace Function [" << testArr1[9] << ", " << testArr2[4] << "]." << endl;
        testNum++;
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Section: Class Tests
    // ------------------------------------------------------------------------------------------------------------------------

    // --OverloadedClass Test--
    {
        OverloadedClass oC1(100);
        OverloadedClass oC2(0);
        ~oC1;
        oC2++;
        ++oC2;
        oC1(2);
        cout << "Test " << testNum << ": OverloadedClass Test [" << (oC1 % oC2) << ", ";
        cout << (oC1 || oC2) << ", "<< !oC1 << "]." << endl;
        testNum++;
    }

    // --BaseClass Class Test--
    int initArr[3] = {1, 2, 3};
    BaseClass bC1(initArr, 3);
    BaseClass bC2(bC1);
    cout << "Test " << testNum << ": BaseClass Test [" << bC1.BaseSum() + bC2.BaseSum() << "]." << endl;
    testNum++;

    // --PrivateSubClass Class Test--
    PrivateSubClass sC1(initArr, 3, EnumClass::ZERO);
    cout << "Test " << testNum << ": PrivateSubClass Test ";
    sC1.Print();
    cout << "." << endl;
    testNum++;
    
    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------
// Section: Intersects Function
// ------------------------------------------------------------------------------------------------------------------------

// --Intersects Function--
// Description: A function that calculates if two circles intersect.
// Parameters:
//             - x1: x coordinate of first circle.
//             - y1: y coordinate of first circle.
//             - r1: Radius of first circle.
//             - x2: x coordinate of second circle.
//             - y2: y coordinate of second circle.
//             - r2: Radius of second circle.
// Return: Boolean value set to true if the circles intersect.
bool Intersects(double x1, double y1, double r1, double x2, double y2, double r2) {

    // Works for circles that are not contained.
    double centerDist = pow(fabs(x1 - x2), 2) + pow(fabs(y1 -y2), 2);
    centerDist = sqrt(centerDist);

    // Find the larger and smaller radius.
    double largerRadius = r1;
    double smallerRadius = r2;
    if (r1 < r2) {

        largerRadius = r2;
        smallerRadius = r1;
    }

    // This activates if the center of one circle is within the other circle.
    if (centerDist < largerRadius) {

        double radiusDiff = largerRadius - centerDist;
        return !(smallerRadius < radiusDiff);
    }

    // Otherwise this statement works for disjoint circles.
    return (r1 + r2) >= centerDist;
}

// ------------------------------------------------------------------------------------------------------------------------
// Section: Loops
// ------------------------------------------------------------------------------------------------------------------------

// --ForLoop Function--
// Description: A function that displays the capabilities of the C++ for loop.
// Parameters:
//             - retVal: An integer passed by reference which will be incremented within the function.
// Return: Void.
void ForLoop(int& retVal) {

    // --Clasic For Loop--
    // Description: Repeats inner code based on an initialized value, condition, and manipulator.
    // Initilization Phase: In the first section of the for loop, a value to control the loop is initialized.
    // Condition Phase: Each time before entering the for loop, the middle condition section is checked. If the condition
    //                  is not met, then the loop is not entered.
    // Manipulation Phase: In the last section of the for loop, a statement which manipulates the initialized value
    //                     is specified.
    for (int i = 0; i < 10; i++) {
        
        retVal++;
    }

    // --Infinite loop--
    // Description: If the condition section of the for loop is ommited, the loop becomes infinite. The break keyword
    //              must be used to escape. Initilization and manipulation may be ommited but must be handled manualy
    //              elsewhere to avoid an infinite loop.
    {
        int i = 0;
        for (;;) {

            retVal++;

            if (i == 9)
                break;
            i++;
        }
    }
}

// --WhileLoop Function--
// Description: A function that displays the capabilities of the C++ while loop.
// Parameters:
//             - charVal: A constant string which will be used to make the function return value. 
// Return: String created by the WhileLoop function.
string WhileLoop(const string& charVal) {

    string retVal = "";

    // --Classic While Loop--
    // Description: A loop that continues to execute while the condition is true.
    int i = 0;
    while(i < 5) {

        retVal = retVal + charVal;
        i++;
    }

    // --Do While Loop--
    // Description: A loop that executes once and then continues to execute based on a condition.
    do {

        retVal = retVal + retVal;
    } while(i < 5);

    return retVal;
}

// --IfSwich Function--
// Description: A function that displays the capabiliteis of C++ if and switch statements.
// Parameters:
//             - retVal: A pointer to an integer used to provide a function return value.
// Return: Void.
void IfSwitch(int* retVal) {

    // --Classic If Statement--
    // Description: A statement in which different branches execute based on provided conditions. The "if" keyword
    //              is always used to start the chain. The "else if" statement is used specify additional conditions
    //              which are part of the same chain. The "else" keyword executes if no other conditions in the 
    //              statement are met.
    if (*retVal == 1) {

        *retVal = 100;
    } else if (*retVal == 2) {

        *retVal = 200;
    } else {

        *retVal = 300;
    }

    // --Switch Statement--
    // Description: A statement which an integer value is specified and different branches are executed based on the
    //              provided value. The "case" keyword is used to specify expected integer values. The "break" keyword
    //              specifies when the code to execute ends.
    switch(*retVal) {
        
        case 100:
            *retVal += 10;
            break;

        case 200:
            *retVal += 20;
            break;

        case 300:
            *retVal += 30;
            break;

        default:
            break;
    }

    // --Layering Switch Cases--
    // Description: Switch cases can be layered so that multiple cases lead to the same segment of code.
    switch(*retVal) {
        
        case 110:
        case 220:
        case 330:
            *retVal += 1000;
            break;

        default:
            break;
    }
}

// --TestNamespace Function--
// Description: A function which tests the TestSpace namespace.
// Parameters:
//             - arr: An array of integers passed to the function.
//             - arrSize: The size of the array passed to the function.
// Return: Void.
void TestNamespace(int* arr, int arrSize) {
    
    // Reassign the first three elements.
    TestClass testVar;
    arr[0] = testVar.GetNum();
    arr[1] = testSpaceNum;
    arr[2] = TestFunc();
    
    // Sum the elements.
    int arrSum = 0;
    for (int i = 0; i < arrSize; i++) {
        arrSum += arr[i];
    }

    // Reassign the last element.
    arr[arrSize - 1] = arrSum;
}

// --TestNamespace Function--
// Description: A function which tests the TestSpace namespace.
// Parameters:
//             - arr: An array of integers passed to the function.
// Return: Void.
void TestNamespace(int (&arr)[5]) {

    // Reassign the first three elements.
    TestClass testVar(-5);
    arr[0] = testVar.GetNum();
    arr[1] = testSpaceNum;
    arr[2] = TestFunc();

    // Sum the elements.
    int arrSum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];

    // Reassign the last element.
    arr[4] = arrSum;
}