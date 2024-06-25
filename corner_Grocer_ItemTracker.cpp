#include <iostream> // Include the iostream library for input/output
#include <map> // Include the map library for map data structure
#include <fstream> // Include the fstream library for file handling
#include <string> // Include the string library for string manipulation

// Define a class named ItemTracker
class ItemTracker {
private:
    std::map<std::string, int> itemFrequency; // Declare a private member variable: a map to store item frequencies
public:
    void addItem(std::string item) { // Method to add an item to the map
        itemFrequency[item]++; // Increment the frequency of the item in the map
    }
    int getItemFrequency(std::string item) { // Method to get the frequency of an item
        return itemFrequency[item]; // Return the frequency of the item from the map
    }
    void printAllItems() { // Method to print all items and their frequencies
        for (auto const& pair : itemFrequency) { // Loop through each pair in the map
            std::cout << pair.first << " " << pair.second << std::endl; // Print the item and its frequency
        }
    }
    void printHistogram() { // Method to print a histogram of item frequencies
        for (auto const& pair : itemFrequency) { // Loop through each pair in the map
            std::cout << pair.first << " "; // Print the item
            int limit = std::min(pair.second, 50); // Limit the number of asterisks to 50
            for (int i = 0; i < limit; i++) { // Loop as many times as the frequency of the item
                std::cout << "*"; // Print an asterisk for each count of the item
            }
            std::cout << std::endl; // Print a newline character
        }
    }
    void saveToFile() { // Method to save the item frequencies to a file
        std::ofstream outFile("frequency.dat"); // Create an ofstream object and open the file "frequency.dat"
        if (!outFile.is_open()) { // If the file could not be opened
            std::cerr << "Error opening file." << std::endl; // Print an error message
            return; // Return from the function
        }
        for (auto const& pair : itemFrequency) { // Loop through each pair in the map
            outFile << pair.first << " " << pair.second << std::endl; // Write the item and its frequency to the file
        }
        outFile.close(); // Close the file
    }
};

int main() { // The main function
    ItemTracker tracker; // Create an object of the ItemTracker class
    std::ifstream inputFile("CS210_Project_Three_Input_File.txt"); // Create an ifstream object and open the input file
    std::string line; // Declare a string to store each line of the file
    while (std::getline(inputFile, line)) { // While there are lines in the file
        tracker.addItem(line); // Add the item from the line to the tracker
    }
    int option = 0; // Declare an integer to store the user's menu option
    std::string item; // Declare a string to store the user's item
    while (option != 6) { // While the user's option is not 6 (exit)
        // Print the menu options
        std::cout << "1. Search for an item\n2. Print all items\n3. Print histogram\n4. Save to file\n5. Exit\n";
        std::cin >> option; // Get the user's option
        switch (option) { // Switch on the user's option
        case 1: // If the option is 1 (search for an item)
            std::cout << "Enter item name: "; // Prompt the user to enter an item name
            std::cin >> item; // Get the item from the user
            std::cout << "Frequency: " << tracker.getItemFrequency(item) << std::endl; // Print the frequency of the item
            break; // Break out of the switch statement
        case 2: // If the option is 2 (print all items)
            tracker.printAllItems(); // Print all items and their frequencies
            break; // Break out of the switch statement
        case 3: // If the option is 3 (print histogram)
            tracker.printHistogram(); // Print a histogram of item frequencies
            break; // Break out of the switch statement
        case 4: // If the option is 4 (save to file)
            tracker.saveToFile(); // Save the item frequencies to a file
            break; // Break out of the switch statement
        case 5: // If the option is 5 (exit)
            std::cout << "Exiting...\n"; // Print a message indicating that the program is exiting
            return 0; // Return 0 to indicate successful program termination
        default: // If the option is not 1, 2, 3, 4, or 5
            std::cout << "Invalid option. Please try again.\n"; // Print an error message
        }
    }
    return 0; // Return 0 to indicate successful program termination
}
