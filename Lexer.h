#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <map>

class read {
public:
    void storeValue(const std::string& line) 
    {
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) 
        {
            if (word == "str") 
            {
                std::string varName, equals, value, strVal, temp;
                ss >> varName >> equals; // get name and "="

                while (ss >> temp) 
                {
                    strVal += temp + " ";
                }
                str.insert(std::pair<std::string, std::string>(varName, strVal));
            }

            else if (word == "int") {
                std::string varName, equals, value;
                ss >> varName >> equals >> value;

                try 
                {
                    int intVal = std::stoi(value);
                    num.insert(std::pair<std::string, int>(varName, intVal));
                } 
                
                catch (std::invalid_argument&) 
                {
                    std::cerr << "Invalid integer value\n";
                }
            }
        }
    }

    void print(const std::string& line) 
    {
        std::stringstream ss(line);
        std::string word;
        ss >> word; // should be "print"
        ss >> word;

        if (num.find(word) != num.end()) 
        {
            std::cout << num[word] << "\n";
        } 
        
        else if (str.find(word) != str.end()) 
        {
            std::cout << str[word] << "\n";
        } 
        
        else 
        {
            std::cout << "Undefined variable: " << word << "\n";
        }
    }

    int add(const std::string& line)
    {
        std::stringstream ss(line);
        std::string add, firstVar, secondVar;
        ss >> add >> firstVar >> secondVar;

        return num[firstVar] + num[secondVar];
    }

    int subtract(const std::string& line)
    {
        std::stringstream ss(line);
        std::string subtract, firstVar, secondVar;
        ss >> subtract >> firstVar >> secondVar;

        return num[firstVar] - num[secondVar];
    }

    int multiply(const std::string& line)
    {
        std::stringstream ss(line);
        std::string divide, firstVar, secondVar;
        ss >> divide >> firstVar >> secondVar;

        return num[firstVar] * num[secondVar];
    }

    int divide(const std::string& line)
    {
        std::stringstream ss(line);
        std::string divide, firstVar, secondVar;
        ss >> divide >> firstVar >> secondVar;

        int denominator = num[secondVar];
        int numerator = num[firstVar];

        if (denominator == 0)
        {
            std::cerr << "Error: Division by zero\n";
            return 0; // or throw exception or return special error code
        }

        return numerator / denominator;
    }

    void decide(const std::string& line) 
    {
        std::stringstream ss(line);
        std::string word;
        ss >> word;

        if (word == "str" || word == "int") 
        {
            storeValue(line);
        } 
        
        else if (word == "print") 
        {
            print(line);
        }

        else if(word == "add")
        {
            std::cout << add(line) << "\n";
        }

        else if(word == "multiply")
        {
            std::cout << multiply(line) << "\n";
        }

        else if(word == "divide")
        {
            std::cout << divide(line) << "\n";
        }

        else if (word == "subtract")
        {
            std::cout << subtract(line) << "\n";
        }
    }

private:
    std::map<std::string, std::string> str;
    std::map<std::string, int> num;
};
