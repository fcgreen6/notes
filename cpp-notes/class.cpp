#include "class.h"

// ------------------------------------------------------------------------------------------------------------------------
// Section: BaseClass Definitions
// ------------------------------------------------------------------------------------------------------------------------

// --BaseClass Constructor--
// Description: Initializes an instance of BaseClass.
// Parameters:
//             - numArr: A pointer to an array of elements to initialize the class with.
//             - size: The size of the array passed.
BaseClass::BaseClass(int* numArr, unsigned int size): _size(size) {
    _nums = new int[_size];
    for (int i = 0; i < _size; i++) {
        _nums[i] = numArr[i];
    }
}

// --BaseClass Copy Constructor--
// Description: Initializes an instance of BaseClass.
// Parameters:
//             - copy: The instance of the class to copy.
BaseClass::BaseClass(const BaseClass& copy): _size(copy._size) {
    _nums = new int[_size];
    for (int i = 0; i < _size; i++) {
        _nums[i] = copy._nums[i];
    }
}

// --BaseClass Destructor--
// Description: Deletes dynamically allocated data within a BaseClass instance.
BaseClass::~BaseClass() {
    delete[] _nums;
}

// --BaseClass::BaseSum Method--
// Description: Calculates the sum of all of the numbers held in the BaseClass instance.
// Return: An integer containing the sum of the numbers held in the BaseClass instance.
int BaseClass::BaseSum() const {
    int sum = 0;
    for (int i = 0; i < _size; i++) {
        sum += _nums[i];
    }
    return sum;
}

// ------------------------------------------------------------------------------------------------------------------------
// Section: Overloaded Class Definitions
// ------------------------------------------------------------------------------------------------------------------------

// --OverloadedClass Constructor--
// Description: Initilises an OverloadedClass.
// Parameters:
//             - initNum: The number to initialize the compNum data member to.
OverloadedClass::OverloadedClass(int initNum): _compNum(initNum) {};
void OverloadedClass::operator~() {
    if (_compNum != 0) {
        _compNum = 0;
    }
}

// --OverloadedClass::operator% Method--
// Description: Overloads the % operator.
// Parameters:
//             - rhs: The right side of the % operator.
double OverloadedClass::operator%(const OverloadedClass& rhs) {
    return ((double)_compNum / rhs._compNum) * 100;
}

// --OverloadedClass::operator++ Method--
// Description: Overloads the prefix ++ operator.
OverloadedClass& OverloadedClass::operator++() {
    _compNum++;
    return *this;
}

// --OverloadedClass::operator++ Method--
// Description: Overloads the postfix ++ operator.
// Parameters:
//             - none: A variable to identify the posifix variation. Not used.
OverloadedClass OverloadedClass::operator++(int none) {
    OverloadedClass retVal = OverloadedClass(_compNum);
    ++_compNum;
    return retVal;
}

// --OverloadedClass::operator() Method--
// Description: Overloads the () operator.
// Parameters:
//             - setNum: A number to change the compNum data member to.
void OverloadedClass::operator()(int setNum) {
    _compNum = setNum;
}

// --operator|| Overload--
// Description: Overloads the || operator for OverloadedClass outside of the class.
// Parameters:
//             - lhs: The left side of the || operator.
//             - rhs: The right side of the || operator.
bool operator||(const OverloadedClass& lhs, const OverloadedClass& rhs) {
    if (lhs._compNum == 0 || rhs._compNum == 0) {
        return true;
    }
    return false;
}

// --operator! Overload--
// Description: Overloads the ! operator for OverloadedClass outside of the class.
// Parameters:
//             - obj: An OverloadedClass object to perform calculations on.
bool operator!(const OverloadedClass& obj) {
    if (obj._compNum == 0) {
        return true;
    }
    return false;
}

// ------------------------------------------------------------------------------------------------------------------------
// Section: PrivateSubClass Definitions
// ------------------------------------------------------------------------------------------------------------------------

// --PrivateSubClass Constructor--
// Description: Creates an instance of PrivateSubClass.
// Parameters:
//             - numArr: Array used to create the BaseClass.
//             - size: Integer used to create the BaseClass.
//             - classNum: Enum type used in PrivateSubClass.
PrivateSubClass::PrivateSubClass(int* numArr, unsigned int size, EnumClass::number classNum): BaseClass(numArr, size), _classNum(classNum) {}

// --PrivateSubClass::Print Method--
// Description: Prints basic information about the PrivateSubClass instance.
void PrivateSubClass::Print() {
    cout << "[" << _classNum << ", " << BaseSum() << "]";
}