// printf '"abcde\\nabcde\\tabcde"' | node unescape.js

const chunks = []

process.stdin.on('data', chunk => chunks.push(chunk))
process.stdin.on('end', _ => {
  const input = Buffer.concat(chunks).toString()

  if (input[0] !== '"' || input[input.length - 1] !== '"') {
    // Abort
    process.stderr.write("wrong input\n")
    process.exit(1)
  }

  process.stdout.write(
    input
    // 맨 처음과 맨 뒤의 쌍따옴표 삭제
    .substr(1, input.length - 2)
    // Unescape
    .replace(/\\(.|$)/g, (_, seq) => {
      switch (seq) {
        case `0`: return `\0`
        case `'`: return `\'`
        case `"`: return `\"`
        case `\\`: return `\\`
        case `n`: return `\n`
        case `r`: return `\r`
        case `v`: return `\v`
        case `t`: return `\t`
        case `b`: return `\b`
        case `f`: return `\f`
          // TODO: \uXXXX \u{X} \u{XXXXXX} \xXX
      }
    }) + '\n'
  )
})
