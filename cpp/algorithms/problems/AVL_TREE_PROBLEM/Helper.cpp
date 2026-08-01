#include "Helper.h"

Tree Helper::generateTree(int type) {
    Tree tree;

    if (type == 1) {
        tree.insert(62);
        tree.insert(33);
        tree.insert(99);
        tree.insert(57);
        tree.insert(75);
        tree.insert(129);
        tree.insert(67);
        tree.insert(80);
    } else if (type == 2) {
        tree.insert(43);
        tree.insert(187);
        tree.insert(24);
        tree.insert(99);
        tree.insert(12);
        tree.insert(265);
        tree.insert(74);
        tree.insert(68);
    } else if (type == 3) {
        tree.insert(17);
        tree.insert(18);
        tree.insert(19);
        tree.insert(14);
        tree.insert(15);
        tree.insert(16);
        tree.insert(1);
        tree.insert(20);
    } else if (type == 4) {
        tree.insert(38);
        tree.insert(37);
        tree.insert(36);
        tree.insert(35);
        tree.insert(45);
        tree.insert(47);
        tree.insert(49);
        tree.insert(79);
    }

    return tree;
}
