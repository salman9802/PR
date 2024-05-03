package com.example.q8;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageSwitcher;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
/* Q8. Construct image switcher using setFactory(). */

    ImageSwitcher imageSwitcher;

    private int[] images = {
            R.drawable.ic_launcher_background,
            R.mipmap.ic_launcher,
            R.drawable.ic_launcher_foreground,
            R.mipmap.ic_launcher_round
    };

    private int index = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imageSwitcher = (ImageSwitcher) findViewById(R.id.image_switcher);

        imageSwitcher.setOnClickListener(v -> {
            imageSwitcher.setImageResource(images[index]); // sets the image resource for next imageview
            index = (index + 1) % images.length;
        });

        // creates the (next) imageview
        imageSwitcher.setFactory(() -> {
            ImageView imageView = new ImageView(this);
//            imageView.setLayoutParams(new ImageSwitcher.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
            return imageView;
        });
    }
}