#include <bits/stdc++.h> // Includes all standard C++ libraries at once; great for CP, but increases compile time.
using namespace std;     // Allows using standard names (like string, cin, cout) without typing std:: every time.

void practice_capacity_and_modifiers() {
    string str_val = "hello";           // Creates a string holding "hello". Time: O(N) where N is string length.

    // Capacity
    int len_val = str_val.size();       // Gets the total number of characters. Time: O(1).
    bool is_mt = str_val.empty();       // Checks if the string has 0 characters (true/false). Time: O(1).
    char front_c = str_val.front();     // Gets the very first character ('h'). Time: O(1).
    char back_c = str_val.back();       // Gets the very last character ('o'). Time: O(1).

    // Modifiers
    str_val += " world";                // Appends the text " world" to the end. Time: O(N) where N is appended length.
    str_val.push_back('!');             // Adds a single character '!' to the end. Time: O(1) amortized.
    str_val.pop_back();                 // Removes the last single character from the end. Time: O(1).
    
    // Insert and Erase
    str_val.insert(5, " there");        // Inserts " there" starting at index 5, shifting rest right. Time: O(N).
    str_val.erase(5, 6);                // Deletes 6 characters starting at index 5, shifting rest left. Time: O(N).
}

void practice_algorithms() {
    string str_val = "competitive";     // Creates a string. Time: O(N).
    
    // Substring
    string sub_val = str_val.substr(0, 4); // Copies 4 characters starting from index 0 ("comp"). Time: O(N).
    
    // Search
    size_t idx = str_val.find("pet");   // Searches for "pet" and gets its starting index. Time: O(N * M).
    if (idx != string::npos) {          // string::npos means "not found". Checks if the search succeeded.
        // Handle found case
    }
    
    // Iterators (working with ranges of elements)
    sort(str_val.begin(), str_val.end());    // Sorts all characters in alphabetical order. Time: O(N log N).
    reverse(str_val.begin(), str_val.end()); // Flips the string entirely backwards. Time: O(N).
    
    int freq_val = count(str_val.begin(), str_val.end(), 'e'); // Counts how many times 'e' appears. Time: O(N).
}

void practice_conversions() {
    string num_str = to_string(12345);  // Converts the math integer 12345 into text "12345". Time: O(N).
    
    int int_val = stoi("123");          // Converts text "123" into a standard math integer 123. Time: O(N).
    long long ll_val = stoll("123456789012"); // Converts text into a massive 64-bit integer. Time: O(N).
}

void practice_cctype() {
    char c_val = 'A';                   // Creates a single character variable. Time: O(1).
    string str_val = "Code 123";        // Creates a string. Time: O(N).

    // Classifications (All run in O(1) time)
    bool is_alpha = isalpha(c_val);     // Checks if it is a letter (A-Z, a-z). Result: true.
    bool is_num = isdigit(c_val);       // Checks if it is a number (0-9). Result: false.
    bool is_alnum = isalnum(c_val);     // Checks if it is EITHER a letter or number. Result: true.
    bool is_low = islower(c_val);       // Checks if it is a lowercase letter. Result: false.
    bool is_up = isupper(c_val);        // Checks if it is an uppercase letter. Result: true.
    bool is_spc = isspace(c_val);       // Checks if it is a space, tab, or newline. Result: false.

    // Character Conversions (All run in O(1) time)
    char lower_c = tolower(c_val);      // Changes 'A' to lowercase 'a'.
    char upper_c = toupper(lower_c);    // Changes 'a' back to uppercase 'A'.

    // In-place string transformation
    for (char &ch_ref : str_val) {      // Loops through string. '&' means we edit the actual original characters. Time: O(N).
        ch_ref = tolower(ch_ref);       // Converts the current character to lowercase directly in memory.
    }
}

void practice_io() {
    string word_val, line_val;          // Creates two empty strings. Time: O(1).
    // cin >> word_val;                 // Reads keyboard input until the first space or enter. Time: O(N).
    // cin.ignore();                    // Throws away the leftover "Enter" key press stuck in the system. Time: O(1).
    // getline(cin, line_val);          // Reads an entire sentence including spaces until "Enter". Time: O(N).
}

int main() {
    // Standard CP fast I/O setup
    ios_base::sync_with_stdio(false);   // Disables syncing between C and C++ input/output to make it run much faster. Time: O(1).
    cin.tie(NULL);                      // Unties input from output so cout doesn't force a delay before cin reads. Time: O(1).

    practice_capacity_and_modifiers();  // Executes the function above.
    practice_algorithms();              // Executes the function above.
    practice_conversions();             // Executes the function above.
    practice_cctype();                  // Executes the function above.
    practice_io();                      // Executes the function above.
    
    return 0;                           // Tells the operating system the program finished without errors.
}