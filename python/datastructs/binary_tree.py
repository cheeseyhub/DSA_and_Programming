from __future__ import annotations;
from typing import TypeVar,Generic;
T = TypeVar("T");






class TreeNode(Generic[T]):
    def __init__(self,data:T) -> None:
        self.val:T = data;
        self.left:TreeNode[T] | None = None;
        self.right:TreeNode[T] | None = None;

    def max_depth(self,root: TreeNode[T] | None) ->int:
        if root is None:
            return 0;

        left_depth = self.max_depth(root.left);
        right_depth= self.max_depth(root.right);

        return 1 + max(left_depth,right_depth);

    def total_nodes(self,root:TreeNode[T]|None) -> int :
        if root is None:
            return 0;

        return 1 + self.total_nodes(root.left) + self.total_nodes(root.right);


        return list_of_nodes;

    def median(self,root:TreeNode[T]|None) -> list[int] | int :
        # I want to get all the nodes in a list then find the middle value 
        # if the length of the list is odd then i just do n - 1  /2 
        # if it is even then it is the average of two middle elements (n /2) -1 + (n /2)

        return 0;


        
        



def visualize_tree(node: TreeNode[T] | None, level: int = 0, prefix: str = "Root: ") -> None:
    if node is not None:
        print(" " * (level * 4) + prefix + str(node.val))
        
        if node.left is not None or node.right is not None:
            if node.left:
                visualize_tree(node.left, level + 1, "L── ")
            else:
                print(" " * ((level + 1) * 4) + "L── None")
                
            if node.right:
                visualize_tree(node.right, level + 1, "R── ")
            else:
                print(" " * ((level + 1) * 4) + "R── None")


def print_tree(node:TreeNode[T] |None) ->None:
    if node is None :
        return;
    print(node.val);
    if node.left : 
        print_tree(node.left)
    if node.right :
        print_tree(node.right);


tree :TreeNode[int]=  TreeNode(100);
tree.left = TreeNode(99) ;
tree.right = TreeNode(101) ;


print(tree.max_depth(tree));
print(tree.total_nodes(tree));




