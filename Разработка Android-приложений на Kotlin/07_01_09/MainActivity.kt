/*
 * Разрешения
 */

package com.example.company.myapplication

import android.Manifest
import android.app.DownloadManager
import android.content.pm.PackageManager.PERMISSION_DENIED
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        ActivityCompat.requestPermissions(this, arrayOf(android.Manifest.permission.CAMERA), 1)

        var status = ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA)
        if(status == PERMISSION_DENIED)
        {
            Log.d("PASS", "not")

        }
        else
        {
            Log.d("PASS", "was")
        }
    }
}
