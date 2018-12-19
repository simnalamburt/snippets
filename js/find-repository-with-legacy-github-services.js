'use strict'

const process = require('process')
const octokit = require('@octokit/rest')()

console.log('repository,service')
;(async _ => {
  octokit.authenticate({
    type: 'basic',
    username: 'YOUR_GITHUB_USERNAME_HERE',
    password: 'YOUR_GITHUB_PERSONAL_ACCESS_TOKEN_HERE',
  })

  const opt = octokit.repos.listForOrg.endpoint.merge({ org: 'devsisters' })
  for await (const res of octokit.paginate.iterator(opt)) {
    if (res.status !== 200) {
      process.exit(-1)
    }

    for (const repository of res.data) {
      const opt = octokit.repos.listHooks.endpoint.merge({
        owner: repository.owner.login,
        repo: repository.name,
      })
      for await (const res of octokit.paginate.iterator(opt)) {
        if (res.status !== 200) {
          process.exit(-1)
        }

        for (const hook of res.data) {
          if (hook.name === 'web') { continue }

          console.log(`${repository.name},${hook.name}`)
        }
      }
    }
  }
})()
