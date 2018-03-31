// TASK 뽑아내기
document.querySelectorAll('.ex_link').forEach(e => e.textContent = e.href)
document.querySelectorAll('span.text.sel_item_content br').forEach(e => e.textContent = '\n')
copy(JSON.stringify([...document.querySelectorAll('span.text.sel_item_content')].map(e => e.textContent)))

// 복사한거 MS TODO로 옮기기
// Thanks @disjukr
;(async _ => {
  const data = ["task1", "task2", "task3"]
  const ParentFolderId = '<redacted>'
  const XTodoRequestId = '<redacted>'
  const authorization = '<redacted>'
  const sleep_ms = ms => new Promise(res => setTimeout(res, ms))

  const headers = new Headers({
    'Content-Type': 'application/json',
    'x-anchormailbox': 'CID:<redacted>',
    'x-todo-request-id': XTodoRequestId,
    authorization
  })
  const url = `https://substrate.office.com/todo/api/v1/taskfolders/${ParentFolderId}/tasks`
  const startTime = new Date()

  for (const [i, Subject] of Array.from(data).reverse().entries()) {
    const OrderDateTime = (new Date(startTime.getTime() + 1000 * i)).toISOString()
    const body = JSON.stringify({ OrderDateTime, ParentFolderId, Subject })

    fetch(url, { method: 'POST', body, headers })
    .then(r => r.json())
    .then(r => console.log(r))
    .catch(e => console.error(e))

    await sleep_ms(50)
  }
})()

// Todoist에 있는 TASK들 전부 완료처리하기
document.querySelectorAll('.ist_checkbox').forEach(e => e.click())
