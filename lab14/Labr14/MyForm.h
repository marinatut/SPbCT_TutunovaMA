#pragma once
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public class I_CHO                                         //????????? I_CHO
	{
	public:
		virtual double rasschet() = 0;
	};

	public class Reservoir : I_CHO {							//??????? ????? ?????????
	public:
		char tip;
		double cost;
		double V;

	};

	class Butt :public Reservoir {							//????? ?????, ?????????????? ?? ?????? ?????????
	public:
		int uroven = 0;
		double H = 0;
		double R = 0;
		double rasschet() {
			return M_PI * pow(R, 2) * H;

		}
		double obem_zhid_kosti(double V) {
			return V / 100 * uroven;
		}
	};
	class Canister : public Reservoir {						
		int uroven = 0;
		double W = 0;
		double H = 0;
		double L = 0;
		double rasschet() {
			return W * H * L;
		}
		double obem_zhid_kosti(double V) {
			return V / 100 * uroven;
		}
	};

	class Warehouse {									
	public:
		int length = 10;
		Canister* array = new Canister[length];
		Butt* array1 = new Butt[length];
		Warehouse() {
			for (int i = 0; i < length; i++) {
				array[i].W = 2;
				array[i].H = 7;
				array[i].L = 5;
				array[i].uroven = rand() % 101;
				if (i % 2 == 0) {
					array[i].tip = 'k';
				}
				else {
					array[i].tip = 'b';
				}
				array1[i].H = 10;
				array1[i].R = 10;
				array1[i].uroven = rand() % 101;
				if (i % 2 == 0) {
					array1[i].tip = 'k';
				}
				else {
					array1[i].tip = 'b';
				}
			}
		};
	};
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

	protected:


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			this->button1->Location = System::Drawing::Point(106, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"?????????";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click)
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"????? ????????? ??????????? ?? ?????? ???????:";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(483, 78);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double length = 10;
		long double sum = 0;
		double cost1 = 0;
		double cost2 = 0;
		Warehouse warehouse;
		for (int i = 0; i < length; i++) {
			if (warehouse.array[i].tip == 'k') {
				warehouse.array[i].cost = 100;
			}
			else if (warehouse.array[i].tip == 'b') {
				warehouse.array[i].cost = 200;
			}
			if (warehouse.array1[i].tip == 'k') {
				warehouse.array1[i].cost = 100;
			}
			else if (warehouse.array1[i].tip == 'b') {
				warehouse.array1[i].cost = 200;
			}
			double V1 = warehouse.array[i].rasschet();
			double V2 = warehouse.array1[i].rasschet();
			cost1 = warehouse.array[i].obem_zhid_kosti(V1) * warehouse.array[i].cost;
			cost2 = warehouse.array1[i].obem_zhid_kosti(V2) * warehouse.array1[i].cost;
			sum += cost1;
			sum += cost2;
			cost1 = 0;
			cost2 = 0;
		};
		sum = lround(sum);
		label1->Text += sum + " руб.";
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		srand(time(0));
	}
	};
}