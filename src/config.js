var fetchedVersion = 0;
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

Pebble.addEventListener('ready', function (e) {
  console.log('connect: ' + e.ready);
  console.log(e.type);
  fetchVersion();
});
*/

var values = 0;
var config_url = 'https://remy.github.io/rest/config.html';
var options = JSON.parse(localStorage.getItem('settings'));

Pebble.addEventListener('showConfiguration', function(e) {
  if (localStorage.getItem('settings') !== null) {
    options = JSON.parse(localStorage.settings);
  }
  Pebble.openURL(config_url);
});

Pebble.addEventListener('webviewclosed', function (e) {
  console.log('Configuration closed');
  console.log('Response = ' + e.response.length + '   ' + e.response);
  if (e.response) { // user clicked Save/Submit, not Cancel/Done
    console.log('User hit save');
    values = JSON.parse(decodeURIComponent(e.response));
    console.log('stringified options: ' + JSON.stringify((values)));

    for(var key in values) {
      localStorage.setItem(key, values[key]);
    }

    // Pebble.sendAppMessage(values);
    Pebble.sendAppMessage(values, function (e) {
      console.log('Successfully sent options to Pebble');
    }, function (e) {
      console.log('Failed to send options to Pebble.\nError: ' + e.error.message);
    });
});