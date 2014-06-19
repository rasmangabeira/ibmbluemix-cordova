# com.ibm.mobile.services.cordova.core

Provides access to the IBMBluemix

## Automatic Installation

    cordova plugin add com.ibm.mobile.services.cordova.core

## Manual Installation

### Manual Installation for Worklight 6.2 projects on Android

1) Copy the `IBMBluemixHybrid.js` file to your Worklight app project's `common/js` folder.  Then rebuild the Worklight Environment and the file will be copied to the correct Android app location.

2) Reference `IBMBluemixHybrid.js` in your main `index.html` file after the `worklight/cordova.js` script tag.

```html
<script type="text/javascript" src="js/IBMBluemixHybrid.js"></script>
```

3) Copy `src/android/ibmbluemix.jar` and `src/android/ibmbluemix-cordova-plugin.jar` to your projects `libs` folder.

4) Modify the `AndroidManifest.xml` file in your project to include the following permissions to the `manifest` tag:

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
```

5) Modify the `Resources/config.xml` file in your project, to add a plugin reference to the `widget` tag:

```xml
<feature name="IBMBluemix">
    <param name="android-package" value="com.ibm.mobile.services.cordova.core.CDVIBMBluemix" />
</feature>
```

### Manual Installation for Worklight 6.2 projects on iOS

1) Copy the `IBMBluemixHybrid.js` file to your Worklight app project's `common/js` folder.  Then rebuild the Worklight Environment and the file will be copied to the correct iOS app location.

2) Reference `IBMBluemixHybrid.js` in your main `index.html` file after the `worklight/cordova.js` script tag.

```html
<script type="text/javascript" src="js/IBMBluemixHybrid.js"></script>
```

3) Copy `IBMBluemix.framework` framework to your `Frameworks` folder.
Note: Select `Copy items into destination group's folder` from XCode

4) Copy the the following files to your `Classes` folder:
Note: Select `Copy items into destination group's folder` from XCode

```
CDVIBMBluemix.h
CDVIBMBluemix.m
```

5) Modify the `Resources/config.xml` file in your project, to add a plugin reference to the `widget` tag:

```xml
<feature name="IBMBluemix">
    <param name="ios-package" value="CDVIBMBluemix" />
</feature>
```

## IBMBluemix API
IBMBluemix provides access to the following methods.

- IBMBluemix.initializeSDK
- IBMBluemix.getApplicationId

For more information, see the [API Reference](https://mobile.ng.bluemix.net/mbaas-api/docs/JavaScript/index.html)

## Getting Started Guide

For quick usage information, see the [Getting Started Guide](https://mbaas-gettingstarted.stage1.ng.bluemix.net/hybrid)

## Supported Platforms

- Android
- iOS
