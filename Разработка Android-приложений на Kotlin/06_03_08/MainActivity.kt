/*
 * В спинере столько элементов, сколько ввел пользователь в editText
 */

package com.example.company.myapplication

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import android.widget.ArrayAdapter
import android.widget.Spinner
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText.setText("")

        var dataArray : MutableList<String> = mutableListOf()

        var adapter = ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, dataArray)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        spinner.adapter = adapter


        editText.addTextChangedListener(object: TextWatcher{
            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Log.d("PASS", "before")
            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                dataArray.clear()
                try
                {
                    var x: Int = editText.text.toString().toInt()
                    if (x <= 0) throw Throwable()

                    for(i in 1..x)
                        dataArray.add(i.toString())

                    adapter.notifyDataSetChanged()
                }
                catch (e: Throwable)
                {
                    adapter.notifyDataSetChanged()
                }
            }

            override fun afterTextChanged(p0: Editable?) {
                Log.d("PASS", "after")
            }

        })
    }
}
