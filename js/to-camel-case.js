console.log(toCamelCase("the-stealth-warrior"))
console.log(toCamelCase("The_Stealth_Warrior"))
console.log(toCamelCase("The_Stealth-Warrior"))
console.log(toCamelCase(""))
console.log(toCamelCase("A-B-C"))
console.log(toCamelCase("--a-b---c--"))

function toCamelCase(str) {
  return str
    .split(/[-_]/) // Split by both hyphens and underscores
    .map((word, index) => {
      if (word.length === 0) { return '' }
      const first = word[0];

      const rest = word.slice(1);
      const restLower = rest.toLowerCase();

      if (index === 0) {
        return first + restLower;
      } else {
        return first.toUpperCase() + restLower;
      }
    })
    .join('')
}
