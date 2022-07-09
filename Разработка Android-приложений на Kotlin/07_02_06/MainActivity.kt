/*
 * Поменять содержимое двух текстовых файлов местами
 */

package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.widget.EditText
import kotlinx.android.synthetic.main.activity_main.*
import java.io.BufferedWriter
import java.io.File
import java.io.FileWriter


class MainActivity : AppCompatActivity() {

    fun readTextFromFiles(file: String, txtUI: EditText): String? {
        try
        {
            var path = Environment.getExternalStorageDirectory()
            var fileRead = File(path, file)
            return fileRead.readText()
        }
        catch(e: Throwable)
        {
            txtUI.setText("error")
            return null
        }
    }

    fun writeTextFromFiles(file: String, txt: String) {
        var path = Environment.getExternalStorageDirectory()

        var fileRead = File(path, file)

        val buf = BufferedWriter(FileWriter(fileRead))
        buf.write(txt)
        buf.close()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        filepath.setText("")
        filepath2.setText("")

        perform.setOnClickListener{
            var file1: String = filepath.text.toString()
            var file2: String = filepath2.text.toString()

            var file1Text: String? = readTextFromFiles(file1, filepath)
            var file2Text: String? = readTextFromFiles(file2, filepath2)

            if (file1Text != null && file2Text != null)
            {
                writeTextFromFiles(file1, file2Text)
                writeTextFromFiles(file2, file1Text)
            }
        }
    }
}
