from __future__ import annotations;
from typing import   TypeVar,Generic, override;
T = TypeVar("T",int ,float);



class list_acumalator(Generic[T]):
    def __init__(self):
        self.l:list[T]= [];
        self.size:int = 0;

    def add_to_list(self,node:TreeNode[T])->None:
        self.l.append(node.val);
        self.size+=1;

    def get_value(self,index:int) ->T:
        return self.l[index];
    
            
        
    @override
    def __str__(self) -> str:
        return str(self.l);


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

    def traverse(self,root:TreeNode[T]|None,accu:list_acumalator[T]) ->None:
        if root is None:
            return;

        if root.left:
             self.traverse(root.left,accu);

        accu.add_to_list(root)
        if root.right:
              self.traverse(root.right,accu);


    def median(self,root:TreeNode[T]) ->  float :
        accu:list_acumalator[T] = list_acumalator() 
        self.traverse(root,accu);
        if accu.size % 2 != 0:
            return accu.get_value(accu.size // 2);
        else:
            return  (accu.get_value(accu.size // 2) + accu.get_value(( accu.size // 2 )  -1 )) / 2;



        


        
        



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
tree.left.left = TreeNode(1) ;
tree.right = TreeNode(101) ;
tree.right.right =TreeNode(9999)



#print(tree.median(tree))
print_tree(tree)





