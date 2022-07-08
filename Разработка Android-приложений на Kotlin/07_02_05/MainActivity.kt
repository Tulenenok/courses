/*
 * Читаем содержимое файла по введенному пути
 */

package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.support.v4.app.ActivityCompat
import android.support.v4.content.ContextCompat
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import java.io.File


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        

        result.setText("")
        filepath.setText("")

        perform.setOnClickListener{
            try
            {
                var path = Environment.getExternalStorageDirectory()
                val fileRead = File(path, filepath.text.toString())
                result.setText(fileRead.readText())
            }
            catch (e: Throwable)
            {
                Log.d("PASS", "ERROR")
            }
        }
      }
}
