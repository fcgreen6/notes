// ------------------------------------------------------------------------------------------------------------------------
// Section: Preprocessor Arithmetic
// ------------------------------------------------------------------------------------------------------------------------

// --ifndef Directive--
// Description: If a symbol is not yet defined executes a conditional section of code. Closed by endif.
#ifndef _class_
#define _class_

// --define Directive--
// Description: Binds text to a symbol. Wherever that symbol is placed in the program the literal text is copied there.
#define DEFINED THREE

#include <iostream>
using std::cout;

// ------------------------------------------------------------------------------------------------------------------------
// Section: Enums
// ------------------------------------------------------------------------------------------------------------------------

// --Class Scoping--
// Description: Enums can be placed within the public part of a class to easily scope them.
// Enum Initilization: Starts at zero. When a value is changed starts counting from the number after.
class EnumClass {
    public:
        enum number {ZERO, ONE = -1, TWO, DEFINED};
};

// ------------------------------------------------------------------------------------------------------------------------
// Section: Classes
// ------------------------------------------------------------------------------------------------------------------------

// --Class Constructor--
// Description: A class method with the same name as the class. A variation of the constructor method is called when the
//              class is created.
// Explicit Keyword: Explicit can be placed in front of constructors to prevent implicit conversions to that constructor.
// No Constructors: If there is no default constructor the default syntax cannot be used.

// --Class Copy Constructor--
// Description: Accepts a parameter of the same class with const. The copy constructor manually copies the values of the
//              given object into itself.
// Implicit Definition: If no copy constructor is defined, one will be implicitly defined.

// --Class Destructor--
// Description: Deletes any dynamically alocated data which may exist within the class when the object is dropped
//              out of scope.
class BaseClass {
    protected:
        int* _nums;
        unsigned int _size;
    public:
        explicit BaseClass(int* numArr, unsigned int size);
        explicit BaseClass(const BaseClass& copy);
        ~BaseClass();
        int BaseSum() const;
};

// --Operator Overloading--
// The following categories can only be overloaded within the class:
//                                                                   - Assignment operators.
//                                                                   - Postfix and prefix ++-- operators.
//                                                                   - The [] operator.
//                                                                   - The () operator.
// The following categories have a boolean return type:
//                                                      - Logical operators.
// The following categories can have any return type:
//                                                    - Pemdas operators.
//                                                    - Bitwise operators.
//                                                    - Reference and dereference operators.
//                                                    - The () operator.
// The following categories return object references:
//                                                    - Assignment operators.
//                                                    - Postfix and prefix ++-- operators.
//                                                    - The [] operator.
class OverloadedClass {
    public:
        int _compNum;
        explicit OverloadedClass(int initNum);
        void operator~();
        double operator%(const OverloadedClass& rhs);
        OverloadedClass& operator++();
        OverloadedClass operator++(int none);
        void operator()(int setNum);
};
bool operator||(const OverloadedClass& lhs, const OverloadedClass& rhs);
bool operator!(const OverloadedClass& obj);

// --Private Subclass--
// Description: A class which inherits BaseClass privatley. This means that public members become private. Private and protected members
//              are inaccessable.
class PrivateSubClass: private BaseClass {
    private:
        EnumClass::number _classNum;
    public:
        explicit PrivateSubClass(int* numArr, unsigned int size, EnumClass::number classNum);
        void Print();
};

#endif