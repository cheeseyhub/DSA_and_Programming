from typing import TypeVar,Generic;
T = TypeVar("T");






class TreeNode(Generic[T]):
    def __init__(self,data:T) -> None:
        self.val:T = data;
        self.left:TreeNode[T] | None = None;
        self.right:TreeNode[T] | None = None;



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
    if node.left is None: 
        return;
    print_tree(node.left)
    if node.right is None:
        return;
    print_tree(node.right);


tree :TreeNode[int]=  TreeNode(5);



tree.left = TreeNode(10) ;
tree.right = TreeNode(15) ;


print_tree(tree);


