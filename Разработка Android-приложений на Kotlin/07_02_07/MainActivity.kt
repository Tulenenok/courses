/*
 * Получить от пользователя путь и определить по нему количество файлов в директории
 */

package com.example.company.myapplication

import android.content.Context
import android.os.Bundle
import android.os.Environment
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import java.io.File


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        path.setText("")
        result.setText("")
        perform.setOnClickListener{
            try
            {
                var p = path.text.toString()
                result.setText(File(p).listFiles().filter { it.isFile }.size.toString())
            }
            catch (e: Throwable)
            {
                result.setText("Error")
            }
        }
    }
}
