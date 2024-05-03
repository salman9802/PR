package com.example.slip12q1;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.os.Bundle;
import android.widget.ToggleButton;

public class MainActivity extends AppCompatActivity {
    /* Construct an Android app that toggles a light bulb ON and OFF when the user clicks on toggle button */

    ToggleButton toggleButton;
    CameraManager cameraManager;
    String cameraId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.toggleButton = (ToggleButton) findViewById(R.id.toggle_btn);

        this.cameraManager = (CameraManager) getSystemService(CAMERA_SERVICE);
        try {
            this.cameraId = this.cameraManager.getCameraIdList()[0];
        } catch (CameraAccessException e) {
            throw new RuntimeException(e);
        }

        this.toggleButton.setOnCheckedChangeListener((compoundButton, isChecked) -> {
            if(isChecked) {
                try {
                    this.cameraManager.setTorchMode(this.cameraId, true);
                } catch (CameraAccessException e) {
                    throw new RuntimeException(e);
                }
            }
            else {
                try {
                    this.cameraManager.setTorchMode(this.cameraId, false);
                } catch (CameraAccessException e) {
                    throw new RuntimeException(e);
                }
            }
        });

    }
}