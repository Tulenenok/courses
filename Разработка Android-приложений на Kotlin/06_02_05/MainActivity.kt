/*
 *  При нажатии на элемент его копия добавляется в конец списка
 */

package com.example.company.myapplication


import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.widget.ArrayAdapter
import android.widget.ListAdapter
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var dataArray : MutableList<String> = mutableListOf()
        for(i in 0..10)
            dataArray.add((i * i).toString())

        var adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, dataArray)

        listView.adapter = adapter

        listView.setOnItemClickListener{ parent, view, position, id ->
            adapter.add((view as TextView).text.toString())
        }
    }
}
