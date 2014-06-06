# com.ibm.baas.cordova.ibmbaas

Provides access to the IBMBaaS

## Automatic Installation

    cordova plugin add com.ibm.baas.cordova.ibmbaas

## Manual Installation

### Manual Installation for Worklight 6.2 projects on Android

1) Copy the `IBMBaaS.hybrid.js` file to your Worklight app project's `common/js` folder.  Then rebuild the Worklight Environment and the file will be copied to the correct Android app location.

2) Reference `IBMBaaS.hybrid.js` in your main `index.html` file after the `worklight/cordova.js` script tag.

```html
<script type="text/javascript" src="js/IBMBaaS.hybrid.js"></script>
```

3) Copy `src/android/ibmbaas.jar` and `src/android/ibmbaas-cordova-plugin.jar` to your projects `libs` folder.

4) Modify the `AndroidManifest.xml` file in your project to include the following permissions to the `manifest` tag:

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
```

5) Modify the `Resources/config.xml` file in your project, to add a plugin reference to the `widget` tag:

```xml
<feature name="IBMBaaS">
    <param name="android-package" value="com.ibm.baas.cordova.CDVIBMBaaS" />
</feature>
```

### Manual Installation for Worklight 6.2 projects on iOS

1) Copy the `IBMBaaS.hybrid.js` file to your Worklight app project's `common/js` folder.  Then rebuild the Worklight Environment and the file will be copied to the correct iOS app location.

2) Reference `IBMBaaS.hybrid.js` in your main `index.html` file after the `worklight/cordova.js` script tag.

```html
<script type="text/javascript" src="js/IBMBaaS.hybrid.js"></script>
```

3) Copy `IBMBaaS.framework` framework to your `Frameworks` folder.
Note: Select `Copy items into destination group's folder` from XCode

4) Copy the the following files to your `Classes` folder:
Note: Select `Copy items into destination group's folder` from XCode

```
CDVIBMBaaS.h
CDVIBMBaaS.m
```

5) Modify the `Resources/config.xml` file in your project, to add a plugin reference to the `widget` tag:

```xml
<feature name="IBMBaaS">
    <param name="ios-package" value="CDVIBMBaaS" />
</feature>
```

## IBMBaaS API
IBMBaaS provides access to the following methods.

- IBMBaaS.initializeSDK
- IBMBaaS.getApplicationId

For more information, see the [API Reference](https://mobile.ng.bluemix.net/mbaas-api/docs/JavaScript/index.html)

## Getting Started Guide

For quick usage information, see the [Getting Started Guide](https://mbaas-gettingstarted.stage1.ng.bluemix.net/hybrid)

## Supported Platforms

- Android
- iOS
