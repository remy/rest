'use strict';
// var fetchedVersion = 0;
/*
function fetchVersion() {
  if (fetchedVersion === 0) {
    var response;
    var req = new XMLHttpRequest();
    req.open('GET', 'http://edwinfinch.github.io/simplyclean', false);
    console.log('Getting latest watchapp and javascript version from: http://edwinfinch.github.io/simplyclean');
    req.onload = function(e) {
      if (req.readyState == 4) {
        if(req.status == 200) {
          response = JSON.parse(req.responseText);
          var watchAppVersion;
          if (response > 0) {
        watchAppVersion = response;
        console.log('Latest watchapp version: ' + watchAppVersion + '. Sending to pebble...');
            Pebble.sendAppMessage({
              'wfupdate':parseInt(watchAppVersion),
        });
        fetchedVersion = 1;
          }
      else{
        console.log('Version API error: No existing value in response');
      }
        } else {
        console.log('Error: could not connect');
        }
      }
    };
    req.send(null);
  }
}

*/

/*global Pebble*/

var values = null;

Pebble.addEventListener('ready', function (e) {
  console.log('connect: ' + e.ready);
  console.log(e.type);
});

Pebble.addEventListener('showConfiguration', function () {
  Pebble.openURL('http://remy.github.io/rest/config.html');
});

Pebble.addEventListener('webviewclosed', function (e) {
  // console.log('Configuration closed');
  // console.log('Response = ' + e.response.length + '   ' + e.response);
  if (e.response) { // user clicked Save/Submit, not Cancel/Done
    // console.log('User hit save');
    values = JSON.parse(decodeURIComponent(e.response));
    // console.log('stringified options: ' + JSON.stringify((values)));

    Pebble.sendAppMessage(values);
    // Pebble.sendAppMessage(values, function () {
    //   // console.log('Successfully sent options to Pebble');
    // }, function (e) {
    //   // console.log('Failed to send options to Pebble.\nError: ' + e.error.message);
    // });
  }
});