#pragma once

#include <string>

class Brain {
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain();
        void setIdeas(const std::string idea, int index);
        std::string getIdeas(int index) const;
};