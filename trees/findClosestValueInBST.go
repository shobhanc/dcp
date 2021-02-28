/*
 * Given a BST and a value. Find the closest value in the tree to the given value.
 *
 */


package main

type BST struct {
	Value int

	Left  *BST
	Right *BST
}

func abs (a, b int)int {
	if a>b {
		return a-b
	}else{
		return b-a
	}
}

//time O(N) and worst space O(N)
//average time O(log(N)) and space O(log(N)) depth of the tree
func (tree *BST) helper(target int, closest int)int{
	if(abs(tree.Value,target)<abs(closest,target)){
		closest = tree.Value
	}
	if(target < tree.Value && tree.Left != nil){
		return tree.Left.helper(target, closest)
	} else if (target > tree.Value && tree.Right != nil){
		return tree.Right.helper(target, closest)
	}
	return closest;
}

func (tree *BST) FindClosestValue(target int) int {
	return tree.helper( target, tree.Value)
}

//time O(N) and space O(1)
func (tree *BST) FindClosestValue(target int) int {
	if tree == nil{
		return -1
	}
	closest := tree.Value
	root := tree
	for root != nil {
		if abs(root.Value,target)<abs(closest,target){
			closest=root.Value
		}
		if target<root.Value {
			root = root.Left
		}else if target>root.Value {
			root = root.Right
		}else{
			break
		}
	}
	return closest
}

