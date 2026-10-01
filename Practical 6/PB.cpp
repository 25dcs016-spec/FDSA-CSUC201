#include <iostream>
#include <vector>
#include <string>

class BrowserHistory {
private:
    std::vector<std::string> history;

    void print_current() {
        if (history.empty()) {
            std::cout << "No pages visited\n";
        } else {
            std::cout << "Current page: " << history.back() << "\n";
        }
    }

public:
    BrowserHistory(const std::string& homepage) {
        history.push_back(homepage);
        print_current();
    }

    void visit(const std::string& url) {
        history.push_back(url);
        print_current();
    }

    void back() {
        if (history.size() <= 1) {
            std::cout << "Error: No history left to go back.\n";
            return;
        }
        history.pop_back();
        print_current();
    }
};

int main() {
    BrowserHistory browser("homepage.com");

    browser.visit("news.com");
    browser.visit("sports.com");
    browser.back();
    browser.back();
    browser.back(); 

    return 0;
}
