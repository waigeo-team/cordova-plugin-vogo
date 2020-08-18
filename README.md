# VOGO Sport
> A Cordova plugin to interact with the VOGO SDK  
> URL: http://dev.vogosport.com/

## Installing

Get the SDK for iOS and Android beforehand, then put them in their respective directory in libs/ios or libs/android.
Once done, you can type the following command in your cordova project to add the plugin :

> cordova plugin add  `path/to/plugin/folder`

*Beware that any image ressources that you may want to use must be placed in the respective ressources directory of Android (res/drawable) and iOS (Images.xcassets via XCode)*

You're all set to use the plugin !

## Usage

The VOGO plugin contains two javascripts files :
..* **vogoPlugin.js** : It contains the `launchPlayer` function, the only one you will have to use, it takes a javascript object of `key: values` to personalize your player as shown in the Android and iOS SDK. Keys that you will find in the second file...
..* **Vogo.js** : This file is only used to expose the constant to construct your option object to personnalize your player.

### Here is an exemple 
You can write in the javascript files of your project this :
```
function launchVogo() {
	var options = {
	   ... 
	   [Vogo.DEFAULT_TEXT]:"Hello, please connect to VOGO Wifi Network ...",
	   [Vogo.HIDE_CGU]:true,
	   [Vogo.PRIMARY_COLOR]:"#FF0000",
	   [Vogo.SPONSOR1]:"sponsor_logo.png"
	   ...
	 }

	 vogoPlugin.launchPlayer(options);
}
```
