from __future__ import annotations;
from typing import Any, TypeVar,Generic, override;
T = TypeVar("T");



class list_acumalator(Generic[T]):
     def __init__(self):
         self.list:list[T]= [];
     def add_to_list(self,node:TreeNode[T])->None:
         self.list.append(node.val);
     @override
     def __str__(self) -> str:
        return str(self.list);


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



    def median(self,root:TreeNode[T]|None,accu:list_acumalator[T]) ->  int |None:
        # I want to get all the nodes in a list then find the middle value 
        # if the length of the list is odd then i just do n - 1  /2 
        # if it is even then it is the average of two middle elements (n /2) -1 + (n /2)
        #
        if root is None:
            return;

        if root.left:
            _ = self.median(root.left,accu);

        accu.add_to_list(root)
        if root.right:
            _=  self.median(root.right,accu);

        
        return 0;


        
        



def print_tree(node:TreeNode[T] |None) ->None:
    if node is None :
        return;
    print(node.val);
    if node.left : 
        print_tree(node.left)
    if node.right :
        print_tree(node.right);


nodes_list:list_acumalator[int] = list_acumalator() 


tree :TreeNode[int]=  TreeNode(100);
tree.left = TreeNode(99) ;
tree.right = TreeNode(101) ;


_ =tree.median(tree,nodes_list);
print(str(nodes_list));





