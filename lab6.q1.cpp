#include <iostream>
#include <vector>
#include <utility>

bool isReflexive(const std::vector<std::pair<int, int>>& relation, const std::vector<int>& set) {
    for (int a : set) {
        bool found = false;
        for (const auto& pair : relation) {
            if (pair.first == a && pair.second == a) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(const std::vector<std::pair<int, int>>& relation) {
    for (const auto& pair : relation) {
        bool found = false;
        for (const auto& otherPair : relation) {
            if (otherPair.first == pair.second && otherPair.second == pair.first) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool isAsymmetric(const std::vector<std::pair<int, int>>& relation) {
    for (const auto& pair : relation) {
        for (const auto& otherPair : relation) {
            if (otherPair.first == pair.second && otherPair.second == pair.first) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(const std::vector<std::pair<int, int>>& relation) {
    for (const auto& pair1 : relation) {
        for (const auto& pair2 : relation) {
            if (pair1.second == pair2.first) {
                bool found = false;
                for (const auto& pair3 : relation) {
                    if (pair3.first == pair1.first && pair3.second == pair2.second) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    std::vector<int> set = {1, 2, 3};
    std::vector<std::pair<int, int>> relation = {{1, 1}, {2, 2}, {3, 3}, {1, 2}, {2, 1}, {2, 3}, {3, 2}};

    std::cout << "Is reflexive: " << (isReflexive(relation, set) ? "Yes" : "No") << std::endl;
    std::cout << "Is symmetric: " << (isSymmetric(relation) ? "Yes" : "No") << std::endl;
    std::cout << "Is asymmetric: " << (isAsymmetric(relation) ? "Yes" : "No") << std::endl;
    std::cout << "Is transitive: " << (isTransitive(relation) ? "Yes" : "No") << std::endl;

    return 0;
}
