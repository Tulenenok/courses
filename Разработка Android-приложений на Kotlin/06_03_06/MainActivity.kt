/*
 * GridView по нажатию поменять текст на (i, j)
 */

package com.example.company.myapplication

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.widget.ArrayAdapter
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var dataArray = MutableList(31, { it -> it.toString()})
        var adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, dataArray)
        gridView.adapter = adapter

        gridView.numColumns = 4

        gridView.setOnItemClickListener{parent, view, position, id ->
            dataArray[position] = "${position / 4 + 1},${position % 4 + 1}"
            adapter.notifyDataSetChanged()
        }
    }
}
