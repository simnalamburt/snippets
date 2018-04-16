function isSubset(parent, child) {
  for (const elem of child) {
    if (!parent.has(elem)) {
      return false
    }
  }
  return true
}

console.log(isSubset(new Set([1, 2, 3]), new Set([1])))
console.log(isSubset(new Set([1, 2, 3]), new Set([4])))
