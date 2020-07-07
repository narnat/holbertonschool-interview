#!/usr/bin/node
const request = require('request');

function send (person) {
  return new Promise(function (resolve, reject) {
    request(person, function (error, response, body) {
      if (error || response.code >= 400) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`,
  async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const people = JSON.parse(body).characters;
      for (let i = 0; i < people.length; ++i) {
          const name = await send(people[i]);
          console.log(name);
      }
    }
  });
