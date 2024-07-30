#include <iostream>
#include <variant>

struct Leaf {};
struct Node;

using Tree = std::variant<Leaf, Node*>;

struct Node {
    Tree left;
    Tree right;
};

template <typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};

int countLeaves(const Tree& tree) {
    return std::visit(Overload{
        [](const Leaf&) { return 1; },
        [](this auto& self, const Node* node) -> int {
            return std::visit(self, node->left)
                    + std::visit(self, node->right);
        }
    })
}