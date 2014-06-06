var cordova = require('cordova'),
    exec = require('cordova/exec');

var IBMBaaS = {
		initializeSDK : function(applicationID, successCallback, failureCallback) {
	    	 exec(successCallback, failureCallback, "IBMBaaS", "initializeSDK", [applicationID]);
	    }

};
module.exports = IBMBaaS;