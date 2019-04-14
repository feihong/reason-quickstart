const fs = require('fs')
const pathlib = require('path')
const glob = require('glob')
const childProcess = require('child_process')

const examplesDir = './src/'

fs.watch(examplesDir, { recursive: true }, (eventType, filename) => {
  if (filename.endsWith('.bs.js')) {
    console.log(`${filename} changed, running...\n`)
    childProcess.spawn(
      'node',
      [pathlib.join('./src', filename)],
      { stdio: 'inherit' })
  }
})
