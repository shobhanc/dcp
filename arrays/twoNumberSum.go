/*
 * Given an unsorted array and a target sum return elements that make up the target sum from the array.
 */

//time O(nlogn) and space O(1)
//sort array and check of begin element and end element sum match target
//if less move towards end else move end towards begin.
package main

import "sort"

func TwoNumberSum1(array []int, target int) []int {
	sort.Ints(array)
	l, r := 0, len(array)-1
	for l<r {
		sum := array[l]+array[r]
		if sum == target {
			return []int{array[l],array[r]}
		}else if sum > target {
			r -= 1
		}else {
			l += 1
		}
	}
	return []int{}
}

//time O(n) and space O(n)
//use a hashtable to lookup for the other number
func TwoNumberSum2(array []int, target int) []int {
	nums := map[int]bool{}
	for _, num := range array {
		reminder := target - num
		if _, found := nums[reminder]; found {
			return []int{reminder, num}
		}
		nums[num]=true
	}
	return []int{}
}

//time O(N^2) and space O(1)
func TwoNumberSum3(array []int, target int) []int {
	for i:=0; i<len(array)-1; i++ {
		for j:=i+1; j<len(array); j++ {
			if array[i]+array[j] == target {
				return []int{array[i], array[j]}
			}
		}
	}
	return []int{}
}
