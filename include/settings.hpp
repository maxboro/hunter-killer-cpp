#ifndef TEST_HPP
#define TEST_HPP

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

class Settings {
public:

    void load_settings(){
        std::string config_line;

        std::cout << "Reading the settings." << std::endl;

        std::string settings_name;
        std::string settings_value_str;
        int equal_sign_position;

        // Read from the text file
        std::ifstream config_file("settings.txt");

        while (getline(config_file, config_line)) {

            equal_sign_position = config_line.find("=");
            settings_name = config_line.substr(0, equal_sign_position);
            settings_value_str = config_line.substr(equal_sign_position + 1, config_line.length());
            std::cout << settings_name << ": " << settings_value_str << std::endl;
            _settings[settings_name] = stoi(settings_value_str);
        }

        // Close the file
        config_file.close();
        std::cout << "Settings are loaded." << std::endl;
    }

    int get_value(std::string key){
        if (_settings.find(key) == _settings.end()){
            throw std::runtime_error("Key: " + key + " is not in settings");
        } else {
            return _settings["key"];
        }
    }

private:
    std::unordered_map<std::string, int> _settings;

};

#endif