/*
 * Сложное условие
 * Внимания заслуживает поиск количества слов в строке
 */

package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    var saveText : String = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText.setText("")
        stats_view.setText("0")
        unsaved_changes_view.setText("All changes saved")

        editText.addTextChangedListener(object: TextWatcher{
            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Log.d("PASS", "before")
            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Log.d("ERROR_1", "start")

                var words : String = editText.text.toString()
                stats_view.setText((words.split("[^A-Za-zА-Яа-я0-9_]".toRegex()).filter { it != "" }.size).toString())

                if(words != saveText)
                    unsaved_changes_view.setText("Unsaved changes")
                else
                    unsaved_changes_view.setText("All changes saved")
            }

            override fun afterTextChanged(p0: Editable?) {
                Log.d("PASS", "after")
            }
        })

        save_button.setOnClickListener{
            saveText = editText.text.toString()
            unsaved_changes_view.setText("All changes saved")
        }

        load_button.setOnClickListener{
            editText.setText(saveText.trim())
            editText.setSelection(editText.text.toString().length)
            unsaved_changes_view.setText("All changes saved")
        }

        clear_button.setOnClickListener{
            editText.setText("")
            if( editText.text.toString() != saveText)
                unsaved_changes_view.setText("Unsaved changes")
            else
                unsaved_changes_view.setText("All changes saved")
        }
    }
}
