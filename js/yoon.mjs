const response = await fetch('https://open.assembly.go.kr/portal/data/sheet/downloadSheetData.do?rows=1&infId=O0JYV9001256KD10538&infSeq=1&downloadType=J&PETIT_SJ=탄핵소추안')
// TODO: handle errors
const json = await response.json()

console.log(json)
console.log(json[1].AGRE_CO)
