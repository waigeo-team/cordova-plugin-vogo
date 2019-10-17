/*global cordova, module*/


var failure = function(e) {
	console.log("VOGO plugin error: ");
  	console.log(e);
};

var success = function() {
  	console.log("VOGO plugin ok (silent)");
};

module.exports = {
	launchPlayer: function (options) {
    	cordova.exec(success, failure, "VogoPlugin", "launchPlayer", [options]);
  	}
};
