from __future__ import annotations;
from typing import   TypeVar,Generic;
T = TypeVar("T",int ,float);



            
        


class BST(Generic[T]):
    def __init__(self,data:T) -> None:
        self.val:T = data;
        self.left:BST[T] | None = None;
        self.right:BST[T] | None = None;

    def max_depth(self,root: BST[T] | None) ->int:
        if root is None:
            return 0;

        left_depth = self.max_depth(root.left);
        right_depth= self.max_depth(root.right);

        return 1 + max(left_depth,right_depth);

    def total_nodes(self,root:BST[T]|None) -> int :
        if root is None:
            return 0;

        return 1 + self.total_nodes(root.left) + self.total_nodes(root.right);

    def traverse(self,root:BST[T]|None,accu:list[T]) ->None:
        if root is None:
            return;

        if root.left:
             self.traverse(root.left,accu);

        accu.append(root.val)
        if root.right:
              self.traverse(root.right,accu);


    def median(self,root:BST[T]) ->  float :
        accu:list[T] = [];
        self.traverse(root,accu);
        size :int = len(accu)
        if size % 2 != 0:
            return accu[size//2 ];
        else:
            return  (accu[ size // 2 ] + accu[ ( size  // 2 )  - 1 ]) /2 ;

    def insert(self,root:BST[T] | None,data:T) ->BST[T] | None:
        if root is None:
           return  BST(data);
            
            

        assert(root is not None);
        if data < root.val:
            root.left = self.insert(root.left,data);
        else:
            root.right = self.insert(root.right,data);

        return root;


        


        
        



def print_tree(node:BST[T] |None) ->None:
    if node is None :
        return;
    if node.left : 
        print_tree(node.left)
    print(node.val);
    if node.right :
        print_tree(node.right);




tree:BST[int] = BST(32);
_ = tree.insert(tree,100);
_ = tree.insert(tree,200);


print_tree(tree);






