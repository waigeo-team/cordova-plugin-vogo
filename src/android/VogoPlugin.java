package com.vogo.sdk;


import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;

import android.app.Activity;
import android.content.Intent;
import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONException;

import android.util.Log;

import com.vogo.playerlib.MainPlayer;
import com.vogo.playerlib.Params;

public class VogoPlugin extends CordovaPlugin {

    private static final String TAG = "VogoPlugin";

    @Override
    public void initialize(final CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);

        Log.i(TAG," -- Init VOGO Sport sdk --");
    }

    @Override
    public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {

        Log.i(TAG, "Action Name: " + action);

        if (action.equals("launchPlayer")){

            Activity activity = this.cordova.getActivity();
            if(activity != null)
            {
                Intent vogoIntent = new Intent(activity, MainPlayer.class);
                JSONObject options = (args != null ? args.getJSONObject(0) : null);
                if(options != null) setupIntent(vogoIntent, options);
                activity.startActivity(vogoIntent);
            }

            return true;
        }


        return false;
    }

    private void setupIntent(Intent vogoIntent, final JSONObject options)
    {
        if(options != null && vogoIntent != null)
        {
            if(options.has("DEFAULT_TEXT"))        vogoIntent.putExtra(Params.DEFAULT_TEXT, JsonGetString(options, "DEFAULT_TEXT"));
            if(options.has("DEFAULT_TEXT_HIDDEN")) vogoIntent.putExtra(Params.DEFAULT_TEXT_HIDDEN, JsonGetBoolean(options, "DEFAULT_TEXT_HIDDEN"));
            if(options.has("CONNECTING_TEXT"))     vogoIntent.putExtra(Params.CONNECTING_TEXT, JsonGetString(options, "CONNECTING_TEXT"));
            if(options.has("QUIT_TEXT"))           vogoIntent.putExtra(Params.QUIT_TEXT, JsonGetString(options, "QUIT_TEXT"));
            if(options.has("DIALOG_ICON"))         vogoIntent.putExtra(Params.DIALOG_ICON, JsonGetString(options, "DIALOG_ICON"));
            if(options.has("BACKGROUND"))          vogoIntent.putExtra(Params.BACKGROUND, JsonGetString(options, "BACKGROUND"));
            if(options.has("SPONSOR1"))            vogoIntent.putExtra(Params.SPONSOR1, JsonGetString(options, "SPONSOR1"));
            if(options.has("SPONSOR2"))            vogoIntent.putExtra(Params.SPONSOR2, JsonGetString(options, "SPONSOR2"));
            if(options.has("SPONSOR3"))            vogoIntent.putExtra(Params.SPONSOR3, JsonGetString(options, "SPONSOR3"));
            if(options.has("SPONSOR4"))            vogoIntent.putExtra(Params.SPONSOR4, JsonGetString(options, "SPONSOR4"));
            if(options.has("SPONSOR5"))            vogoIntent.putExtra(Params.SPONSOR5, JsonGetString(options, "SPONSOR5"));
            if(options.has("MAIN_LOGO"))           vogoIntent.putExtra(Params.MAIN_LOGO, JsonGetString(options, "MAIN_LOGO"));
            if(options.has("PRIMARY_COLOR"))       vogoIntent.putExtra(Params.PRIMARY_COLOR, rgbHexStringToInt(JsonGetString(options, "PRIMARY_COLOR")));
            if(options.has("BACKGROUND_NOTIFICATION_ICON"))       vogoIntent.putExtra(Params.BACKGROUND_NOTIFICATION_ICON, JsonGetString(options, "BACKGROUND_NOTIFICATION_ICON"));
            if(options.has("BACKGROUND_NOTIFICATION_MESSAGE"))    vogoIntent.putExtra(Params.BACKGROUND_NOTIFICATION_MESSAGE, JsonGetString(options, "BACKGROUND_NOTIFICATION_MESSAGE"));
            if(options.has("BACKGROUND_NOTIFICATION_ICON_LARGE")) vogoIntent.putExtra(Params.BACKGROUND_NOTIFICATION_ICON_LARGE, JsonGetString(options, "BACKGROUND_NOTIFICATION_ICON_LARGE"));
            if(options.has("PLAYER_TITLE"))           vogoIntent.putExtra(Params.PLAYER_TITLE, JsonGetString(options, "PLAYER_TITLE"));
            if(options.has("HIDE_CGU"))               vogoIntent.putExtra(Params.HIDE_CGU, JsonGetBoolean(options, "HIDE_CGU"));
            if(options.has("VOGO_EVENTS_PROJECT_ID")) vogoIntent.putExtra(Params.VOGO_EVENTS_PROJECT_ID, JsonGetInt(options, "VOGO_EVENTS_PROJECT_ID"));
            if(options.has("WITH_BACKGROUND_AUDIO"))  vogoIntent.putExtra(Params.WITH_BACKGROUND_AUDIO, JsonGetBoolean(options, "WITH_BACKGROUND_AUDIO"));
            if(options.has("JSON_LISTENING_IP"))      vogoIntent.putExtra(Params.JSON_LISTENING_IP, JsonGetString(options, "JSON_LISTENING_IP"));
        }
    }

    private int rgbHexStringToInt(String hexNumber)
    {
        int R = 0;
        int G = 0;
        int B = 0;

        if(hexNumber.length() == 7 && hexNumber.charAt(0) == '#')
        {
            R = Integer.parseInt(hexNumber.substring(1, 3), 16);
            G = Integer.parseInt(hexNumber.substring(3, 5), 16);
            B = Integer.parseInt(hexNumber.substring(5, 7), 16);
        }

        return (0xff) << 24 | (R & 0xff) << 16 | (G & 0xff) << 8 | (B & 0xff);
    }

    private String JsonGetString(JSONObject jsonObject, String key)
    {
        try {
            return jsonObject.getString(key);
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }

    private boolean JsonGetBoolean(JSONObject jsonObject, String key)
    {
        try {
            return jsonObject.getBoolean(key);
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }

    private int JsonGetInt(JSONObject jsonObject, String key)
    {
        try {
            return jsonObject.getInt(key);
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }
}
