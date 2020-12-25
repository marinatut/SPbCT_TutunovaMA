#pragma once
#include "MathLibrary.h"
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include <Windows.h>



namespace EducationalPractice {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			DateTime datetime = DateTime::Now;
			this->label2->Text = datetime.ToString();//вывод времени в форме

			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(215, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тутунова Марина, 590 группа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Дата";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(59, 490);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(312, 34);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Отсортировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(32, 113);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(358, 120);
			this->textBox1->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(59, 441);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(312, 31);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Вывод на экран";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(167, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"первый файл";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(35, 258);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(354, 160);
			this->textBox2->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(167, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"второй файл";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 557);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ Filename = "text.txt";
	StreamReader^ file = File::OpenText(Filename);
	textBox1->Text = file->ReadToEnd(); //вывод содержимого файла на экран
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	char values[100];//масив для хранения букв из файла
	std::vector<char> v1;//объявление векторов
	std::vector<char> v2;
	std::vector<char> v3;
	std::vector<char> v4;
	std::vector<char> v5;
	std::vector<char> v6;
	std::vector<char> v7;
	std::vector<char> v8;
	std::vector<char> v9;
	std::vector<char> v10;
	ofstream filestream("sorted.txt");//удаление содержимого файла
	filestream.close();
	ifstream f;
	f.open("text.txt");
	for (int i = 0; i < 10; i++)
	{
		f >> values[i];
		v1.push_back(values[i]);//запись 10 букв в первый вектор
	}
	sort(v1.begin(), v1.end());//сортировка вектора
	if (v1[9] == 'o')//замена o на *
		v1[9] = '*';
	writeTo(v1);//запись вектора в файл
	for (int i = 10; i < 20; i++)
	{
		f >> values[i];
		v2.push_back(values[i]);
	}
	sort(v2.begin(), v2.end());
	if (v2[8] == 'o')
		v2[8] = '*';
	writeTo(v2);
	for (int i = 20; i < 30; i++)
	{
		f >> values[i];
		v3.push_back(values[i]);
	}
	sort(v3.begin(), v3.end());
	if (v3[7] == 'o')
		v3[7] = '*';
	writeTo(v3);
	for (int i = 30; i < 40; i++)
	{
		f >> values[i];
		v4.push_back(values[i]);
	}
	sort(v4.begin(), v4.end());
	if (v4[6] == 'o')
		v4[6] = '*';
	writeTo(v4);
	for (int i = 40; i < 50; i++)
	{
		f >> values[i];
		v5.push_back(values[i]);
	}
	sort(v5.begin(), v5.end());
	if (v5[5] == 'o')
		v5[5] = '*';
	writeTo(v5);
	for (int i = 50; i < 60; i++)
	{
		f >> values[i];
		v6.push_back(values[i]);
	}
	sort(v6.begin(), v6.end());
	if (v6[4] == 'o')
		v6[4] = '*';
	writeTo(v6);
	for (int i = 60; i < 70; i++)
	{
		f >> values[i];
		v7.push_back(values[i]);
	}
	sort(v7.begin(), v7.end());
	if (v7[3] == 'o')
		v7[3] = '*';
	writeTo(v7);
	for (int i = 70; i < 80; i++)
	{
		f >> values[i];
		v8.push_back(values[i]);
	}
	sort(v8.begin(), v8.end());
	if (v8[2] == 'o')
		v8[2] = '*';
	writeTo(v8);
	for (int i = 80; i < 90; i++)
	{
		f >> values[i];
		v9.push_back(values[i]);
	}
	sort(v9.begin(), v9.end());
	if (v9[1] == 'o')
		v9[1] = '*';
	writeTo(v9);
	for (int i = 90; i < 100; i++)
	{
		f >> values[i];
		v10.push_back(values[i]);
	}
	sort(v10.begin(), v10.end());
	if (v10[0] == 'o')
		v10[0] = '*';
	writeTo(v10);
	f.close();
	String^ Filename = "sorted.txt";
	StreamReader^ file = File::OpenText(Filename); 
	textBox2->Text = file->ReadToEnd(); //вывод содержимого файла на экран
}
};
}
