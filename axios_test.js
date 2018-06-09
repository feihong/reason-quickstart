const axios = require('axios')
const fs = require('fs')

function getAccessToken() {
    let text = fs.readFileSync('secrets.json')
    return JSON.parse(text)['eventbrite_access_token']
}

let params = {
    "token": getAccessToken(),
    "location.address": "2100 S Wentworth Ave, Chicago, IL 60616",
    "location.within": "1mi",
    "sort_by": "date"
}
axios.get("https://www.eventbriteapi.com/v3/events/search/", {params})
    .then(res => {
        console.log('Status:', res.status)
        for (let evt of res.data.events) {
            console.log(evt.name.text, evt.start.local.substring(0, 10))
        }
        let text = JSON.stringify(res.data, null, 2)
        fs.writeFileSync('results.json', text)
    })
    .catch(err => {
        console.log(err)
    })