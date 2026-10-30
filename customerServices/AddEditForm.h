#pragma once
#include "customerAccounts.h"

using namespace System;
using namespace System::Windows::Forms;

namespace customerServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddEditForm
	/// </summary>
	public ref class AddEditForm : public System::Windows::Forms::Form
	{
	public:
		AddEditForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Text = "Add New Customer";
			isAddMode = true;
			currentCustomer = nullptr;
		}

		// NEW: Constructor for Update mode
		AddEditForm(customerAccounts^ customerToEdit)
		{
			InitializeComponent();
			this->Text = "Update Customer";
			isAddMode = false;
			currentCustomer = customerToEdit;

			// Populate fields with existing data
			PopulateFields();
		}

		// Properties to get values from form
		property int AccountNo {
			int get() { return Convert::ToInt32(txtAccountNo->Text); }
		}

		property String^ CustomerName {
			String^ get() { return txtCustomerName->Text; }
		}

		property String^ Address {
			String^ get() { return txtAddress->Text; }
		}

		property String^ Suburb {
			String^ get() { return txtSuburb->Text; }
		}

		property String^ PropertyType {
			String^ get() { return txtPropertyType->Text; }
		}

		property int PreviousUsage {
			int get() { return Convert::ToInt32(txtPreviousUsage->Text); }
		}

		property int CurrentUsage {
			int get() { return Convert::ToInt32(txtCurrentUsage->Text); }
		}

		property String^ RefuseBin {
			String^ get() { return txtRefuseBin->Text; }
		}

	private:
		void PopulateFields()
		{
			if (currentCustomer != nullptr)
			{
				txtAccountNo->Text = currentCustomer->getAccountNo().ToString();
				txtCustomerName->Text = currentCustomer->getCustomerName();
				txtAddress->Text = currentCustomer->getAddress();
				txtSuburb->Text = currentCustomer->getSuburb();
				txtPropertyType->Text = currentCustomer->getPropertyType();
				txtPreviousUsage->Text = currentCustomer->getPreviousUsage().ToString();
				txtCurrentUsage->Text = currentCustomer->getCurrentUsage().ToString();
				txtRefuseBin->Text = currentCustomer->getRefuseBin();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Label9;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^ txtAccountNo;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCustomerName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtAddress;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtSuburb;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtPropertyType;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtPreviousUsage;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtCurrentUsage;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtRefuseBin;


	private: System::Windows::Forms::Button^ btnclear;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnSave;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool isAddMode;
		customerAccounts^ currentCustomer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddEditForm::typeid));
			this->Label9 = (gcnew System::Windows::Forms::Label());
			this->txtAccountNo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCustomerName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtSuburb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPropertyType = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtPreviousUsage = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtCurrentUsage = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtRefuseBin = (gcnew System::Windows::Forms::TextBox());
			this->btnclear = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Label9
			// 
			this->Label9->AutoSize = true;
			this->Label9->Location = System::Drawing::Point(28, 32);
			this->Label9->Name = L"Label9";
			this->Label9->Size = System::Drawing::Size(73, 16);
			this->Label9->TabIndex = 52;
			this->Label9->Text = L"AccountNo";
			// 
			// txtAccountNo
			// 
			this->txtAccountNo->Location = System::Drawing::Point(256, 32);
			this->txtAccountNo->Name = L"txtAccountNo";
			this->txtAccountNo->Size = System::Drawing::Size(154, 22);
			this->txtAccountNo->TabIndex = 51;
			this->txtAccountNo->Tag = L"";
			this->txtAccountNo->Text = L" ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 16);
			this->label2->TabIndex = 54;
			this->label2->Text = L"CustomerName";
			// 
			// txtCustomerName
			// 
			this->txtCustomerName->Location = System::Drawing::Point(256, 97);
			this->txtCustomerName->Name = L"txtCustomerName";
			this->txtCustomerName->Size = System::Drawing::Size(154, 22);
			this->txtCustomerName->TabIndex = 53;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 16);
			this->label1->TabIndex = 56;
			this->label1->Text = L"Address";
			// 
			// txtAddress
			// 
			this->txtAddress->Location = System::Drawing::Point(256, 164);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(154, 22);
			this->txtAddress->TabIndex = 55;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 235);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 16);
			this->label3->TabIndex = 58;
			this->label3->Text = L"Suburb";
			// 
			// txtSuburb
			// 
			this->txtSuburb->Location = System::Drawing::Point(256, 238);
			this->txtSuburb->Name = L"txtSuburb";
			this->txtSuburb->Size = System::Drawing::Size(154, 22);
			this->txtSuburb->TabIndex = 57;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 309);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 16);
			this->label4->TabIndex = 60;
			this->label4->Text = L"PropertyType";
			// 
			// txtPropertyType
			// 
			this->txtPropertyType->Location = System::Drawing::Point(256, 312);
			this->txtPropertyType->Name = L"txtPropertyType";
			this->txtPropertyType->Size = System::Drawing::Size(154, 22);
			this->txtPropertyType->TabIndex = 59;
			this->txtPropertyType->TextChanged += gcnew System::EventHandler(this, &AddEditForm::txtPropertyType_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 388);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 16);
			this->label5->TabIndex = 62;
			this->label5->Text = L"PreviousUsage";
			// 
			// txtPreviousUsage
			// 
			this->txtPreviousUsage->Location = System::Drawing::Point(256, 391);
			this->txtPreviousUsage->Name = L"txtPreviousUsage";
			this->txtPreviousUsage->Size = System::Drawing::Size(157, 22);
			this->txtPreviousUsage->TabIndex = 61;
			this->txtPreviousUsage->TextChanged += gcnew System::EventHandler(this, &AddEditForm::txtPreviousUsage_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 459);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 16);
			this->label6->TabIndex = 64;
			this->label6->Text = L"CurrentUsage";
			// 
			// txtCurrentUsage
			// 
			this->txtCurrentUsage->Location = System::Drawing::Point(256, 462);
			this->txtCurrentUsage->Name = L"txtCurrentUsage";
			this->txtCurrentUsage->Size = System::Drawing::Size(154, 22);
			this->txtCurrentUsage->TabIndex = 63;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(28, 534);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 16);
			this->label7->TabIndex = 66;
			this->label7->Text = L"RefuseBin";
			// 
			// txtRefuseBin
			// 
			this->txtRefuseBin->Location = System::Drawing::Point(256, 537);
			this->txtRefuseBin->Name = L"txtRefuseBin";
			this->txtRefuseBin->Size = System::Drawing::Size(154, 22);
			this->txtRefuseBin->TabIndex = 65;
			// 
			// btnclear
			// 
			this->btnclear->Location = System::Drawing::Point(154, 591);
			this->btnclear->Name = L"btnclear";
			this->btnclear->Size = System::Drawing::Size(99, 48);
			this->btnclear->TabIndex = 68;
			this->btnclear->Text = L"Clear";
			this->btnclear->UseVisualStyleBackColor = true;
			this->btnclear->Click += gcnew System::EventHandler(this, &AddEditForm::button2_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(296, 591);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(114, 48);
			this->btnUpdate->TabIndex = 69;
			this->btnUpdate->Text = L"UpDate";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &AddEditForm::btnUpdate_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(30, 592);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(99, 47);
			this->btnSave->TabIndex = 70;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddEditForm::btnSave_Click);
			// 
			// AddEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(498, 722);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnclear);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txtRefuseBin);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtCurrentUsage);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtPreviousUsage);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtPropertyType);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtSuburb);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtAddress);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtCustomerName);
			this->Controls->Add(this->Label9);
			this->Controls->Add(this->txtAccountNo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddEditForm";
			this->Text = L"AddEditForm";
			this->Load += gcnew System::EventHandler(this, &AddEditForm::AddEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtPropertyType_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void txtPreviousUsage_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	txtAccountNo->Clear();
	txtCustomerName->Clear();
	txtAddress->Clear();
	txtSuburb->Clear();
	txtPropertyType->Clear();
	txtPreviousUsage->Clear();
	txtCurrentUsage->Clear();
	txtRefuseBin->Clear();
}
private: System::Void AddEditForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Basic validation
	if (String::IsNullOrWhiteSpace(txtAccountNo->Text) ||
		String::IsNullOrWhiteSpace(txtCustomerName->Text))
	{
		MessageBox::Show("Please fill in Account No and Customer Name.");
		return;
	}

	// Validate numeric fields
	int accountNo, prevUsage, currUsage;
	if (!Int32::TryParse(txtAccountNo->Text, accountNo))
	{
		MessageBox::Show("Account No must be a valid number.");
		return;
	}

	if (!Int32::TryParse(txtPreviousUsage->Text, prevUsage))
	{
		MessageBox::Show("Previous Usage must be a valid number.");
		return;
	}

	if (!Int32::TryParse(txtCurrentUsage->Text, currUsage))
	{
		MessageBox::Show("Current Usage must be a valid number.");
		return;
	}

	// Set DialogResult to OK to indicate successful save
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Call the same save logic
	btnSave_Click(sender, e);
}
};
}
