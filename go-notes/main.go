// ------------------------------------------------------------------------------------------------------------------------
// Section: Project Management
// ------------------------------------------------------------------------------------------------------------------------

// --Go Projects--
// Description: To make a project in Go, navigate to the directory where the project should be located. Use the command
//              "go mod init projectname". It might be helpful to name the project after its directory.
// This Project: This project has been named notes.

// --Go Packages--
// Descripton: Go automatically exports any identifiers that begin with a capital letter. This includes structs and functions.
//             Identifiers can be accessed with the "." operator. For example, "package.identifier".
// Package Naming Conventions: A package will be located within its own directory within a Go project. The directory and header
//                             (within Go files) should have the same name. There can be multiple Go files within the same
//                             package. The main package must have the name "main", and it is not necessary for the project
//                             working directory name to match.
package main

// --Importing Packages--
// Description: Import is called at the top of a Go file. Packages to import are declared on separate lines within the 
//              import function.
// Standard Library Functions: fmt and strings are standard library functions that have been iported into the project. 
// Relative packages: Relative packages are imported using the module name specified when creating a go project. The
//                    The relative package medtwoarr is included to display this functionality.
import(
	"fmt"
	//"strings"
	//"notes/medtwoarr"
)

func main() {

	// ------------------------------------------------------------------------------------------------------------------------
	// Section: Types
	// ------------------------------------------------------------------------------------------------------------------------

	// All types in go are initialized to the zero value of their type if not specified.

	// ------------------------------------------------------------------------------------------------------------------------
	// Section: Arrays and Slices
	// ------------------------------------------------------------------------------------------------------------------------

	{
		// --Arrays--
		// Description: A collection of a single type stored in a contiguous section of memory.
		// Declaration Styles: The ... operator can be used to imply that an array should be the size of the elements
		//                     specified.
		arr1 := [3]int{1, 2, 3};
		arr2 := [...]int{1, 2, 3};
		var arr3 [3]int;

		// Indexing: Indexing is accomplished using the [] operator. Arrays start at index zero.
		arr3[0] = 1;
		arr3[1] = 2;
		arr3[2] = 3;

		// Length Function: The function is called len. Returns the size of the array specified.
		lenArr1 := len(arr1);
		fmt.Printf("Test 1: Arrays [%v, %v, %v, %v].\n", arr1, arr2, arr3, lenArr1);
	}

	{
		arr := [3]int{1, 2, 3}

		// --Slices--
		// Description: A mutable array-like data structure.
		// Declaration Styles: Can be created with the make function in which the second passed argument is the size
		//                     of the created slice.
		// Slicing: Arrays and other slices can be used to make a slice. When this is done, changes made to the new slice
		//          impact the original array since slices are reference types.
		var slc1 []int = []int{1, 2, 3};
		slc2 := []int{1, 2, 3};
		slc3 := arr[0:3];
		slc4 := make([]int, 0);
		slc5 := slc2[0:3];

		// Append Function: Appends elements to the end of a slice, increasing its capacity if necessary.
		slc4 = append(slc4, 1, 2, 3);

		slc3[2] = 1;
		slc5[2] = 1;

		// Copy Function: Creates a slice which does not reference the original array.
		cpySlc := make([]int, 3);
		copy(cpySlc, slc1);
		slc1[2] = 1;

		fmt.Printf("Test 2: Slices [%v, %v, %v, %v, %v, %v, %v].\n", arr, slc1, slc2, slc3, slc4, slc5, cpySlc);
	}

	// ------------------------------------------------------------------------------------------------------------------------
	// Section: Maps
	// ------------------------------------------------------------------------------------------------------------------------
	
	{
		// --Map Initialization--
		// Description: An empty map must be created using the make function since it is a refference type.
		//              A few elements of a map can be initialized in brackets. By default, all elements are initialized to the
		//              zero value of the given type.
		// Map Keys: A map's key may be anything in the Go language that is comparable.
		m1 := make(map[string]int);
		m2 := map[string]int{
			"one": 1,
			"two": 2,
			"three": 3,
		};

		// --Adding Elements to a Map--
		// Description: Elements can be added to a map similar to in an array except the key is in the brackets.
		m1["one"] = 1;
		m1["two"] = 2;
		m1["three"] = 3;

		// --Looping Over a Map--
		// Description: You can loop over a map using this syntax. The order is not always the same.
		for key, value := range m2 {
			if value == 1 {
				m2[key] = 3;
			}
		}

		// --Checking if Value Exists--
		// Description: Throw away the first value and store a second value in a variable.
		//              the second value is true if exists, false if it does not exist (zero value).
		_, ok := m1["four"];
		fmt.Printf("Test 3: Maps [%v, %v, %v, %v, %v, %v, %v, %v].\n", m1["one"], m1["two"], m1["three"], m1["four"], m2["one"], m2["two"], m2["three"], ok);
	}
}

// TODO: GetDigit Function (Help me remember how modulo works).
// TODO: Median of Two Sorted Arrays in O(log(m+n)).