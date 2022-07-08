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

        var dataArray = Array<String>(31, {it -> it.toString()})
        var adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, dataArray)
        gridView.adapter = adapter

        gridView.numColumns = 4
    }
}
